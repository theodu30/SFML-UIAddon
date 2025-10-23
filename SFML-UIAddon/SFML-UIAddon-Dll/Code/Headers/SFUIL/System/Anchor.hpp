#pragma once

#include "Exports.hpp"

#include <SFML/System/Vector2.hpp>

namespace sfui
{
	/// <summary>
	/// <paragraph>Defines vertical alignment options.</paragraph>
	/// </summary>
	enum class SFUIL_API VerticalAlignment : char
	{
		Upper,
		Middle,
		Lower
	};

	/// <summary>
	/// <paragraph>Defines horizontal alignment options.</paragraph>
	/// </summary>
	enum class SFUIL_API HorizontalAlignment : char
	{
		Left,
		Center,
		Right
	};

	/// <summary>
	/// <paragraph>Defines an alignment using horizontal and vertical alignment.</paragraph>
	/// </summary>
	struct SFUIL_API Alignment
	{
		HorizontalAlignment m_alignX = HorizontalAlignment::Left;
		VerticalAlignment m_alignY = VerticalAlignment::Upper;
	};

	/// <summary>
	/// <paragraph>Provides predefined alignment constants for common alignments.</paragraph>
	/// </summary>
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
		/// <param name="_parentSize">The size of the parent container.</param>
		/// <param name="_elementSize">The size of the element to be positioned.</param>
		/// <param name="_alignment">The alignment of the element within the parent container.</param>
		/// <param name="_offset">The offset to be applied to the calculated position.</param>
		/// <returns></returns>
		[[nodiscard]] static const sf::Vector2f& getAnchoredPosition(
			const sf::Vector2u& _parentSize,
			const sf::Vector2u& _elementSize,
			const Alignment& _alignment,
			const sf::Vector2i& _offset = { 0, 0 }
		);
	};
}