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
}