#pragma once

#include "System/Exports.hpp"
#include "System/UIElementProperty.hpp"
#include <SFML/Graphics/RenderTexture.hpp>

namespace sfui
{
	class SFUIL_API UIElement
	{
	public:
		UIElement() = default;
		virtual ~UIElement() = default;
		virtual void render(sf::RenderTexture& _texture) = 0;
		virtual void drawToTarget(sf::RenderTarget& _target) = 0;

		SpacingProperty& getSpacingProperty() { return m_spacing; }
		BorderProperty& getBorderProperty() { return m_border; }
		TransformProperty& getTransformProperty() { return m_transform; }
		SizeProperty& getSizeProperty() { return m_size; }
		PositionProperty& getPositionProperty() { return m_position; }
		FlexProperty& getFlexProperty() { return m_flex; }
		AlignProperty& getAlignProperty() { return m_align; }
		OpacityProperty& getOpacityProperty() { return m_opacity; }
		VisibilityProperty& getVisibilityProperty() { return m_visibility; }
		DisplayProperty& getDisplayProperty() { return m_display; }
	protected:
		SpacingProperty m_spacing;
		BorderProperty m_border;
		TransformProperty m_transform;
		SizeProperty m_size;
		PositionProperty m_position;
		FlexProperty m_flex;
		AlignProperty m_align;
		OpacityProperty m_opacity;
		VisibilityProperty m_visibility;
		DisplayProperty m_display;
	};
}