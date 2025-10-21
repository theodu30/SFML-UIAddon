#pragma once

#include "Exports.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace sfui
{
	class SFMLUIADDON_API UIPanel
	{
	public:
		UIPanel();
		~UIPanel();

		void setActive(bool _active);
		bool isActive() const noexcept;

		void setSize(const sf::Vector2u& _size);
		sf::Vector2u getSize() const noexcept;
		unsigned int getWidth() const noexcept;
		unsigned int getHeight() const noexcept;
	private:
		bool m_active = false;
		sf::Vector2u m_size;

		sf::RenderTexture m_renderTexture;
	};
}