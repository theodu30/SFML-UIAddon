#pragma once

#include "Exports.hpp"
#include <SFML/System/Vector2.hpp>

namespace sfui
{
	class SFMLUIADDON_API UIPanel
	{
	public:
		UIPanel();
		~UIPanel();

		void setActive(bool _active);
		[[nodiscard]] bool isActive() const noexcept;
	private:
		bool m_active = false;
		sf::Vector2u m_size;
	};
}