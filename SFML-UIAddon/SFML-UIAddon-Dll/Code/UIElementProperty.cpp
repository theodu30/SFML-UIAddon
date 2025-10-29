#include "Headers/SFUIL/System/UIElementProperty.hpp"

namespace sfui
{
	float UIPropUtils::resolveValueToPixels(const PositionValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case PositionValueTypeProperty::Pixels:
			return _prop.value;
		case PositionValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		case PositionValueTypeProperty::Auto:
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const SizeValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case SizeValueTypeProperty::Pixels:
			return _prop.value;
		case SizeValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		case SizeValueTypeProperty::Auto:
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const MinSizeValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case MinSizeValueTypeProperty::Pixels:
			return _prop.value;
		case MinSizeValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		case MinSizeValueTypeProperty::Auto:
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const MaxSizeValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case MaxSizeValueTypeProperty::Pixels:
			return _prop.value;
		case MaxSizeValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		case MaxSizeValueTypeProperty::None:
		default:
			return _relativeTo;
		}

		// Fail safe
		return _relativeTo;
	}

	float UIPropUtils::resolveValueToPixels(const MarginValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case MarginValueTypeProperty::Pixels:
			return _prop.value;
		case MarginValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		case MarginValueTypeProperty::Auto:
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const PaddingValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case PaddingValueTypeProperty::Pixels:
			return _prop.value;
		case PaddingValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		case PaddingValueTypeProperty::Auto:
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const BorderWidthValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case BorderWidthValueTypeProperty::Pixels:
			return _prop.value;
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const BorderRadiusValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case BorderRadiusValueTypeProperty::Pixels:
			return _prop.value;
		case BorderRadiusValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const TransformOriginValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case TransformOriginValueTypeProperty::Pixels:
			return _prop.value;
		case TransformOriginValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const TransformTranslateValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case TransformTranslateValueTypeProperty::Pixels:
			return _prop.value;
		case TransformTranslateValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveValueToPixels(const FlexBasicValueProperty& _prop, float _relativeTo)
	{
		switch (_prop.type)
		{
		case FlexBasicValueTypeProperty::Pixels:
			return _prop.value;
		case FlexBasicValueTypeProperty::Percentage:
			return (_relativeTo * (_prop.value / 100.f));
		case FlexBasicValueTypeProperty::Auto:
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	float UIPropUtils::resolveAngleToDegrees(const TransformRotateValueProperty& _prop)
	{
		switch (_prop.type)
		{
		case TransformRotateValueTypeProperty::Degrees:
			return _prop.value;
		case TransformRotateValueTypeProperty::Radians:
			return (_prop.value * (180.f / 3.14159265f));
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	bool UIPropUtils::isFlexDirectionRowType(const FlexProperty& _flex)
	{
		switch (_flex.flexDirection)
		{
		case FlexDirectionProperty::Row:
		case FlexDirectionProperty::RowReverse:
			return true;
		case FlexDirectionProperty::Column:
		case FlexDirectionProperty::ColumnReverse:
			return false;
		}

		// Fail safe
		return false;
	}

	bool UIPropUtils::isFlexDirectionColumnType(const FlexProperty& _flex)
	{
		switch (_flex.flexDirection)
		{
		case FlexDirectionProperty::Column:
		case FlexDirectionProperty::ColumnReverse:
			return true;
		case FlexDirectionProperty::Row:
		case FlexDirectionProperty::RowReverse:
			return false;
		}

		// Fail safe
		return false;
	}

	bool UIPropUtils::isFlexDirectionReverseType(const FlexProperty& _flex)
	{
		switch (_flex.flexDirection)
		{
		case FlexDirectionProperty::ColumnReverse:
		case FlexDirectionProperty::RowReverse:
			return true;
		case FlexDirectionProperty::Column:
		case FlexDirectionProperty::Row:
			return false;
		}

		// Fail safe
		return false;
	}

	float UIPropUtils::clampFloat(float _value, float _min, float _max)
	{
		if (_value < _min)
			return _min;
		if (_value > _max)
			return _max;
		return _value;
	}

	unsigned int UIPropUtils::clampUnsignedInt(unsigned int _value, unsigned int _min, unsigned int _max)
	{
		if (_value < _min)
			return _min;
		if (_value > _max)
			return _max;
		return _value;
	}
}
