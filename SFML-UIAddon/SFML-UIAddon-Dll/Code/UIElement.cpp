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

	std::vector<UIElement*>& UIElement::getChildren()
	{
		return m_children;
	}

	sf::Vector2u UIElement::getTextureSize() const
	{
		return m_renderTexture.getSize();
	}

	void UIElement::markDirty()
	{
		m_dirty = true;
		if (m_parent)
		{
			m_parent->markDirty();
		}
	}
}