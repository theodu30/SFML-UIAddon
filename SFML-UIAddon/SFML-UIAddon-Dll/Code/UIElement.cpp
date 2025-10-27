#include "Headers/SFUIL/UIElement.hpp"

namespace sfui
{
	SpacingProperty& sfui::UIElement::getSpacingProperty()
	{
		return m_spacing;
	}

	BorderProperty& UIElement::getBorderProperty()
	{
		return m_border;
	}

	TransformProperty& UIElement::getTransformProperty()
	{
		return m_transform;
	}

	SizeProperty& UIElement::getSizeProperty()
	{
		return m_size;
	}

	PositionProperty& UIElement::getPositionProperty()
	{
		return m_position;
	}

	FlexProperty& UIElement::getFlexProperty()
	{
		return m_flex;
	}

	AlignProperty& UIElement::getAlignProperty()
	{
		return m_align;
	}

	OpacityProperty& UIElement::getOpacityProperty()
	{
		return m_opacity;
	}

	VisibilityProperty& UIElement::getVisibilityProperty()
	{
		return m_visibility;
	}

	DisplayProperty& UIElement::getDisplayProperty()
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
}