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

	float UIPropUtils::resolveAngleToRadians(const TransformRotateValueProperty& _prop)
	{
		switch (_prop.type)
		{
		case TransformRotateValueTypeProperty::Degrees:
			return (_prop.value * (3.14159265f / 180.f));
		case TransformRotateValueTypeProperty::Radians:
			return _prop.value;
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}

	sf::Angle UIPropUtils::resolveAngleToSfAngle(const TransformRotateValueProperty& _prop)
	{
		switch (_prop.type)
		{
		case TransformRotateValueTypeProperty::Degrees:
			return sf::degrees(_prop.value);
		case TransformRotateValueTypeProperty::Radians:
			return sf::radians(_prop.value);
		default:
			return sf::degrees(0.f);
		}

		// Fail safe
		return sf::degrees(0.f);
	}

	bool UIPropUtils::isFlexDirectionRowType(const FlexProperty& _flex)
	{
		return (_flex.flexDirection == FlexDirectionProperty::Row || _flex.flexDirection == FlexDirectionProperty::RowReverse);
	}

	bool UIPropUtils::isFlexDirectionColumnType(const FlexProperty& _flex)
	{
		return (_flex.flexDirection == FlexDirectionProperty::Column || _flex.flexDirection == FlexDirectionProperty::ColumnReverse);
	}

	bool UIPropUtils::isFlexDirectionReverseType(const FlexProperty& _flex)
	{
		return (_flex.flexDirection == FlexDirectionProperty::RowReverse || _flex.flexDirection == FlexDirectionProperty::ColumnReverse);
	}

	bool UIPropUtils::isPositionAbsolute(const PositionProperty& _position)
	{
		return _position.mode == PositionModeProperty::Absolute;
	}

	bool UIPropUtils::isPositionRelative(const PositionProperty& _position)
	{
		return _position.mode == PositionModeProperty::Relative;
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

	float UIPropUtils::calculateJustifyContentOffset(const JustifyContentProperty& _justifyContent, size_t _siblingIndex, size_t _siblingCount, float _elementSize, float _parentSize)
	{
		switch (_justifyContent)
		{
		case JustifyContentProperty::FlexStart:
			return static_cast<float>(_siblingIndex) * _elementSize;
		case JustifyContentProperty::Center:
			return ((_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / 2.f) + (static_cast<float>(_siblingIndex) * _elementSize);
		case JustifyContentProperty::FlexEnd:
			return _parentSize - (_elementSize * static_cast<float>(_siblingCount - _siblingIndex));
		case JustifyContentProperty::SpaceBetween:
			if (_siblingCount > 1)
			{
				float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount - 1);
				return (static_cast<float>(_siblingIndex) * (_elementSize + space));
			}
			else
			{
				return 0.f;
			}
		case JustifyContentProperty::SpaceAround:
			{
				float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount);
				return (space / 2.f) + (static_cast<float>(_siblingIndex) * (_elementSize + space));
			}
		case JustifyContentProperty::SpaceEvenly:
			{
				float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount + 1);
				return space + (static_cast<float>(_siblingIndex) * (_elementSize + space));
			}
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}
	float UIPropUtils::calculateAlignItemsOffset(const AlignItemsProperty& _alignItems, float _elementSize, float _parentSize)
	{
		switch (_alignItems)
		{
		case AlignItemsProperty::FlexStart:
			return 0.f;
		case AlignItemsProperty::Center:
			return (_parentSize - _elementSize) / 2.f;
		case AlignItemsProperty::FlexEnd:
			return _parentSize - _elementSize;
		case AlignItemsProperty::Stretch:
			return 0.f; // Stretch is handled differently, so we return 0 offset here
		default:
			return 0.0f;
		}

		// Fail safe
		return 0.0f;
	}
}
