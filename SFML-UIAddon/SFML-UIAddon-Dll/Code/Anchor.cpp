#include "Headers/SFUIL/System/Anchor.hpp"

namespace sfui
{
	inline constexpr Alignment PredefinedAlignments::UpperLeft =
		Alignment({ HorizontalAlignment::Left, VerticalAlignment::Upper });
	inline constexpr Alignment PredefinedAlignments::MiddleLeft =
		Alignment({ HorizontalAlignment::Left, VerticalAlignment::Middle });
	inline constexpr Alignment PredefinedAlignments::LowerLeft =
		Alignment({ HorizontalAlignment::Left, VerticalAlignment::Lower });
	inline constexpr Alignment PredefinedAlignments::UpperCenter =
		Alignment({ HorizontalAlignment::Center, VerticalAlignment::Upper });
	inline constexpr Alignment PredefinedAlignments::MiddleCenter =
		Alignment({ HorizontalAlignment::Center, VerticalAlignment::Middle });
	inline constexpr Alignment PredefinedAlignments::LowerCenter =
		Alignment({ HorizontalAlignment::Center, VerticalAlignment::Lower });
	inline constexpr Alignment PredefinedAlignments::UpperRight =
		Alignment({ HorizontalAlignment::Right, VerticalAlignment::Upper });
	inline constexpr Alignment PredefinedAlignments::MiddleRight =
		Alignment({ HorizontalAlignment::Right, VerticalAlignment::Middle });
	inline constexpr Alignment PredefinedAlignments::LowerRight =
		Alignment({ HorizontalAlignment::Right, VerticalAlignment::Lower });

	const sf::Vector2f& Anchor::getAnchoredPosition(
		const sf::Vector2u& _parentSize,
		const sf::Vector2u& _elementSize,
		const Alignment& _alignment,
		const sf::Vector2i& _offset)
	{
		static sf::Vector2f result;

		// Initial Position
		int posX = 0;
		int posY = 0;

		// Horizontal Alignment
		switch (_alignment.m_alignX)
		{
		case HorizontalAlignment::Left:
			posX = 0;
			break;
		case HorizontalAlignment::Center:
			posX = (static_cast<int>(_parentSize.x) - static_cast<int>(_elementSize.x)) / 2;
			break;
		case HorizontalAlignment::Right:
			posX = static_cast<int>(_parentSize.x) - static_cast<int>(_elementSize.x);
			break;
		}

		// Vertical Alignment
		switch (_alignment.m_alignY)
		{
		case VerticalAlignment::Upper:
			posY = 0;
			break;
		case VerticalAlignment::Middle:
			posY = (static_cast<int>(_parentSize.y) - static_cast<int>(_elementSize.y)) / 2;
			break;
		case VerticalAlignment::Lower:
			posY = static_cast<int>(_parentSize.y) - static_cast<int>(_elementSize.y);
			break;
		}

		// Apply Offset
		posX += _offset.x;
		posY += _offset.y;
		result.x = static_cast<float>(posX);
		result.y = static_cast<float>(posY);
		return result;
	}
}
