#include "Headers/SFUIL/UIElement.hpp"
#include <iostream>

namespace sfui
{
	SpacingProperty& sfui::UIElement::getSpacingProperty()
	{
		markDirty();
		return m_spacing;
	}

	const SpacingProperty& UIElement::getConstSpacingProperty() const
	{
		return m_spacing;
	}

	BorderProperty& UIElement::getBorderProperty()
	{
		markDirty();
		return m_border;
	}

	const BorderProperty& UIElement::getConstBorderProperty() const
	{
		return m_border;
	}

	TransformProperty& UIElement::getTransformProperty()
	{
		markDirty();
		return m_transform;
	}

	const TransformProperty& UIElement::getConstTransformProperty() const
	{
		return m_transform;
	}

	SizeProperty& UIElement::getSizeProperty()
	{
		markDirty();
		return m_size;
	}

	const SizeProperty& UIElement::getConstSizeProperty() const
	{
		return m_size;
	}

	PositionProperty& UIElement::getPositionProperty()
	{
		markDirty();
		return m_position;
	}

	const PositionProperty& UIElement::getConstPositionProperty() const
	{
		return m_position;
	}

	BackgroundProperty& UIElement::getBackgroundProperty()
	{
		markDirty();
		return m_background;
	}

	const BackgroundProperty& UIElement::getConstBackgroundProperty() const
	{
		return m_background;
	}

	FlexProperty& UIElement::getFlexProperty()
	{
		markDirty();
		return m_flex;
	}

	const FlexProperty& UIElement::getConstFlexProperty() const
	{
		return m_flex;
	}

	AlignProperty& UIElement::getAlignProperty()
	{
		markDirty();
		return m_align;
	}

	const AlignProperty& UIElement::getConstAlignProperty() const
	{
		return m_align;
	}

	OpacityProperty& UIElement::getOpacityProperty()
	{
		markDirty();
		return m_opacity;
	}

	const OpacityProperty& UIElement::getConstOpacityProperty() const
	{
		return m_opacity;
	}

	VisibilityProperty& UIElement::getVisibilityProperty()
	{
		markDirty();
		return m_visibility;
	}

	const VisibilityProperty& UIElement::getConstVisibilityProperty() const
	{
		return m_visibility;
	}

	DisplayProperty& UIElement::getDisplayProperty()
	{
		markDirty();
		return m_display;
	}

	const DisplayProperty& UIElement::getConstDisplayProperty() const
	{
		return m_display;
	}

	void UIElement::setName(const char* _name)
	{
		m_name = _name;
	}

	const char* UIElement::getName() const
	{
		return m_name;
	}

	size_t UIElement::getChildCount() const noexcept
	{
		return m_children.size();
	}

	bool UIElement::addChild(UIElement* _child)
	{
		if (_child == nullptr)
		{
			return false;
		}
		_child->m_parent = this;
		m_children.push_back(_child);
		return true;
	}

	bool UIElement::removeFromParent()
	{
		if (m_parent == nullptr)
		{
			return false;
		}
		auto& siblings = m_parent->m_children;
		auto it = std::find(siblings.begin(), siblings.end(), this);
		if (it != siblings.end())
		{
			siblings.erase(it);
			m_parent = nullptr;
			return true;
		}
		return false;
	}

	bool UIElement::removeFromHierarchy()
	{
		// Remove from parent first
		removeFromParent();
		// Recursively remove all children
		for (UIElement* child : m_children)
		{
			if (child != nullptr)
			{
				child->removeFromHierarchy();
				delete child; // Assuming ownership and responsibility for deletion
			}
		}
		m_children.clear();
		return true;
	}

	std::vector<UIElement*>& UIElement::getChildren()
	{
		return m_children;
	}

	sf::Vector2f UIElement::getRenderSize() const
	{
		return m_renderSize;
	}

	sf::Vector2f UIElement::getRenderPosition() const
	{
		return m_renderPosition;
	}

	void UIElement::markDirty()
	{
		m_dirty = true;
		if (m_parent)
		{
			m_parent->markDirty();
		}
	}

