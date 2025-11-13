#include "Headers/SFUIL/Containers/UIVisualContainer.hpp"
#include <iostream>
#include "math.h"

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
		removeFromHierarchy();
	}

	void UIVisualContainer::drawToTarget(sf::RenderTexture& _target)
	{
		if (m_display.getDisplay() == DisplayProperty::Type::None)
		{
			return;
		}

		reRenderIfDirty(_target);

		sf::Vector2f targetSize(_target.getSize());
		if (m_parent)
		{
			targetSize = m_parent->getRenderSize();
		}

		drawBackground(_target, targetSize);

		for (auto& child : m_children)
		{
			child->drawToTarget(_target);
		}
	}

	void UIVisualContainer::reRenderIfDirty(sf::RenderTexture& _texture)
	{
		if (!m_dirty) return;

		m_dirty = false;

		sf::Vector2u parentSize = _texture.getSize();

		FlexProperty parentFlex;

		if (m_parent)
		{
			parentSize = sf::Vector2u(m_parent->getRenderSize());
			parentFlex = m_parent->getConstProperty<FlexProperty>();
		}

		sf::Vector2u newSize;
		calculateNewSize(newSize, parentSize, parentFlex);
		m_renderSize = sf::Vector2f(newSize);
	}

	void UIVisualContainer::Initialize()
	{
		UIElement::Initialize();
		markDirty();
	}

	void UIVisualContainer::calculateNewSize(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex)
	{
		sf::Vector2u minSize;
		sf::Vector2u maxSize;
		calculateFinalMinMaxSizes(minSize, maxSize, _parentSize, _parentFlex);

		if (UIPropUtils::isPositionAbsolute(m_position))
		{
			calculateNewSizeInAbsolute(newSize, _parentSize, _parentFlex);
		}
		else if (UIPropUtils::isPositionRelative(m_position))
		{
			calculateNewSizeInRelative(newSize, _parentSize, _parentFlex);
		}

		newSize.x = UIPropUtils::clampUnsignedInt(newSize.x, minSize.x, maxSize.x);
		newSize.y = UIPropUtils::clampUnsignedInt(newSize.y, minSize.y, maxSize.y);
	}

	void UIVisualContainer::calculateNewSizeInAbsolute(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex)
	{
		const SizeProperty::Size& sizeProp = m_size.getSize();

		newSize.x = static_cast<unsigned int>(sizeProp.width.resolveToPixels(static_cast<float>(_parentSize.x)));

		newSize.y = static_cast<unsigned int>(sizeProp.height.resolveToPixels(static_cast<float>(_parentSize.y)));

		if (sizeProp.height.type == SizeProperty::SizeType::Auto)
		{
			sf::Vector2u contentSize;
			calculateContentSize(contentSize);
			newSize.y = contentSize.y;
		}

		if (sizeProp.width.type == SizeProperty::SizeType::Auto)
		{
			float left = m_position.getLeft().resolveToPixels(static_cast<float>(_parentSize.x));
			float right = m_position.getRight().resolveToPixels(static_cast<float>(_parentSize.x));
			newSize.x = static_cast<unsigned int>(static_cast<float>(_parentSize.x) - left - right);
		}
	}

	void UIVisualContainer::calculateNewSizeInRelative(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex)
	{
		if (UIPropUtils::isFlexDirectionRowType(_parentFlex))
		{
			newSize.y = _parentSize.y;

			float basicValue = resolveFinalBasicWidth(*this, static_cast<float>(_parentSize.x));

			float growShrinkFactor = 0.f;

			if (m_parent)
			{
				float totalFlexGrow = 0.f;
				float totalFlexShrink = 0.f;
				float totalBasic = 0.f;
				for (const auto& sibling : m_parent->getChildren())
				{
					const FlexProperty& siblingFlex = sibling->getConstProperty<FlexProperty>();
					totalFlexGrow += siblingFlex.getFlexGrow();

					float childBasic = resolveFinalBasicWidth(*sibling->as<UIVisualContainer>(), static_cast<float>(_parentSize.x));

					totalBasic += childBasic;
					totalFlexShrink += siblingFlex.getFlexShrink() * childBasic;
				}

				if (static_cast<float>(_parentSize.x) > totalBasic && totalFlexGrow > 0)
				{
					growShrinkFactor = (m_flex.getFlexGrow() / totalFlexGrow) * (_parentSize.x - totalBasic);
				}
				else if (static_cast<float>(_parentSize.x) < totalBasic && totalFlexShrink > 0)
				{
					growShrinkFactor = ((m_flex.getFlexShrink() * basicValue) / totalFlexShrink) * (_parentSize.x - totalBasic);
				}
			}

			newSize.x = static_cast<unsigned int>(basicValue + growShrinkFactor);
		}
		else if (UIPropUtils::isFlexDirectionColumnType(_parentFlex))
		{
			newSize.x = _parentSize.x;

			float basicValue = resolveFinalBasicHeight(*this, static_cast<float>(_parentSize.y));

			float growShrinkFactor = 0.f;

			if (m_parent)
			{
				float totalFlexGrow = 0.f;
				float totalFlexShrink = 0.f;
				float totalBasic = 0.f;
				for (const auto& sibling : m_parent->getChildren())
				{
					const FlexProperty& siblingFlex = sibling->getConstProperty<FlexProperty>();
					totalFlexGrow += siblingFlex.getFlexGrow();

					float childBasic = resolveFinalBasicHeight(*sibling->as<UIVisualContainer>(), static_cast<float>(_parentSize.y));


					totalBasic += childBasic;
					totalFlexShrink += siblingFlex.getFlexShrink() * childBasic;
				}

				if (static_cast<float>(_parentSize.y) > totalBasic && totalFlexGrow > 0)
				{
					growShrinkFactor = (m_flex.getFlexGrow() / totalFlexGrow) * (_parentSize.y - totalBasic);
				}
				else if (static_cast<float>(_parentSize.y) < totalBasic && totalFlexShrink > 0)
				{
					growShrinkFactor = ((m_flex.getFlexShrink() * basicValue) / totalFlexShrink) * (_parentSize.y - totalBasic);
				}
			}

			newSize.y = static_cast<unsigned int>(basicValue + growShrinkFactor);
		}
	}

	void UIVisualContainer::calculateFinalMinMaxSizes(sf::Vector2u& minSize, sf::Vector2u& maxSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex) const
	{
		const SizeProperty::MinSize& minProp = m_size.getMinSize();

		minSize.x = static_cast<unsigned int>(minProp.width.resolveToPixels(static_cast<float>(_parentSize.x)));

		minSize.y = static_cast<unsigned int>(minProp.height.resolveToPixels(static_cast<float>(_parentSize.y)));

		const SizeProperty::MaxSize& maxProp = m_size.getMaxSize();

		maxSize.x = static_cast<unsigned int>(maxProp.width.resolveToPixels(static_cast<float>(_parentSize.x)));

		maxSize.y = static_cast<unsigned int>(maxProp.height.resolveToPixels(static_cast<float>(_parentSize.y)));
	}

	void UIVisualContainer::calculateContentSize(sf::Vector2u& contentSize) const
	{
		if (m_children.empty())
		{
			contentSize = sf::Vector2u(0u, 0u);
			return;
		}
		else
		{
			for (const auto& child : m_children)
			{
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

		const FlexProperty& childFlex = _child.getConstProperty<FlexProperty>();
		const SizeProperty::Size& childSize = _child.getConstProperty<SizeProperty>().getSize();

		result = childFlex.getFlexBasic().resolveToPixels(static_cast<float>(_parentWidth));

		if (childFlex.getFlexBasic().type == FlexProperty::BasicType::Auto)
		{
			result = childSize.width.resolveToPixels(static_cast<float>(_parentWidth));

			if (childSize.width.type == SizeProperty::SizeType::Auto)
			{
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

		const FlexProperty& childFlex = _child.getConstProperty<FlexProperty>();
		const SizeProperty::Size& childSize = _child.getConstProperty<SizeProperty>().getSize();

		result = childFlex.getFlexBasic().resolveToPixels(static_cast<float>(_parentHeight));

		if (childFlex.getFlexBasic().type == FlexProperty::BasicType::Auto)
		{
			result = childSize.width.resolveToPixels(static_cast<float>(_parentHeight));

			if (childSize.height.type == SizeProperty::SizeType::Auto)
			{
				sf::Vector2u contentSize;
				_child.calculateContentSize(contentSize);
				result = static_cast<float>(contentSize.y);
			}
		}

		return result;
	}
}
