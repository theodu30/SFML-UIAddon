#pragma once

#include "Exports.hpp"

#include <SFML/System/Vector2.hpp>

namespace sfui
{
	/// <summary>
	/// <paragraph>Defines vertical alignment options.</paragraph>
	/// </summary>
	enum VerticalAlignment
	{
		Upper,
		Middle,
		Lower
	};

	/// <summary>
	/// <paragraph>Defines horizontal alignment options.</paragraph>
	/// </summary>
	enum HorizontalAlignment
	{
		Left,
		Center,
		Right
	};

	/// <summary>
	/// <paragraph>Defines an alignment using horizontal and vertical alignment.</paragraph>
	/// </summary>
	class SFUIL_API Alignment
	{
	public:
		/// <summary>
		/// <paragraph>Constructs an Alignment with default values (Left, Upper).</paragraph>
		/// </summary>
		constexpr Alignment() = default;

		/// <summary>
		/// <paragraph>Constructs an Alignment with the given horizontal and vertical alignment.</paragraph>
		/// </summary>
		/// <param name="_alignX">The horizontal alignment.</param>
		/// <param name="_alignY">The vertical alignment.</param>
		constexpr Alignment(HorizontalAlignment _alignX, VerticalAlignment _alignY);

		~Alignment() = default;
		Alignment(const Alignment& _other);
		Alignment& operator=(const Alignment& _other);
		Alignment(Alignment&& _other) noexcept;
		Alignment& operator=(Alignment&& _other) noexcept;

		/// <summary>
		/// <paragraph>Returns the horizontal alignment.</paragraph>
		/// </summary>
		/// <returns></returns>
		HorizontalAlignment getHorizontalAlignment() const noexcept;

		/// <summary>
		/// <paragraph>Returns the vertical alignment.</paragraph>
		/// </summary>
		/// <returns></returns>
		VerticalAlignment getVerticalAlignment() const noexcept;

		[[nodiscard]] constexpr bool operator==(const Alignment& _other) const;

		static const Alignment UpperLeft;
		static const Alignment MiddleLeft;
		static const Alignment LowerLeft;
		static const Alignment UpperCenter;
		static const Alignment MiddleCenter;
		static const Alignment LowerCenter;
		static const Alignment UpperRight;
		static const Alignment MiddleRight;
		static const Alignment LowerRight;

	private:
		HorizontalAlignment alignX = Left;
		VerticalAlignment alignY = Upper;
	};

	/// <summary>
	/// <paragraph>Provides functions for anchoring elements within a parent container.</paragraph>
	/// </summary>
	class SFUIL_API Anchor
	{
	public:
		/// <summary>
		/// <paragraph>Calculates the anchored position of an element within a</paragraph>
		/// <paragraph>parent container based on the specified alignment and offset.</paragraph>
		/// </summary>
		/// <param name="_parentSize"></param>
		/// <param name="_elementSize"></param>
		/// <param name="_alignment"></param>
		/// <param name="_offset"></param>
		/// <returns></returns>
		[[nodiscard]] static const sf::Vector2u getAnchoredPosition(
			const sf::Vector2u& _parentSize,
			const sf::Vector2u& _elementSize,
			const Alignment& _alignment,
			const sf::Vector2i& _offset = { 0, 0 }
		);
	};
}