	void UIElement::computePosition(sf::Vector2f& _targetSize, const sf::FloatRect& _bounds)
	{
		// Apply Positioning using m_position, m_align, etc.
		float posX = 0.f;
		float posY = 0.f;
		// Check if position is absolute
		if (UIPropUtils::isPositionAbsolute(m_position))
		{
			// Horizontal Positioning
			if (m_position.left.type != PositionValueTypeProperty::Auto)
			{
				posX = UIPropUtils::resolveValueToPixels(m_position.left, _targetSize.x);
			}
			else if (m_position.right.type != PositionValueTypeProperty::Auto)
			{
				float rightPos = UIPropUtils::resolveValueToPixels(m_position.right, _targetSize.x);
				posX = _targetSize.x - rightPos - _bounds.size.x;
			}

			//Vertical Positioning
			if (m_position.top.type != PositionValueTypeProperty::Auto)
			{
				posY = UIPropUtils::resolveValueToPixels(m_position.top, _targetSize.y);
			}
			else if (m_position.bottom.type != PositionValueTypeProperty::Auto)
			{
				float bottomPos = UIPropUtils::resolveValueToPixels(m_position.bottom, _targetSize.y);
				posY = _targetSize.y - bottomPos - _bounds.size.y;
			}
		}
		// Check if position is relative
		else if (UIPropUtils::isPositionRelative(m_position))
		{
			if (m_parent)
			{
				// Get parent align property (there will always be a parent for relative positioning because root element exists)
				const AlignProperty& parentAlign = m_parent->getConstAlignProperty();

				// Get parent flex property
				const FlexProperty& parentFlex = m_parent->getConstFlexProperty();

				// Get number of siblings
				size_t siblingCount = m_parent->getChildCount();

				// Get index among siblings
				size_t siblingIndex = 0;
				for (size_t i = 0; i < siblingCount; ++i)
				{
					if (m_parent->getChildren()[i] == this)
					{
						siblingIndex = i;
						break;
					}
				}

				// Check for flex direction
				if (UIPropUtils::isFlexDirectionRowType(parentFlex))
				{
					// Horizontal Positioning based on JustifyContent
					posX = UIPropUtils::calculateJustifyContentOffset(parentAlign.justifyContent, siblingIndex, siblingCount, _bounds.size.x, _targetSize.x);
					// Vertical Positioning based on AlignItems
					posY = UIPropUtils::calculateAlignItemsOffset(parentAlign.alignItems, _bounds.size.y, _targetSize.y);
				}
				else if (UIPropUtils::isFlexDirectionColumnType(parentFlex))
				{
					// Vertical Positioning based on JustifyContent
					posY = UIPropUtils::calculateJustifyContentOffset(parentAlign.justifyContent, siblingIndex, siblingCount, _bounds.size.y, _targetSize.y);
					// Horizontal Positioning based on AlignItems
					posX = UIPropUtils::calculateAlignItemsOffset(parentAlign.alignItems, _bounds.size.x, _targetSize.x);
				}
			}
			// If no parent (root element), position at (0,0)
			else
			{
				posX = 0.f;
				posY = 0.f;
			}
		}

		// Apply parent position offset if exists
		if (m_parent)
		{
			sf::Vector2f parentPos = m_parent->getRenderPosition();
			posX += parentPos.x;
			posY += parentPos.y;
		}

		// Set render position
		m_renderPosition = sf::Vector2f(posX, posY);
	}

	void UIElement::applyTransformations(sf::Vector2f& _targetSize, sf::Sprite& _sprite)
	{
		// Apply Transformations using m_transform (origin, translate, scale, rotate)
		// Apply Origin
		sf::Vector2f origin(
			UIPropUtils::resolveValueToPixels(m_transform.origin.x, _sprite.getGlobalBounds().size.x),
			UIPropUtils::resolveValueToPixels(m_transform.origin.y, _sprite.getGlobalBounds().size.y)
		);
		_sprite.setOrigin(origin);

		// Apply origin offset to position
		_sprite.move(origin);

		// Apply Translation
		sf::Vector2f translation(
			UIPropUtils::resolveValueToPixels(m_transform.translate.x, _targetSize.x),
			UIPropUtils::resolveValueToPixels(m_transform.translate.y, _targetSize.y)
		);
		_sprite.move(translation);

		// Apply Scaling
		sf::Vector2f scale(m_transform.scale.x.value, m_transform.scale.y.value);
		_sprite.setScale(scale);

		// Apply Rotation
		UIPropUtils::normalizeAngle(m_transform.rotate.angle);
		sf::Angle rotation = UIPropUtils::resolveAngleToSfAngle(m_transform.rotate.angle);
		_sprite.setRotation(rotation);
	}

	void UIElement::applyTransformations(sf::Vector2f& _targetSize, sf::RectangleShape& _shape)
	{
		// Apply Transformations using m_transform (origin, translate, scale, rotate)
		// Apply Origin
		sf::Vector2f origin(
			UIPropUtils::resolveValueToPixels(m_transform.origin.x, _shape.getGlobalBounds().size.x),
			UIPropUtils::resolveValueToPixels(m_transform.origin.y, _shape.getGlobalBounds().size.y)
		);
		_shape.setOrigin(origin);

		// Apply origin offset to position
		_shape.move(origin);

		// Apply Translation
		sf::Vector2f translation(
			UIPropUtils::resolveValueToPixels(m_transform.translate.x, _targetSize.x),
			UIPropUtils::resolveValueToPixels(m_transform.translate.y, _targetSize.y)
		);
		_shape.move(translation);

		// Apply Scaling
		sf::Vector2f scale(m_transform.scale.x.value, m_transform.scale.y.value);
		_shape.setScale(scale);

		// Apply Rotation
		UIPropUtils::normalizeAngle(m_transform.rotate.angle);
		sf::Angle rotation = UIPropUtils::resolveAngleToSfAngle(m_transform.rotate.angle);
		_shape.setRotation(rotation);
	}
}