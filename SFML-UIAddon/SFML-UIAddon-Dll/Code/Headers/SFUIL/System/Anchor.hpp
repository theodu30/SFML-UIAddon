#pragma once

#include "Exports.hpp"

#include <SFML/System/Vector2.hpp>

namespace sfui
{
	enum VerticalAlignment
	{
		Upper,
		Middle,
		Lower
	};

	enum HorizontalAlignment
	{
		Left,
		Center,
		Right
	};

	class SFUIL_API Alignment
	{
	public:
		// Members
		HorizontalAlignment alignX = Left;
		VerticalAlignment alignY = Upper;

		// Constructors and Destructor
		constexpr Alignment() = default;
		constexpr Alignment(HorizontalAlignment _alignX, VerticalAlignment _alignY);
		~Alignment() = default;
		Alignment(const Alignment& _other);
		Alignment& operator=(const Alignment& _other);
		Alignment(Alignment&& _other) noexcept;
		Alignment& operator=(Alignment&& _other) noexcept;

		// Operator Overloads
		[[nodiscard]] constexpr bool operator==(const Alignment& _other) const;

		// Predefined Alignments
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
		// Useful functions
		[[nodiscard]] static const sf::Vector2u getAnchoredPosition(
			const sf::Vector2u& _parentSize,
			const sf::Vector2u& _elementSize,
			const Alignment& _alignment,
			const sf::Vector2i& _offset = { 0, 0 }
		);
	};
}