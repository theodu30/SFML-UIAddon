#pragma once

#include "Exports.hpp"
#include "Anchor.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sfui
{
	class SFUIL_API Property {};

	class SFUIL_API OpacityProperty : public Property
	{
	public:
		[[nodiscard]] const float& getOpacity() const;
		void setOpacity(float _opacity);
	private:
		float m_opacity = 1.f;
	};

	class SFUIL_API DisplayProperty : public Property
	{
	public:
		enum class Type : char
		{
			Flex,
			None
		};

		[[nodiscard]] Type getDisplay() const;
		void setDisplay(Type _type);
	private:
		Type m_display = Type::Flex;
	};

	class SFUIL_API VisibilityProperty : public Property
	{
	public:
		enum class Type : char
		{
			Visible,
			Hidden
		};
		[[nodiscard]] Type getVisibility() const;
		void setVisibility(Type _type);

	private:
		Type m_visibility = Type::Visible;
	};

	class SFUIL_API PositionProperty : public Property
	{
	public:
		enum class Mode : char
		{
			Relative,
			Absolute
		};

		[[nodiscard]] Mode getMode() const;
		void setMode(Mode _mode);

		enum class ValueType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct Value
		{
			float value = 0.f;
			ValueType type = ValueType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const Value& getTop() const;
		void setTop(const Value& _value);
		void setTop(float _value, ValueType _type);
		void setTop(float _value);

		[[nodiscard]] const Value& getRight() const;
		void setRight(const Value& _value);
		void setRight(float _value, ValueType _type);
		void setRight(float _value);

		[[nodiscard]] const Value& getBottom() const;
		void setBottom(const Value& _value);
		void setBottom(float _value, ValueType _type);
		void setBottom(float _value);

		[[nodiscard]] const Value& getLeft() const;
		void setLeft(const Value& _value);
		void setLeft(float _value, ValueType _type);
		void setLeft(float _value);

	private:
		Mode m_mode = Mode::Relative;
		Value m_top;
		Value m_right;
		Value m_bottom;
		Value m_left;
	};

	class SFUIL_API FlexProperty : public Property
	{
	public:
		enum class BasicType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct Basic
		{
			float value = 0.f;
			BasicType type = BasicType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const Basic& getFlexBasic() const;
		void setFlexBasic(const Basic& _value);
		void setFlexBasic(float _value, BasicType _type);
		void setFlexBasic(float _value);

		[[nodiscard]] const float& getFlexShrink() const;
		void setFlexShrink(float _value);

		[[nodiscard]] const float& getFlexGrow() const;
		void setFlexGrow(float _value);

		enum class Direction : char
		{
			Column,
			ColumnReverse,
			Row,
			RowReverse
		};

		[[nodiscard]] Direction getFlexDirection() const;
		void setFlexDirection(Direction _direction);

		enum class Warp : char
		{
			NoWrap,
			Wrap,
			WrapReverse
		};

		[[nodiscard]] Warp getFlexWrap() const;
		void setFlexWrap(Warp _warp);

	private:
		Basic m_flexBasis;
		float m_flexShrink = 1.f;
		float m_flexGrow = 1.f;
		Direction m_flexDirection = Direction::Column;
		Warp m_flexWrap = Warp::NoWrap;
	};

	class SFUIL_API AlignProperty : public Property
	{
	public:
		enum class AlignItems : char
		{
			Auto,
			FlexStart,
			Center,
			FlexEnd,
			Stretch
		};

		[[nodiscard]] AlignItems getAlignItems() const;
		void setAlignItems(AlignItems _alignItems);

		enum class JustifyContent : char
		{
			FlexStart,
			Center,
			FlexEnd,
			SpaceBetween,
			SpaceAround,
			SpaceEvenly
		};

		[[nodiscard]] JustifyContent getJustifyContent() const;
		void setJustifyContent(JustifyContent _justifyContent);

		enum class AlignSelf : char
		{
			Auto,
			FlexStart,
			Center,
			FlexEnd,
			Stretch
		};

		[[nodiscard]] AlignSelf getAlignSelf() const;
		void setAlignSelf(AlignSelf _alignSelf);

		enum class AlignContent : char
		{
			Auto,
			FlexStart,
			Center,
			FlexEnd,
			Stretch
		};

		[[nodiscard]] AlignContent getAlignContent() const;
		void setAlignContent(AlignContent _alignContent);

	private:
		AlignItems m_alignItems = AlignItems::Stretch;
		JustifyContent m_justifyContent = JustifyContent::FlexStart;
		AlignSelf m_alignSelf = AlignSelf::Auto;
		AlignContent m_alignContent = AlignContent::FlexStart;
	};

	class SFUIL_API SizeProperty : public Property
	{
	public:
		enum class SizeType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct SizeValue
		{
			float value = 0.f;
			SizeType type = SizeType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		struct Size
		{
			SizeValue width;
			SizeValue height;
		};

		[[nodiscard]] const Size& getSize() const;
		void setSize(const Size& _size);
		void setWidth(float _value, SizeType _type);
		void setWidth(float _value);
		void setHeight(float _value, SizeType _type);
		void setHeight(float _value);

		enum class MinSizeType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct MinSizeValue
		{
			float value = 0.f;
			MinSizeType type = MinSizeType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		struct MinSize
		{
			MinSizeValue width;
			MinSizeValue height;
		};

		[[nodiscard]] const MinSize& getMinSize() const;
		void setMinSize(const MinSize& _minSize);
		void setMinWidth(float _value, MinSizeType _type);
		void setMinWidth(float _value);
		void setMinHeight(float _value, MinSizeType _type);
		void setMinHeight(float _value);

		enum class MaxSizeType : char
		{
			None,
			Pixels,
			Percentage
		};

		struct MaxSizeValue
		{
			float value = 0.f;
			MaxSizeType type = MaxSizeType::None;

			float resolveToPixels(float _relativeTo) const;
		};

		struct MaxSize
		{
			MaxSizeValue width;
			MaxSizeValue height;
		};

		[[nodiscard]] const MaxSize& getMaxSize() const;
		void setMaxSize(const MaxSize& _maxSize);
		void setMaxWidth(float _value, MaxSizeType _type);
		void setMaxWidth(float _value);
		void setMaxHeight(float _value, MaxSizeType _type);
		void setMaxHeight(float _value);

	private:
		Size m_size;
		MinSize m_minSize;
		MaxSize m_maxSize;
	};

	class SFUIL_API SpacingProperty : public Property
	{
	public:
		enum class MarginType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct MarginValue
		{
			float value = 0.f;
			MarginType type = MarginType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const MarginValue& getMarginTop() const;
		void setMarginTop(const MarginValue& _value);
		void setMarginTop(float _value, MarginType _type);
		void setMarginTop(float _value);

		[[nodiscard]] const MarginValue& getMarginRight() const;
		void setMarginRight(const MarginValue& _value);
		void setMarginRight(float _value, MarginType _type);
		void setMarginRight(float _value);

		[[nodiscard]] const MarginValue& getMarginBottom() const;
		void setMarginBottom(const MarginValue& _value);
		void setMarginBottom(float _value, MarginType _type);
		void setMarginBottom(float _value);

		[[nodiscard]] const MarginValue& getMarginLeft() const;
		void setMarginLeft(const MarginValue& _value);
		void setMarginLeft(float _value, MarginType _type);
		void setMarginLeft(float _value);

		enum class PaddingType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct PaddingValue
		{
			float value = 0.f;
			PaddingType type = PaddingType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const PaddingValue& getPaddingTop() const;
		void setPaddingTop(const PaddingValue& _value);
		void setPaddingTop(float _value, PaddingType _type);
		void setPaddingTop(float _value);

		[[nodiscard]] const PaddingValue& getPaddingRight() const;
		void setPaddingRight(const PaddingValue& _value);
		void setPaddingRight(float _value, PaddingType _type);
		void setPaddingRight(float _value);

		[[nodiscard]] const PaddingValue& getPaddingBottom() const;
		void setPaddingBottom(const PaddingValue& _value);
		void setPaddingBottom(float _value, PaddingType _type);
		void setPaddingBottom(float _value);

		[[nodiscard]] const PaddingValue& getPaddingLeft() const;
		void setPaddingLeft(const PaddingValue& _value);
		void setPaddingLeft(float _value, PaddingType _type);
		void setPaddingLeft(float _value);

	private:
		MarginValue m_marginTop;
		MarginValue m_marginRight;
		MarginValue m_marginBottom;
		MarginValue m_marginLeft;
		PaddingValue m_paddingTop;
		PaddingValue m_paddingRight;
		PaddingValue m_paddingBottom;
		PaddingValue m_paddingLeft;
	};

	class SFUIL_API BackgroundProperty : public Property
	{
	public:
		[[nodiscard]] const sf::Color& getColor() const;
		void setColor(const sf::Color& _color);
		void setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a = 255);

	private:
		sf::Color m_color = sf::Color::Transparent;
	};

	class SFUIL_API BorderProperty : public Property
	{
	public:
		[[nodiscard]] const sf::Color& getColor() const;
		void setColor(const sf::Color& _color);
		void setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a = 255);

		[[nodiscard]] const float& getWidth() const;
		void setWidth(float _width);

		[[nodiscard]] const float& getRadius() const;
		void setRadius(float _radius);

	private:
		sf::Color m_color = sf::Color::Black;
		float m_width = 0.f;
		float m_radius = 0.f;
	};

	class SFUIL_API TransformProperty : public Property
	{
	public:
		enum class OriginType : char
		{
			Pixels,
			Percentage
		};

		struct OriginValue
		{
			float value = 0.f;
			OriginType type = OriginType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		struct Origin
		{
			OriginValue x;
			OriginValue y;
		};

		[[nodiscard]] const Origin& getOrigin() const;
		void setOrigin(const Origin& _origin);
		void setOriginX(float _value, OriginType _type);
		void setOriginX(float _value);
		void setOriginY(float _value, OriginType _type);
		void setOriginY(float _value);

		enum class TranslateType : char
		{
			Pixels,
			Percentage
		};

		struct TranslateValue
		{
			float value = 0.f;
			TranslateType type = TranslateType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		struct Translate
		{
			TranslateValue x;
			TranslateValue y;
		};

		[[nodiscard]] const Translate& getTranslate() const;
		void setTranslate(const Translate& _translate);
		void setTranslateX(float _value, TranslateType _type);
		void setTranslateX(float _value);
		void setTranslateY(float _value, TranslateType _type);
		void setTranslateY(float _value);

		struct Scale
		{
			float x = 1.f;
			float y = 1.f;
		};

		[[nodiscard]] const Scale& getScale() const;;
		void setScale(const Scale& _scale);
		void setScaleX(float _value);
		void setScaleY(float _value);

		enum class RotateType : char
		{
			Degrees,
			Radians
		};

		struct Rotate
		{
			float value = 0.f;
			RotateType type = RotateType::Degrees;

			float resolveToDegrees() const;
			float resolveToRadians() const;
			sf::Angle resolveToSfAngle() const;
		};

		[[nodiscard]] const Rotate& getRotate() const;
		void setRotate(const Rotate& _rotate);
		void setRotate(float _value, RotateType _type);
		void setRotate(float _value);

	private:
		Origin m_origin;
		Translate m_translate;
		Scale m_scale;
		Rotate m_rotate;
	};

	class SFUIL_API UIPropUtils
	{
	public:
		static void normalizeAngle(TransformProperty& _prop);

		static TransformProperty::Rotate normalizedAngle(const TransformProperty::Rotate& _rotate);

		static bool isFlexDirectionRowType(const FlexProperty& _flex);

		static bool isFlexDirectionColumnType(const FlexProperty& _flex);

		static bool isFlexDirectionReverseType(const FlexProperty& _flex);

		static bool isPositionAbsolute(const PositionProperty& _position);

		static bool isPositionRelative(const PositionProperty& _position);

		static float clampFloat(float _value, float _min, float _max);

		static unsigned int clampUnsignedInt(unsigned int _value, unsigned int _min, unsigned int _max);

		static float calculateJustifyContentOffset(const AlignProperty& _justifyContent, size_t _siblingIndex, size_t _siblingCount, float _elementSize, float _parentSize);

		static float calculateAlignItemsOffset(const AlignProperty& _alignItems, float _elementSize, float _parentSize);
	};
}