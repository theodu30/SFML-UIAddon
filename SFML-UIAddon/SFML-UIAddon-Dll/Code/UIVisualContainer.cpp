#include "Headers/SFUIL/Containers/UIVisualContainer.hpp"
#include <iostream>

namespace sfui
{
	UIVisualContainer::UIVisualContainer() : UIElement()
	{
		Initialize();
	}

	UIVisualContainer::UIVisualContainer(const char* _name) : UIElement(_name)
	{
		Initialize();
	}

	UIVisualContainer::~UIVisualContainer()
	{
	}

	void UIVisualContainer::render(sf::RenderTexture& _texture)
	{
		// If display property is None, do not render
		if (m_display.type == DisplayValueTypeProperty::None)
		{
			return;
		}

		reRenderIfDirty(_texture);

		m_renderTexture.clear(m_background.color);

		// Render all child elements to the render texture
		for (const auto& child : m_children)
		{
			child->render(m_renderTexture);
		}
	}

	void UIVisualContainer::drawToTarget(sf::RenderTarget& _target)
	{
		// If display property is None, do not draw
		if (m_display.type == DisplayValueTypeProperty::None)
		{
			return;
		}

		// Call Draw on all child elements
		for (const auto& child : m_children)
		{
			child->drawToTarget(m_renderTexture);
		}

		m_renderTexture.display();

		// Get Texture of RenderTexture and make a Sprite with it
		const sf::Texture& texture = m_renderTexture.getTexture();
		sf::Sprite sprite(texture);

		// Then apply positioning and transformations
		applyPositioningAndTransformations(_target, sprite);

		_target.draw(sprite);
	}

	void UIVisualContainer::reRenderIfDirty(sf::RenderTexture& _texture)
	{
		if (!m_dirty) return;

		// Perform re-rendering logic here
		m_dirty = false;

		sf::Vector2u newSize;
		calculateNewSize(newSize, _texture.getSize(), m_parent->getConstFlexProperty());

		if (!m_renderTexture.resize(newSize))
		{
			std::cout << "UIVisualContainer::reRenderIfDirty: (" << m_name << ") Failed to resize render texture to " << newSize.x << "x" << newSize.y << std::endl;
		}
	}

	void UIVisualContainer::Initialize()
	{
		UIElement::Initialize();
		(void)m_renderTexture.resize(sf::Vector2u(1u, 1u)); // Initial size, will be resized on first render
		markDirty();
	}

	void UIVisualContainer::calculateNewSize(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex)
	{
		// Calculate final minimum and maximum sizes based on SizeProperty constraints
		sf::Vector2u minSize;
		sf::Vector2u maxSize;
		calculateFinalMinMaxSizes(minSize, maxSize, _parentSize, _parentFlex);

		// Calculate new size based on position mode
		if (UIPropUtils::isPositionAbsolute(m_position))
		{
			calculateNewSizeInAbsolute(newSize, _parentSize, _parentFlex);
		}
		else if (UIPropUtils::isPositionRelative(m_position))
		{
			calculateNewSizeInRelative(newSize, _parentSize, _parentFlex);
		}

		// Clamp new size within min and max sizes
		newSize.x = UIPropUtils::clampUnsignedInt(newSize.x, minSize.x, maxSize.x);
		newSize.y = UIPropUtils::clampUnsignedInt(newSize.y, minSize.y, maxSize.y);
	}

	void UIVisualContainer::calculateNewSizeInAbsolute(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex)
	{
		// Compute new size
		const SizeVectorProperty& sizeProp = m_size.size;

		// Width
		newSize.x = static_cast<unsigned int>(UIPropUtils::resolveValueToPixels(sizeProp.width, static_cast<float>(_parentSize.x)));

		// Height
		newSize.y = static_cast<unsigned int>(UIPropUtils::resolveValueToPixels(sizeProp.height, static_cast<float>(_parentSize.y)));

		// If height is set to Auto, calculate content size height
		if (sizeProp.height.type == SizeValueTypeProperty::Auto)
		{
			sf::Vector2u contentSize;
			calculateContentSize(contentSize);
			newSize.y = contentSize.y;
		}

		// If width is set to Auto, calculate width using position left and right
		if (sizeProp.width.type == SizeValueTypeProperty::Auto)
		{
			float left = UIPropUtils::resolveValueToPixels(m_position.left, static_cast<float>(_parentSize.x));
			float right = UIPropUtils::resolveValueToPixels(m_position.right, static_cast<float>(_parentSize.x));
			newSize.x = static_cast<unsigned int>(static_cast<float>(_parentSize.x) - left - right);
		}
	}

