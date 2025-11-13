#include "Headers/SFUIL/System/UIElementProperty.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

namespace sfui
{
	const float& OpacityProperty::getOpacity() const
	{
		return m_opacity;
	}

	void OpacityProperty::setOpacity(float _opacity)
	{
		// Clamp the value between 0.0f and 1.0f
		m_opacity = UIPropUtils::clampFloat(_opacity, 0.0f, 1.0f);
	}

	DisplayProperty::Type DisplayProperty::getDisplay() const
	{
		return m_display;
	}

	void DisplayProperty::setDisplay(Type _type)
	{
		m_display = _type;
	}

	VisibilityProperty::Type VisibilityProperty::getVisibility() const
	{
		return Type();
	}

	void VisibilityProperty::setVisibility(Type _type)
	{
		m_visibility = _type;
	}

	PositionProperty::Mode PositionProperty::getMode() const
	{
		return m_mode;
	}

	void PositionProperty::setMode(Mode _mode)
	{
		m_mode = _mode;
	}

	float PositionProperty::Value::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case ValueType::Auto:
			return 0.f;
		case ValueType::Pixels:
			return value;
		case ValueType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const PositionProperty::Value& PositionProperty::getTop() const
	{
		return m_top;
	}

	void PositionProperty::setTop(const Value& _value)
	{
		m_top = _value;
	}

	void PositionProperty::setTop(float _value, ValueType _type)
	{
		m_top.value = _value;
		m_top.type = _type;
	}

	void PositionProperty::setTop(float _value)
	{
		m_top.value = _value;
	}

	const PositionProperty::Value& PositionProperty::getRight() const
	{
		return m_right;
	}

	void PositionProperty::setRight(const Value& _value)
	{
		m_right = _value;
	}

	void PositionProperty::setRight(float _value, ValueType _type)
	{
		m_right.value = _value;
		m_right.type = _type;
	}

	void PositionProperty::setRight(float _value)
	{
		m_right.value = _value;
	}

	const PositionProperty::Value& PositionProperty::getBottom() const
	{
		return m_bottom;
	}

	void PositionProperty::setBottom(const Value& _value)
	{
		m_bottom = _value;
	}

	void PositionProperty::setBottom(float _value, ValueType _type)
	{
		m_bottom.value = _value;
		m_bottom.type = _type;
	}

	void PositionProperty::setBottom(float _value)
	{
		m_bottom.value = _value;
	}

	const PositionProperty::Value& PositionProperty::getLeft() const
	{
		return m_left;
	}

	void PositionProperty::setLeft(const Value& _value)
	{
		m_left = _value;
	}

	void PositionProperty::setLeft(float _value, ValueType _type)
	{
		m_left.value = _value;
		m_left.type = _type;
	}

	void PositionProperty::setLeft(float _value)
	{
		m_left.value = _value;
	}

	float FlexProperty::Basic::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case BasicType::Auto:
			return 0.f;
		case BasicType::Pixels:
			return value;
		case BasicType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const FlexProperty::Basic& FlexProperty::getFlexBasic() const
	{
		return m_flexBasis;
	}

	void FlexProperty::setFlexBasic(const Basic& _value)
	{
		m_flexBasis = _value;
	}

	void FlexProperty::setFlexBasic(float _value, BasicType _type)
	{
		m_flexBasis.value = _value;
		m_flexBasis.type = _type;
	}

	void FlexProperty::setFlexBasic(float _value)
	{
		m_flexBasis.value = _value;
	}

	const float& FlexProperty::getFlexShrink() const
	{
		return m_flexShrink;
	}

	void FlexProperty::setFlexShrink(float _value)
	{
		m_flexShrink = _value;
	}

	const float& FlexProperty::getFlexGrow() const
	{
		return m_flexGrow;
	}

	void FlexProperty::setFlexGrow(float _value)
	{
		m_flexGrow = _value;
	}

	FlexProperty::Direction FlexProperty::getFlexDirection() const
	{
		return m_flexDirection;
	}

