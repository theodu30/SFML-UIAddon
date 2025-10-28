#include "Headers/SFUIL/UIElement.hpp"

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

	void UIElement::markDirty()
	{
		m_dirty = true;
		if (m_parent)
		{
			m_parent->markDirty();
		}
	}

	const sf::Vector2u& UIElement::calculateRelativeTextureSize() const
	{
		static sf::Vector2u relativeSize;

		if (!m_parent)
		{
			relativeSize = m_renderTexture.getSize();
		}
		else
		{
			// Get FlexProperty of parent for layout calculations
			const FlexProperty& parentFlex = static_cast<const UIElement*>(m_parent)->getConstFlexProperty();

			// Get number of siblings for size distribution
			const size_t& siblingCount = m_parent->getChildCount();

			// Basic calculation: divide parent's size by number of siblings depending on flex direction
			switch (parentFlex.flexDirection)
			{
			case FlexDirectionProperty::Column:
			case FlexDirectionProperty::ColumnReverse:
				relativeSize.x = m_parent->m_renderTexture.getSize().x;
				relativeSize.y = m_parent->m_renderTexture.getSize().y / static_cast<unsigned int>(siblingCount);
				break;
			case FlexDirectionProperty::Row:
			case FlexDirectionProperty::RowReverse:
				relativeSize.x = m_parent->m_renderTexture.getSize().x / static_cast<unsigned int>(siblingCount);
				relativeSize.y = m_parent->m_renderTexture.getSize().y;
				break;
			}
		}

		return relativeSize;
	}
}