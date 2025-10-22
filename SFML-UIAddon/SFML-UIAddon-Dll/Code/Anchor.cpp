#include "Headers/SFUIL/System/Anchor.hpp"

namespace sfui
{
	inline constexpr Alignment Alignment::UpperLeft = Alignment(HorizontalAlignment::Left, VerticalAlignment::Upper);
	inline constexpr Alignment Alignment::MiddleLeft = Alignment(HorizontalAlignment::Left, VerticalAlignment::Middle);
	inline constexpr Alignment Alignment::LowerLeft = Alignment(HorizontalAlignment::Left, VerticalAlignment::Lower);
	inline constexpr Alignment Alignment::UpperCenter = Alignment(HorizontalAlignment::Center, VerticalAlignment::Upper);
	inline constexpr Alignment Alignment::MiddleCenter = Alignment(HorizontalAlignment::Center, VerticalAlignment::Middle);
	inline constexpr Alignment Alignment::LowerCenter = Alignment(HorizontalAlignment::Center, VerticalAlignment::Lower);
	inline constexpr Alignment Alignment::UpperRight = Alignment(HorizontalAlignment::Right, VerticalAlignment::Upper);
	inline constexpr Alignment Alignment::MiddleRight = Alignment(HorizontalAlignment::Right, VerticalAlignment::Middle);
	inline constexpr Alignment Alignment::LowerRight = Alignment(HorizontalAlignment::Right, VerticalAlignment::Lower);

	constexpr Alignment::Alignment(HorizontalAlignment _alignX, VerticalAlignment _alignY)
	{
		alignX = _alignX;
		alignY = _alignY;
	}

	Alignment::Alignment(const Alignment& _other)
	{
		alignX = _other.alignX;
		alignY = _other.alignY;
	}

	Alignment& Alignment::operator=(const Alignment& _other)
	{
		if (this != &_other)
		{
			alignX = _other.alignX;
			alignY = _other.alignY;
		}
		return *this;
	}

	Alignment::Alignment(Alignment&& _other) noexcept
	{
		alignX = _other.alignX;
		alignY = _other.alignY;

		_other.alignX = HorizontalAlignment::Left;
		_other.alignY = VerticalAlignment::Upper;
	}

	Alignment& Alignment::operator=(Alignment&& _other) noexcept
	{
		if (this != &_other)
		{
			alignX = _other.alignX;
			alignY = _other.alignY;
			_other.alignX = HorizontalAlignment::Left;
			_other.alignY = VerticalAlignment::Upper;
		}
		return *this;
	}

	HorizontalAlignment Alignment::getHorizontalAlignment() const noexcept
	{
		return alignX;
	}

	VerticalAlignment Alignment::getVerticalAlignment() const noexcept
	{
		return alignY;
	}

	constexpr bool Alignment::operator==(const Alignment& _other) const
	{
		return (alignX == _other.alignX) && (alignY == _other.alignY);
	}

	const sf::Vector2u Anchor::getAnchoredPosition(
		const sf::Vector2u& _parentSize,
		const sf::Vector2u& _elementSize,
		const Alignment& _alignment,
		const sf::Vector2i& _offset)
	{
		// Initial Position
		int posX = 0;
		int posY = 0;

		// Horizontal Alignment
		switch (_alignment.getHorizontalAlignment())
		{
		case HorizontalAlignment::Left:
			posX = 0;
			break;
		case HorizontalAlignment::Center:
			posX = static_cast<int>(_parentSize.x / 2) - static_cast<int>(_elementSize.x / 2);
			break;
		case HorizontalAlignment::Right:
			posX = static_cast<int>(_parentSize.x) - static_cast<int>(_elementSize.x);
			break;
		}

		// Vertical Alignment
		switch (_alignment.getVerticalAlignment())
		{
		case VerticalAlignment::Upper:
			posY = 0;
			break;
		case VerticalAlignment::Middle:
			posY = static_cast<int>(_parentSize.y / 2) - static_cast<int>(_elementSize.y / 2);
			break;
		case VerticalAlignment::Lower:
			posY = static_cast<int>(_parentSize.y) - static_cast<int>(_elementSize.y);
			break;
		}

		// Apply Offset
		posX += _offset.x;
		posY += _offset.y;
		return sf::Vector2u(static_cast<unsigned int>(posX), static_cast<unsigned int>(posY));
	}
}