	void FlexProperty::setFlexDirection(Direction _direction)
	{
		m_flexDirection = _direction;
	}

	FlexProperty::Warp FlexProperty::getFlexWrap() const
	{
		return m_flexWrap;
	}

	void FlexProperty::setFlexWrap(Warp _warp)
	{
		m_flexWrap = _warp;
	}

	AlignProperty::AlignItems AlignProperty::getAlignItems() const
	{
		return m_alignItems;
	}

	void AlignProperty::setAlignItems(AlignItems _alignItems)
	{
		m_alignItems = _alignItems;
	}

	AlignProperty::JustifyContent AlignProperty::getJustifyContent() const
	{
		return m_justifyContent;
	}

	void AlignProperty::setJustifyContent(JustifyContent _justifyContent)
	{
		m_justifyContent = _justifyContent;
	}

	AlignProperty::AlignSelf AlignProperty::getAlignSelf() const
	{
		return m_alignSelf;
	}

	void AlignProperty::setAlignSelf(AlignSelf _alignSelf)
	{
		m_alignSelf = _alignSelf;
	}

	AlignProperty::AlignContent AlignProperty::getAlignContent() const
	{
		return m_alignContent;
	}

	void AlignProperty::setAlignContent(AlignContent _alignContent)
	{
		m_alignContent = _alignContent;
	}

	float SizeProperty::SizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case SizeType::Auto:
			return 0.f;
		case SizeType::Pixels:
			return value;
		case SizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SizeProperty::Size& SizeProperty::getSize() const
	{
		return m_size;
	}

	void SizeProperty::setSize(const Size& _size)
	{
		m_size = _size;
	}

	void SizeProperty::setWidth(float _value, SizeType _type)
	{
		m_size.width.value = _value;
		m_size.width.type = _type;
	}

	void SizeProperty::setWidth(float _value)
	{
		m_size.width.value = _value;
	}

	void SizeProperty::setHeight(float _value, SizeType _type)
	{
		m_size.height.value = _value;
		m_size.height.type = _type;
	}

	void SizeProperty::setHeight(float _value)
	{
		m_size.height.value = _value;
	}

	float SizeProperty::MinSizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MinSizeType::Auto:
			return 0.f;
		case MinSizeType::Pixels:
			return value;
		case MinSizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SizeProperty::MinSize& SizeProperty::getMinSize() const
	{
		return m_minSize;
	}

	void SizeProperty::setMinSize(const MinSize& _minSize)
	{
		m_minSize = _minSize;
	}

	void SizeProperty::setMinWidth(float _value, MinSizeType _type)
	{
		m_minSize.width.value = _value;
		m_minSize.width.type = _type;
	}

	void SizeProperty::setMinWidth(float _value)
	{
		m_minSize.width.value = _value;
	}

	void SizeProperty::setMinHeight(float _value, MinSizeType _type)
	{
		m_minSize.height.value = _value;
		m_minSize.height.type = _type;
	}

	void SizeProperty::setMinHeight(float _value)
	{
		m_minSize.height.value = _value;
	}

