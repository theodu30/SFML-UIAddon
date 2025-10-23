#pragma once

#include "Exports.hpp"
#include "Anchor.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sfui
{
	struct SFUIL_API OpacityProperty
	{
		float value = 1.0f; // Opacity value between 0.0 (transparent) and 1.0 (opaque)
	};

	enum class SFUIL_API DisplayProperty : char
	{
		Flex,
		None
	};

	enum class SFUIL_API VisibilityProperty : char
	{
		Visible,
		Hidden
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
		int value = 0; // The value for the position
		PositionValueTypeProperty type = PositionValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API PositionProperty
	{
		PositionValueProperty top;
		PositionValueProperty right;
		PositionValueProperty bottom;
		PositionValueProperty left;
	};

	struct SFUIL_API FlexShrinkProperty
	{
		float value = 1.0f; // The flex shrink factor
	};

	struct SFUIL_API FlexGrowProperty
	{
		float value = 0.0f; // The flex grow factor
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
		int value = 0; // The value for the width
		SizeValueTypeProperty type = SizeValueTypeProperty::Auto; // The type of the value
	};

	struct SFUIL_API MinSizeValueProperty
	{
		int value = 0; // The value for the width
		MinSizeValueTypeProperty type = MinSizeValueTypeProperty::Auto; // The type of the value
	};

	struct SFUIL_API MaxSizeValueProperty
	{
		int value = 0; // The value for the width
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
		int value = 0; // The value for the margin
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
		int value = 0; // The value for the padding
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
		int value = 0; // The value for the border width
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
		int value = 0; // The value for the border radius
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
		int value = 0; // The value for the transform origin
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
		int value = 0; // The value for the transform translate
		TransformTranslateValueTypeProperty type = TransformTranslateValueTypeProperty::Pixels; // The type of the value
	};

	struct SFUIL_API TransformTranslateProperty
	{
		TransformTranslateValueProperty x;
		TransformTranslateValueProperty y;
	};

	struct SFUIL_API TransformScaleValueProperty
	{
		float value = 1.0f; // The value for the transform scale
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
		float value = 0.0f; // The value for the transform rotate
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
}