#pragma once

#include "Exports.hpp"
#include "Anchor.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sfui
{
	struct SFUIL_API OpacityProperty
	{
		float value = 1.f; // Opacity value between 0.0f (transparent) and 1.0f (opaque)
	};

	enum class SFUIL_API DisplayValueTypeProperty : char
	{
		Flex,
		None
	};

	struct SFUIL_API DisplayProperty
	{
		DisplayValueTypeProperty type = DisplayValueTypeProperty::Flex; // The display type
	};

	enum class SFUIL_API VisibilityValueTypeProperty : char
	{
		Visible,
		Hidden
	};

	struct SFUIL_API VisibilityProperty
	{
		VisibilityValueTypeProperty type = VisibilityValueTypeProperty::Visible; // The visibility type
	};

	enum class SFUIL_API PositionModeProperty : char
	{
		Relative,
		Absolute
	};

	enum class SFUIL_API PositionValueTypeProperty : char
	{
		Auto,
		Pixels,
		Percentage
	};

	struct SFUIL_API PositionValueProperty
	{
		float value = 0.f; // The value for the position
		PositionValueTypeProperty type = PositionValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API PositionProperty
	{
		PositionModeProperty mode = PositionModeProperty::Relative; // The position mode
		PositionValueProperty top;
		PositionValueProperty right;
		PositionValueProperty bottom;
		PositionValueProperty left;
	};

	enum class SFUIL_API FlexBasicValueTypeProperty
	{
		Auto,
		Pixels,
		Percentage
	};

	struct SFUIL_API FlexBasicValueProperty
	{
		float value = 0.f; // The value for the flex basis
		FlexBasicValueTypeProperty type = FlexBasicValueTypeProperty::Auto; // The type of the value
	};

	struct SFUIL_API FlexShrinkProperty
	{
		float value = 1.f; // The flex shrink factor
	};

	struct SFUIL_API FlexGrowProperty
	{
		float value = 1.f; // The flex grow factor
	};

	enum class SFUIL_API FlexDirectionProperty : char
	{
		Column,
		ColumnReverse,
		Row,
		RowReverse
	};

	enum class SFUIL_API FlexWarpProperty : char
	{
		NoWrap,
		Wrap,
		WrapReverse
	};

	struct SFUIL_API FlexProperty
	{
		FlexBasicValueProperty flexBasis;
		FlexShrinkProperty flexShrink;
		FlexGrowProperty flexGrow;
		FlexDirectionProperty flexDirection = FlexDirectionProperty::Column;
		FlexWarpProperty flexWrap = FlexWarpProperty::NoWrap;
	};

	enum class SFUIL_API AlignItemsProperty : char
	{
		Auto,
		FlexStart,
		Center,
		FlexEnd,
		Stretch
	};

	enum class SFUIL_API JustifyContentProperty : char
	{
		FlexStart,
		Center,
		FlexEnd,
		SpaceBetween,
		SpaceAround,
		SpaceEvenly
	};

	enum class SFUIL_API AlignSelfProperty : char
	{
		Auto,
		FlexStart,
		Center,
		FlexEnd,
		Stretch
	};

	enum class SFUIL_API AlignContentProperty : char
	{
		Auto,
		FlexStart,
		Center,
		FlexEnd,
		Stretch
	};

	struct SFUIL_API AlignProperty
	{
		AlignItemsProperty alignItems = AlignItemsProperty::Stretch;
		JustifyContentProperty justifyContent = JustifyContentProperty::FlexStart;
		AlignSelfProperty alignSelf = AlignSelfProperty::Auto;
		AlignContentProperty alignContent = AlignContentProperty::FlexStart;
	};

	enum class SFUIL_API SizeValueTypeProperty : char
	{
		Auto,
		Pixels,
		Percentage
	};

	enum class SFUIL_API MinSizeValueTypeProperty : char
	{
		Auto,
		Pixels,
		Percentage
	};

	enum class SFUIL_API MaxSizeValueTypeProperty : char
	{
		None,
		Pixels,
		Percentage
	};

	struct SFUIL_API SizeValueProperty
	{
		float value = 0.f; // The value for the width or height
		SizeValueTypeProperty type = SizeValueTypeProperty::Auto; // The type of the value
	};

	struct SFUIL_API MinSizeValueProperty
	{
		float value = 0.f; // The value for the width or height
		MinSizeValueTypeProperty type = MinSizeValueTypeProperty::Auto; // The type of the value
	};

	struct SFUIL_API MaxSizeValueProperty
	{
		float value = 0.f; // The value for the width or height
		MaxSizeValueTypeProperty type = MaxSizeValueTypeProperty::None; // The type of the value
	};

	struct SFUIL_API SizeVectorProperty
	{
		SizeValueProperty width;
		SizeValueProperty height;
	};

	struct SFUIL_API MinSizeVectorProperty
	{
		MinSizeValueProperty width;
		MinSizeValueProperty height;
	};

	struct SFUIL_API MaxSizeVectorProperty
	{
		MaxSizeValueProperty width;
		MaxSizeValueProperty height;
	};

	struct SFUIL_API SizeProperty
	{
		SizeVectorProperty size;
		MinSizeVectorProperty minSize;
		MaxSizeVectorProperty maxSize;
	};

	enum class SFUIL_API MarginValueTypeProperty : char
	{
		Auto,
		Pixels,
		Percentage
	};

	struct SFUIL_API MarginValueProperty
	{
		float value = 0.f; // The value for the margin
		MarginValueTypeProperty type = MarginValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API MarginProperty
	{
		MarginValueProperty top;
		MarginValueProperty right;
		MarginValueProperty bottom;
		MarginValueProperty left;
	};

	enum class SFUIL_API PaddingValueTypeProperty : char
	{
		Auto,
		Pixels,
		Percentage
	};

	struct SFUIL_API PaddingValueProperty
	{
		float value = 0.f; // The value for the padding
		PaddingValueTypeProperty type = PaddingValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API PaddingProperty
	{
		PaddingValueProperty top;
		PaddingValueProperty right;
		PaddingValueProperty bottom;
		PaddingValueProperty left;
	};

	struct SFUIL_API SpacingProperty
	{
		MarginProperty margin;
		PaddingProperty padding;
	};

	struct SFUIL_API BackgroundProperty
	{
		sf::Color color = sf::Color::Transparent; // The background color
	};

	struct SFUIL_API BorderColorValueProperty
	{
		sf::Color color = sf::Color::Black; // The color of the border
	};

	struct SFUIL_API BorderColorProperty
	{
		BorderColorValueProperty top;
		BorderColorValueProperty right;
		BorderColorValueProperty bottom;
		BorderColorValueProperty left;
	};

	enum class SFUIL_API BorderWidthValueTypeProperty : char
	{
		Pixels
	};

	struct SFUIL_API BorderWidthValueProperty
	{
		float value = 0.f; // The value for the border width
		BorderWidthValueTypeProperty type = BorderWidthValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API BorderWidthProperty
	{
		BorderWidthValueProperty top;
		BorderWidthValueProperty right;
		BorderWidthValueProperty bottom;
		BorderWidthValueProperty left;
	};

	enum class SFUIL_API BorderRadiusValueTypeProperty : char
	{
		Pixels,
		Percentage
	};

	struct SFUIL_API BorderRadiusValueProperty
	{
		float value = 0.f; // The value for the border radius
		BorderRadiusValueTypeProperty type = BorderRadiusValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API BorderRadiusProperty
	{
		BorderRadiusValueProperty topLeft;
		BorderRadiusValueProperty topRight;
		BorderRadiusValueProperty bottomRight;
		BorderRadiusValueProperty bottomLeft;
	};

	struct SFUIL_API BorderProperty
	{
		BorderColorProperty color;
		BorderWidthProperty width;
		BorderRadiusProperty radius;
	};

	enum class SFUIL_API TransformOriginValueTypeProperty : char
	{
		Pixels,
		Percentage
	};

	struct SFUIL_API TransformOriginValueProperty
	{
		float value = 0.f; // The value for the transform origin
		TransformOriginValueTypeProperty type = TransformOriginValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API TransformOriginProperty
	{
		TransformOriginValueProperty x;
		TransformOriginValueProperty y;
	};

	enum class SFUIL_API TransformTranslateValueTypeProperty : char
	{
		Pixels,
		Percentage
	};

	struct SFUIL_API TransformTranslateValueProperty
	{
		float value = 0.f; // The value for the transform translate
		TransformTranslateValueTypeProperty type = TransformTranslateValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API TransformTranslateProperty
	{
		TransformTranslateValueProperty x;
		TransformTranslateValueProperty y;
	};

	struct SFUIL_API TransformScaleValueProperty
	{
		float value = 1.f; // The value for the transform scale
	};

	struct SFUIL_API TransformScaleProperty
	{
		TransformScaleValueProperty x;
		TransformScaleValueProperty y;
	};

	enum class SFUIL_API TransformRotateValueTypeProperty : char
	{
		Degrees,
		Radians
	};

	struct SFUIL_API TransformRotateValueProperty
	{
		float value = 0.f; // The value for the transform rotate
		TransformRotateValueTypeProperty type = TransformRotateValueTypeProperty::Degrees; // The type of the value
	};

	struct SFUIL_API TransformRotateProperty
	{
		TransformRotateValueProperty angle;
	};

	struct SFUIL_API TransformProperty
	{
		TransformOriginProperty origin;
		TransformTranslateProperty translate;
		TransformScaleProperty scale;
		TransformRotateProperty rotate;
	};

	/// <summary>
	/// <paragraph>Utility class that contains different utility functions for UI element properties.</paragraph>
	/// </summary>
	class SFUIL_API UIPropUtils
	{
	public:
		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const PositionValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const SizeValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const MinSizeValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const MaxSizeValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const MarginValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const PaddingValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const BorderWidthValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const BorderRadiusValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const TransformOriginValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const TransformTranslateValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a property value to pixels based on its type and a relative reference value.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <param name="_relativeTo"></param>
		/// <returns></returns>
		static float resolveValueToPixels(const FlexBasicValueProperty& _prop, float _relativeTo);

		/// <summary>
		/// <paragraph>Resolves a rotation angle property to degrees based on its type.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <returns></returns>
		static float resolveAngleToDegrees(const TransformRotateValueProperty& _prop);

		/// <summary>
		/// <paragraph>Resolves a rotation angle property to radians based on its type.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <returns></returns>
		static float resolveAngleToRadians(const TransformRotateValueProperty& _prop);

		/// <summary>
		/// <paragraph>Resolves a rotation angle property to sf::Angle based on its type.</paragraph>
		/// </summary>
		/// <param name="_prop"></param>
		/// <returns></returns>
		static sf::Angle resolveAngleToSfAngle(const TransformRotateValueProperty& _prop);

		/// <summary>
		/// <paragraph>Checks if the flex direction is of row or reverse row type.</paragraph>
		/// </summary>
		/// <param name="_flex"></param>
		/// <returns></returns>
		static bool isFlexDirectionRowType(const FlexProperty& _flex);

		/// <summary>
		/// <paragraph>Checks if the flex direction is of column orr reverse column type.</paragraph>
		/// </summary>
		/// <param name="_flex"></param>
		/// <returns></returns>
		static bool isFlexDirectionColumnType(const FlexProperty& _flex);

		/// <summary>
		/// <paragraph>Checks if the flex direction is of reverse row or reverse column type.</paragraph>
		/// </summary>
		/// <param name="_flex"></param>
		/// <returns></returns>
		static bool isFlexDirectionReverseType(const FlexProperty& _flex);

		/// <summary>
		/// <paragraph>Checks if the position mode is absolute.</paragraph>
		/// </summary>
		/// <param name="_position"></param>
		/// <returns></returns>
		static bool isPositionAbsolute(const PositionProperty& _position);

		/// <summary>
		/// <paragraph>Checks if the position mode is relative.</paragraph>
		/// </summary>
		/// <param name="_position"></param>
		/// <returns></returns>
		static bool isPositionRelative(const PositionProperty& _position);

		/// <summary>
		/// <paragraph>Clamps a float value between a minimum and maximum value.</paragraph>
		/// </summary>
		/// <param name="_value"></param>
		/// <param name="_min"></param>
		/// <param name="_max"></param>
		/// <returns>Returns _min if _value less than _min, _max if _value more than _max, otherwise simply returns _value.</returns>
		static float clampFloat(float _value, float _min, float _max);

		/// <summary>
		/// <paragraph>Clamps an unsigned int value between a minimum and maximum value.</paragraph>
		/// </summary>
		/// <param name="_value"></param>
		/// <param name="_min"></param>
		/// <param name="_max"></param>
		/// <returns>>Returns _min if _value less than _min, _max if _value more than _max, otherwise simply returns _value.</returns>
		static unsigned int clampUnsignedInt(unsigned int _value, unsigned int _min, unsigned int _max);

		/// <summary>
		/// <paragraph>Calculates the offset for an element based on JustifyContent property.</paragraph>
		/// </summary>
		/// <param name="_justifyContent"></param>
		/// <param name="_siblingIndex"></param>
		/// <param name="_siblingCount"></param>
		/// <param name="_elementSize"></param>
		/// <param name="_parentSize"></param>
		/// <returns></returns>
		static float calculateJustifyContentOffset(const JustifyContentProperty& _justifyContent, size_t _siblingIndex, size_t _siblingCount, float _elementSize, float _parentSize);

		/// <summary>
		/// <paragraph>Calculates the offset for an element based on AlignItems property.</paragraph>
		/// </summary>
		/// <param name="_alignItems"></param>
		/// <param name="_elementSize"></param>
		/// <param name="_parentSize"></param>
		/// <returns></returns>
		static float calculateAlignItemsOffset(const AlignItemsProperty& _alignItems, float _elementSize, float _parentSize);
	};
}