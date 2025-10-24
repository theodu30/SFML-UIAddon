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

		/// <summary>
		/// <paragraph>Getter for Spacing Property.</paragraph>
		/// <paragraph>Allows access to margin and padding properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		SpacingProperty& getSpacingProperty();

		/// <summary>
		/// <paragraph>Getter for Border Property.</paragraph>
		/// <paragraph>Allows access to border color, width, and radius properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		BorderProperty& getBorderProperty();

		/// <summary>
		/// <paragraph>Getter for Transform Property.</paragraph>
		/// <paragraph>Allows access to transform origin, translate, scale, and rotate properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		TransformProperty& getTransformProperty();

		/// <summary>
		/// <paragraph>Getter for Size Property.</paragraph>
		/// <paragraph>Allows access to width and height properties, including min and max constraints.</paragraph>
		/// </summary>
		/// <returns></returns>
		SizeProperty& getSizeProperty();

		/// <summary>
		/// <paragraph>Getter for Position Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		PositionProperty& getPositionProperty();

		/// <summary>
		/// <paragraph>Getter for Flex Property.</paragraph>
		/// <paragraph>Allows access to shrink, grow, direction, and wrap properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		FlexProperty& getFlexProperty();

		/// <summary>
		/// <paragraph>Getter for Align Property.</paragraph>
		/// <paragraph>Allows access to align items, justify content, align self and align contents properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		AlignProperty& getAlignProperty();

		/// <summary>
		/// <paragraph>Getter for Opacity Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		OpacityProperty& getOpacityProperty();

		/// <summary>
		/// <paragraph>Getter for Visibility Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		VisibilityProperty& getVisibilityProperty();

		/// <summary>
		/// <paragraph>Getter for Display Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		DisplayProperty& getDisplayProperty();

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