	void UIVisualContainer::calculateNewSizeInRelative(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex)
	{
		// For Row and ReverseRow, the height is the same as the parent, the width is determined by all siblings
		if (UIPropUtils::isFlexDirectionRowType(_parentFlex))
		{
			// Height takes full parent height
			newSize.y = _parentSize.y;

			// Width is distributed among siblings based on flex grow/shrink
			float basicValue = resolveFinalBasicWidth(*this, static_cast<float>(_parentSize.x));

			float growShrinkFactor = 0.f;

			if (m_parent)
			{
				float totalFlexGrow = 0.f;
				float totalFlexShrink = 0.f;
				float totalBasic = 0.f;
				for (const auto& sibling : m_parent->getChildren())
				{
					const FlexProperty& siblingFlex = sibling->getConstFlexProperty();
					totalFlexGrow += siblingFlex.flexGrow.value;

					float childBasic = resolveFinalBasicWidth(*sibling->as<UIVisualContainer>(), static_cast<float>(_parentSize.x));

					totalBasic += childBasic;
					totalFlexShrink += siblingFlex.flexShrink.value * childBasic;
				}

				if (static_cast<float>(_parentSize.x) > totalBasic && totalFlexGrow > 0)
				{
					growShrinkFactor = (m_flex.flexGrow.value / totalFlexGrow) * (_parentSize.x - totalBasic);
				}
				else if (static_cast<float>(_parentSize.x) < totalBasic && totalFlexShrink > 0)
				{
					growShrinkFactor = ((m_flex.flexShrink.value * basicValue) / totalFlexShrink) * (_parentSize.x - totalBasic);
				}
			}

			newSize.x = static_cast<unsigned int>(basicValue + growShrinkFactor);
		}
		// For Column and ReverseColumn, the width is the same as the parent, the height is determined by all siblings
		else if (UIPropUtils::isFlexDirectionColumnType(_parentFlex))
		{
			// Width takes full parent width
			newSize.x = _parentSize.x;

			// height is distributed among siblings based on flex grow/shrink
			float basicValue = resolveFinalBasicHeight(*this, static_cast<float>(_parentSize.y));

			float growShrinkFactor = 0.f;

			if (m_parent)
			{
				float totalFlexGrow = 0.f;
				float totalFlexShrink = 0.f;
				float totalBasic = 0.f;
				for (const auto& sibling : m_parent->getChildren())
				{
					const FlexProperty& siblingFlex = sibling->getConstFlexProperty();
					totalFlexGrow += siblingFlex.flexGrow.value;

					float childBasic = resolveFinalBasicHeight(*sibling->as<UIVisualContainer>(), static_cast<float>(_parentSize.y));


					totalBasic += childBasic;
					totalFlexShrink += siblingFlex.flexShrink.value * childBasic;
				}

				if (static_cast<float>(_parentSize.y) > totalBasic && totalFlexGrow > 0)
				{
					growShrinkFactor = (m_flex.flexGrow.value / totalFlexGrow) * (_parentSize.y - totalBasic);
				}
				else if (static_cast<float>(_parentSize.y) < totalBasic && totalFlexShrink > 0)
				{
					growShrinkFactor = ((m_flex.flexShrink.value * basicValue) / totalFlexShrink) * (_parentSize.y - totalBasic);
				}
			}

			newSize.y = static_cast<unsigned int>(basicValue + growShrinkFactor);
		}
	}

	void UIVisualContainer::calculateFinalMinMaxSizes(sf::Vector2u& minSize, sf::Vector2u& maxSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex) const
	{
		// Compute minimum size
		const MinSizeVectorProperty& minProp = m_size.minSize;

		// Width
		minSize.x = static_cast<unsigned int>(UIPropUtils::resolveValueToPixels(minProp.width, static_cast<float>(_parentSize.x)));

		// Height
		minSize.y = static_cast<unsigned int>(UIPropUtils::resolveValueToPixels(minProp.height, static_cast<float>(_parentSize.y)));

		// Compute maximum size
		const MaxSizeVectorProperty& maxProp = m_size.maxSize;

		// Width
		maxSize.x = static_cast<unsigned int>(UIPropUtils::resolveValueToPixels(maxProp.width, static_cast<float>(_parentSize.x)));

		// Height
		maxSize.y = static_cast<unsigned int>(UIPropUtils::resolveValueToPixels(maxProp.height, static_cast<float>(_parentSize.y)));
	}

	void UIVisualContainer::calculateContentSize(sf::Vector2u& contentSize) const
	{
		// Here we calculate the preffered size based on the hierarchy this element
		if (m_children.empty())
		{
			contentSize = sf::Vector2u(0u, 0u);
			return;
		}
		else
		{
			// Iterate through children and calculate content size
			for (const auto& child : m_children)
			{
				// Accumulate sizes based on children's sizes and positions
				sf::Vector2u childSize;
				child->as<UIVisualContainer>()->calculateContentSize(childSize);
				contentSize.x += childSize.x;
				contentSize.y += childSize.y;
			}
		}

	}

	float UIVisualContainer::resolveFinalBasicWidth(const UIVisualContainer& _child, const float& _parentWidth) const
	{
		float result;

		const FlexProperty& childFlex = _child.getConstFlexProperty();
		const SizeProperty& childSize = _child.getConstSizeProperty();

		result = UIPropUtils::resolveValueToPixels(childFlex.flexBasis, static_cast<float>(_parentWidth));

		if (childFlex.flexBasis.type == FlexBasicValueTypeProperty::Auto)
		{
			// If Basis is Auto, use width instead
			result = UIPropUtils::resolveValueToPixels(childSize.size.width, static_cast<float>(_parentWidth));

			if (childSize.size.width.type == SizeValueTypeProperty::Auto)
			{
				// If width is also Auto, use content size
				sf::Vector2u contentSize;
				_child.calculateContentSize(contentSize);
				result = static_cast<float>(contentSize.x);
			}
		}

		return result;
	}

	float UIVisualContainer::resolveFinalBasicHeight(const UIVisualContainer& _child, const float& _parentHeight) const
	{
		float result;

		const FlexProperty& childFlex = _child.getConstFlexProperty();
		const SizeProperty& childSize = _child.getConstSizeProperty();

		result = UIPropUtils::resolveValueToPixels(childFlex.flexBasis, static_cast<float>(_parentHeight));

		if (childFlex.flexBasis.type == FlexBasicValueTypeProperty::Auto)
		{
			// If Basis is Auto, use height instead
			result = UIPropUtils::resolveValueToPixels(childSize.size.width, static_cast<float>(_parentHeight));

			if (childSize.size.height.type == SizeValueTypeProperty::Auto)
			{
				// If height is also Auto, use content size
				sf::Vector2u contentSize;
				_child.calculateContentSize(contentSize);
				result = static_cast<float>(contentSize.y);
			}
		}

		return result;
	}
}