	float SizeProperty::MaxSizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MaxSizeType::None:
			return _relativeTo;
		case MaxSizeType::Pixels:
			return value;
		case MaxSizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return _relativeTo;
		}
	}

	const SizeProperty::MaxSize& SizeProperty::getMaxSize() const
	{
		return m_maxSize;
	}

	void SizeProperty::setMaxSize(const MaxSize& _maxSize)
	{
		m_maxSize = _maxSize;
	}

	void SizeProperty::setMaxWidth(float _value, MaxSizeType _type)
	{
		m_maxSize.width.value = _value;
		m_maxSize.width.type = _type;
	}

	void SizeProperty::setMaxWidth(float _value)
	{
		m_maxSize.width.value = _value;
	}

	void SizeProperty::setMaxHeight(float _value, MaxSizeType _type)
	{
		m_maxSize.height.value = _value;
		m_maxSize.height.type = _type;
	}

	void SizeProperty::setMaxHeight(float _value)
	{
		m_maxSize.height.value = _value;
	}

	float SpacingProperty::MarginValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MarginType::Auto:
			return 0.f;
		case MarginType::Pixels:
			return value;
		case MarginType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginTop() const
	{
		return m_marginTop;
	}

	void SpacingProperty::setMarginTop(const MarginValue& _value)
	{
		m_marginTop = _value;
	}

	void SpacingProperty::setMarginTop(float _value, MarginType _type)
	{
		m_marginTop.value = _value;
		m_marginTop.type = _type;
	}

	void SpacingProperty::setMarginTop(float _value)
	{
		m_marginTop.value = _value;
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginRight() const
	{
		return m_marginRight;
	}

	void SpacingProperty::setMarginRight(const MarginValue& _value)
	{
		m_marginRight = _value;
	}

	void SpacingProperty::setMarginRight(float _value, MarginType _type)
	{
		m_marginRight.value = _value;
		m_marginRight.type = _type;
	}

	void SpacingProperty::setMarginRight(float _value)
	{
		m_marginRight.value = _value;
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginBottom() const
	{
		return m_marginBottom;
	}

	void SpacingProperty::setMarginBottom(const MarginValue& _value)
	{
		m_marginBottom = _value;
	}

	void SpacingProperty::setMarginBottom(float _value, MarginType _type)
	{
		m_marginBottom.value = _value;
		m_marginBottom.type = _type;
	}

	void SpacingProperty::setMarginBottom(float _value)
	{
		m_marginBottom.value = _value;
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginLeft() const
	{
		return m_marginLeft;
	}

	void SpacingProperty::setMarginLeft(const MarginValue& _value)
	{
		m_marginLeft = _value;
	}

	void SpacingProperty::setMarginLeft(float _value, MarginType _type)
	{
		m_marginLeft.value = _value;
		m_marginLeft.type = _type;
	}

	void SpacingProperty::setMarginLeft(float _value)
	{
		m_marginLeft.value = _value;
	}

	float SpacingProperty::PaddingValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case PaddingType::Auto:
			return 0.f;
		case PaddingType::Pixels:
			return value;
		case PaddingType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingTop() const
	{
		return m_paddingTop;
	}

	void SpacingProperty::setPaddingTop(const PaddingValue& _value)
	{
		m_paddingTop = _value;
	}

	void SpacingProperty::setPaddingTop(float _value, PaddingType _type)
	{
		m_paddingTop.value = _value;
		m_paddingTop.type = _type;
	}

	void SpacingProperty::setPaddingTop(float _value)
	{
		m_paddingTop.value = _value;
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingRight() const
	{
		return m_paddingRight;
	}

	void SpacingProperty::setPaddingRight(const PaddingValue& _value)
	{
		m_paddingRight = _value;
	}

	void SpacingProperty::setPaddingRight(float _value, PaddingType _type)
	{
		m_paddingRight.value = _value;
		m_paddingRight.type = _type;
	}

	void SpacingProperty::setPaddingRight(float _value)
	{
		m_paddingRight.value = _value;
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingBottom() const
	{
		return m_paddingBottom;
	}

	void SpacingProperty::setPaddingBottom(const PaddingValue& _value)
	{
		m_paddingBottom = _value;
	}

	void SpacingProperty::setPaddingBottom(float _value, PaddingType _type)
	{
		m_paddingBottom.value = _value;
		m_paddingBottom.type = _type;
	}

	void SpacingProperty::setPaddingBottom(float _value)
	{
		m_paddingBottom.value = _value;
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingLeft() const
	{
		return m_paddingLeft;
	}

	void SpacingProperty::setPaddingLeft(const PaddingValue& _value)
	{
		m_paddingLeft = _value;
	}

	void SpacingProperty::setPaddingLeft(float _value, PaddingType _type)
	{
		m_paddingLeft.value = _value;
		m_paddingLeft.type = _type;
	}

	void SpacingProperty::setPaddingLeft(float _value)
	{
		m_paddingLeft.value = _value;
	}

	const sf::Color& BackgroundProperty::getColor() const
	{
		return m_color;
	}

	void BackgroundProperty::setColor(const sf::Color& _color)
	{
		m_color = _color;
	}

	void BackgroundProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_color.r = _r;
		m_color.g = _g;
		m_color.b = _b;
		m_color.a = _a;
	}

	const sf::Color& BorderProperty::getColor() const
	{
		return m_color;
	}

	void BorderProperty::setColor(const sf::Color& _color)
	{
		m_color = _color;
	}

	void BorderProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_color.r = _r;
		m_color.g = _g;
		m_color.b = _b;
		m_color.a = _a;
	}

	const float& BorderProperty::getWidth() const
	{
		return m_width;
	}

	void BorderProperty::setWidth(float _width)
	{
		m_width = _width;
	}

	const float& BorderProperty::getRadius() const
	{
		return m_radius;
	}

	void BorderProperty::setRadius(float _radius)
	{
		m_radius = _radius;
	}

	float TransformProperty::OriginValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case OriginType::Pixels:
			return value;
		case OriginType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const TransformProperty::Origin& TransformProperty::getOrigin() const
	{
		return m_origin;
	}

	void TransformProperty::setOrigin(const Origin& _origin)
	{
		m_origin = _origin;
	}

	void TransformProperty::setOriginX(float _value, OriginType _type)
	{
		m_origin.x.value = _value;
		m_origin.x.type = _type;
	}

	void TransformProperty::setOriginX(float _value)
	{
		m_origin.x.value = _value;
	}

	void TransformProperty::setOriginY(float _value, OriginType _type)
	{
		m_origin.y.value = _value;
		m_origin.y.type = _type;
	}

	void TransformProperty::setOriginY(float _value)
	{
		m_origin.y.value = _value;
	}

	float TransformProperty::TranslateValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case TranslateType::Pixels:
			return value;
		case TranslateType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const TransformProperty::Translate& TransformProperty::getTranslate() const
	{
		return m_translate;
	}

	void TransformProperty::setTranslate(const Translate& _translate)
	{
		m_translate = _translate;
	}

	void TransformProperty::setTranslateX(float _value, TranslateType _type)
	{
		m_translate.x.value = _value;
		m_translate.x.type = _type;
	}

	void TransformProperty::setTranslateX(float _value)
	{
		m_translate.x.value = _value;
	}

	void TransformProperty::setTranslateY(float _value, TranslateType _type)
	{
		m_translate.y.value = _value;
		m_translate.y.type = _type;
	}

	void TransformProperty::setTranslateY(float _value)
	{
		m_translate.y.value = _value;
	}

	const TransformProperty::Scale& TransformProperty::getScale() const
	{
		return m_scale;
	}

	void TransformProperty::setScale(const Scale& _scale)
	{
		m_scale = _scale;
	}

	void TransformProperty::setScaleX(float _value)
	{
		m_scale.x = _value;
	}

	void TransformProperty::setScaleY(float _value)
	{
		m_scale.y = _value;
	}

	float TransformProperty::Rotate::resolveToDegrees() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return value;
		case RotateType::Radians:
			return value * (180.f / static_cast<float>(M_PI));
		default:
			return 0.f;
		}
	}

	float TransformProperty::Rotate::resolveToRadians() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return value * (static_cast<float>(M_PI) / 180.f);
		case RotateType::Radians:
			return value;
		default:
			return 0.f;
		}
	}

	sf::Angle TransformProperty::Rotate::resolveToSfAngle() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return sf::degrees(value);
		case RotateType::Radians:
			return sf::radians(value);
		default:
			return sf::degrees(0.f);
		}
	}

	const TransformProperty::Rotate& TransformProperty::getRotate() const
	{
		return m_rotate;
	}

	void TransformProperty::setRotate(const Rotate& _rotate)
	{
		m_rotate = _rotate;
	}

	void TransformProperty::setRotate(float _value, RotateType _type)
	{
		m_rotate.value = _value;
		m_rotate.type = _type;
	}

	void TransformProperty::setRotate(float _value)
	{
		m_rotate.value = _value;
	}

	void UIPropUtils::normalizeAngle(TransformProperty& _prop)
	{
		_prop.setRotate(normalizedAngle(_prop.getRotate()));
	}

	TransformProperty::Rotate UIPropUtils::normalizedAngle(const TransformProperty::Rotate& _rotate)
	{
		switch (_rotate.type)
		{
			case TransformProperty::RotateType::Degrees:
			{
				float degrees = std::fmod(_rotate.value, 360.f);
				if (degrees > 180.f)
					degrees -= 360.f;
				else if (degrees < -180.f)
					degrees += 360.f;
				return TransformProperty::Rotate{ degrees, TransformProperty::RotateType::Degrees };
			}
			case TransformProperty::RotateType::Radians:
			{
				const float twoPi = static_cast<float>(2 * M_PI);
				float radians = std::fmod(_rotate.value, twoPi);
				if (radians > static_cast<float>(M_PI))
					radians -= twoPi;
				else if (radians < -static_cast<float>(M_PI))
					radians += twoPi;
				return TransformProperty::Rotate{ radians, TransformProperty::RotateType::Radians };
			}
			default:
				return _rotate;
		}
	}

	bool UIPropUtils::isFlexDirectionRowType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::Row ||
			_flex.getFlexDirection() == FlexProperty::Direction::RowReverse;
	}

	bool UIPropUtils::isFlexDirectionColumnType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::Column ||
			_flex.getFlexDirection() == FlexProperty::Direction::ColumnReverse;
	}

	bool UIPropUtils::isFlexDirectionReverseType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::RowReverse ||
			_flex.getFlexDirection() == FlexProperty::Direction::ColumnReverse;
	}

	bool UIPropUtils::isPositionAbsolute(const PositionProperty& _position)
	{
		return _position.getMode() == PositionProperty::Mode::Absolute;
	}

	bool UIPropUtils::isPositionRelative(const PositionProperty& _position)
	{
		return _position.getMode() == PositionProperty::Mode::Relative;
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

	float UIPropUtils::calculateJustifyContentOffset(const AlignProperty& _justifyContent, size_t _siblingIndex, size_t _siblingCount, float _elementSize, float _parentSize)
	{
		switch (_justifyContent.getJustifyContent())
		{
		case AlignProperty::JustifyContent::FlexStart:
			return static_cast<float>(_siblingIndex) * _elementSize;
		case AlignProperty::JustifyContent::FlexEnd:
			return _parentSize - (_elementSize * static_cast<float>(_siblingCount - _siblingIndex));
		case AlignProperty::JustifyContent::Center:
			return ((_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / 2.f) + (static_cast<float>(_siblingIndex) * _elementSize);
		case AlignProperty::JustifyContent::SpaceBetween:
			if (_siblingCount > 1)
			{
				float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount - 1);
				return (static_cast<float>(_siblingIndex) * (_elementSize + space));
			}
			else
			{
				return 0.f;
			}
		case AlignProperty::JustifyContent::SpaceAround:
		{
			float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount);
			return (space / 2.f) + (static_cast<float>(_siblingIndex) * (_elementSize + space));
		}
		case AlignProperty::JustifyContent::SpaceEvenly:
		{
			float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount + 1);
			return space + (static_cast<float>(_siblingIndex) * (_elementSize + space));
		}
		default:
			return 0.f;
		}
	}

	float UIPropUtils::calculateAlignItemsOffset(const AlignProperty& _alignItems, float _elementSize, float _parentSize)
	{
		switch (_alignItems.getAlignItems())
		{
		case AlignProperty::AlignItems::FlexStart:
			return 0.f;
		case AlignProperty::AlignItems::FlexEnd:
			return _parentSize - _elementSize;
		case AlignProperty::AlignItems::Center:
			return (_parentSize - _elementSize) / 2.f;
		case AlignProperty::AlignItems::Stretch:
			return 0.f;
		default:
			return 0.f;
		}
	}

}
