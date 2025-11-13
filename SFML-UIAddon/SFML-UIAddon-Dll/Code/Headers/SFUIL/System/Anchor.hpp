#pragma once

#include "Exports.hpp"

#include <SFML/System/Vector2.hpp>

namespace sfui
{
	enum class SFUIL_API VerticalAlignment : char
	{
		Upper,
		Middle,
		Lower
	};

	enum class SFUIL_API HorizontalAlignment : char
	{
		Left,
		Center,
		Right
	};

	struct SFUIL_API Alignment
	{
		HorizontalAlignment m_alignX = HorizontalAlignment::Left;
		VerticalAlignment m_alignY = VerticalAlignment::Upper;
	};

	struct SFUIL_API PredefinedAlignments
	{
		static const Alignment UpperLeft;
		static const Alignment MiddleLeft;
		static const Alignment LowerLeft;
		static const Alignment UpperCenter;
		static const Alignment MiddleCenter;
		static const Alignment LowerCenter;
		static const Alignment UpperRight;
		static const Alignment MiddleRight;
		static const Alignment LowerRight;
	};

	class SFUIL_API Anchor
	{
	public:
		[[nodiscard]] static const sf::Vector2f& getAnchoredPosition(
			const sf::Vector2u& _parentSize,
			const sf::Vector2u& _elementSize,
			const Alignment& _alignment,
			const sf::Vector2i& _offset = { 0, 0 }
		);
	};
}