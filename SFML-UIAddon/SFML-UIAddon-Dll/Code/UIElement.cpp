#include "Headers/SFUIL/UIElement.hpp"
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Headers/SFUIL/Graphics/RoundedRectangle.hpp"

namespace sfui
{
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
		removeFromParent();
		for (UIElement* child : m_children)
		{
			if (child != nullptr)
			{
				child->removeFromHierarchy();
				delete child;
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

	void UIElement::computePosition(const sf::Vector2f& _targetSize, const sf::FloatRect& _bounds)
	{
		float posX = 0.f;
		float posY = 0.f;
		if (UIPropUtils::isPositionAbsolute(m_position))
		{
			if (m_position.getLeft().type != PositionProperty::ValueType::Auto)
			{
				posX = m_position.getLeft().resolveToPixels(_targetSize.x);
			}
			else if (m_position.getRight().type != PositionProperty::ValueType::Auto)
			{
				float rightPos = m_position.getRight().resolveToPixels(_targetSize.x);
				posX = _targetSize.x - rightPos - _bounds.size.x;
			}

			if (m_position.getTop().type != PositionProperty::ValueType::Auto)
			{
				posY = m_position.getTop().resolveToPixels(_targetSize.y);
			}
			else if (m_position.getBottom().type != PositionProperty::ValueType::Auto)
			{
				float bottomPos = m_position.getBottom().resolveToPixels(_targetSize.y);
				posY = _targetSize.y - bottomPos - _bounds.size.y;
			}
		}
		else if (UIPropUtils::isPositionRelative(m_position))
		{
			if (m_parent)
			{
				const AlignProperty& parentAlign = m_parent->getConstProperty<AlignProperty>();

				const FlexProperty& parentFlex = m_parent->getConstProperty<FlexProperty>();

				size_t siblingCount = m_parent->getChildCount();

				size_t siblingIndex = 0;
				for (size_t i = 0; i < siblingCount; ++i)
				{
					if (m_parent->getChildren()[i] == this)
					{
						siblingIndex = i;
						break;
					}
				}

				if (UIPropUtils::isFlexDirectionRowType(parentFlex))
				{
					posX = UIPropUtils::calculateJustifyContentOffset(parentAlign, siblingIndex, siblingCount, _bounds.size.x, _targetSize.x);
					posY = UIPropUtils::calculateAlignItemsOffset(parentAlign, _bounds.size.y, _targetSize.y);
				}
				else if (UIPropUtils::isFlexDirectionColumnType(parentFlex))
				{
					posY = UIPropUtils::calculateJustifyContentOffset(parentAlign, siblingIndex, siblingCount, _bounds.size.y, _targetSize.y);
					posX = UIPropUtils::calculateAlignItemsOffset(parentAlign, _bounds.size.x, _targetSize.x);
				}
			}
			else
			{
				posX = 0.f;
				posY = 0.f;
			}
		}

		if (m_parent)
		{
			sf::Vector2f parentPos = m_parent->getRenderPosition();
			posX += parentPos.x;
			posY += parentPos.y;
		}

		m_renderPosition = sf::Vector2f(posX, posY);
	}

	void UIElement::applyTransformations(const sf::Vector2f& _targetSize, sf::Sprite& _sprite)
	{
		sf::Vector2f origin(
			m_transform.getOrigin().x.resolveToPixels(_sprite.getGlobalBounds().size.x),
			m_transform.getOrigin().y.resolveToPixels(_sprite.getGlobalBounds().size.y)
		);
		_sprite.setOrigin(origin);

		_sprite.move(origin);

		sf::Vector2f translation(
			m_transform.getTranslate().x.resolveToPixels(_targetSize.x),
			m_transform.getTranslate().y.resolveToPixels(_targetSize.y)
		);
		_sprite.move(translation);

		sf::Vector2f scale(m_transform.getScale().x, m_transform.getScale().y);
		_sprite.setScale(scale);

		m_transform.setRotate(UIPropUtils::normalizedAngle(m_transform.getRotate()));
		sf::Angle rotation = m_transform.getRotate().resolveToSfAngle();
		_sprite.setRotation(rotation);
	}

	void UIElement::applyTransformations(const sf::Vector2f& _targetSize, sf::Shape& _shape)
	{
		sf::Vector2f origin(
			m_transform.getOrigin().x.resolveToPixels(_shape.getGlobalBounds().size.x),
			m_transform.getOrigin().y.resolveToPixels(_shape.getGlobalBounds().size.y)
		);
		_shape.setOrigin(origin);

		_shape.move(origin);

		sf::Vector2f translation(
			m_transform.getTranslate().x.resolveToPixels(_targetSize.x),
			m_transform.getTranslate().y.resolveToPixels(_targetSize.y)
		);
		_shape.move(translation);

		sf::Vector2f scale(m_transform.getScale().x, m_transform.getScale().y);
		_shape.setScale(scale);

		m_transform.setRotate(UIPropUtils::normalizedAngle(m_transform.getRotate()));
		sf::Angle rotation = m_transform.getRotate().resolveToSfAngle();
		_shape.setRotation(rotation);
	}

	void UIElement::drawBackground(sf::RenderTexture& _target, const sf::Vector2f& _targetSize)
	{
		size_t pointsPerCorner = static_cast<size_t>(std::fmaxf(1.f, std::ceilf(m_border.getRadius())));
		float radius = m_border.getRadius();
		if (pointsPerCorner == 1 || radius == 0.f)
		{
			sf::RectangleShape backgroundShape;
			backgroundShape.setSize(m_renderSize);
			backgroundShape.setFillColor(m_background.getColor());
			backgroundShape.setOutlineThickness(m_border.getWidth());
			backgroundShape.setOutlineColor(m_border.getColor());

			computePosition(_targetSize, backgroundShape.getGlobalBounds());
			backgroundShape.setPosition(m_renderPosition);
			applyTransformations(_targetSize, backgroundShape);

			_target.draw(backgroundShape);
		}
		else
		{
			RoundedRectangle backgroundShape;
			backgroundShape.setSize(m_renderSize);
			backgroundShape.setFillColor(m_background.getColor());
			backgroundShape.setOutlineThickness(-m_border.getWidth());
			backgroundShape.setOutlineColor(m_border.getColor());
			backgroundShape.setRadius(m_border.getRadius());
			backgroundShape.setPointsPerCorner(pointsPerCorner);

			computePosition(_targetSize, backgroundShape.getGlobalBounds());
			backgroundShape.setPosition(m_renderPosition);
			applyTransformations(_targetSize, backgroundShape);

			_target.draw(backgroundShape);
		}
	}
}