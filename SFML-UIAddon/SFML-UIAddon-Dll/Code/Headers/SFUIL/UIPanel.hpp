#pragma once

#include "System/Exports.hpp"
#include "System/Anchor.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace sfui
{
	class UIVisualContainer;

	class SFUIL_API UIPanel
	{
	public:
		UIPanel();

		~UIPanel();

		void render();

		void drawToTarget(sf::RenderTarget& _target);

		void setActive(bool _active);

		const bool& isActive() const noexcept;

		void setSize(const sf::Vector2u& _size);

		void setSize(unsigned int _width, unsigned int _height);

		[[nodiscard]] const sf::Vector2u& getSize() const noexcept;

		const unsigned int& getWidth() const noexcept;

		const unsigned int& getHeight() const noexcept;

		void setAlignment(const Alignment& _alignment);

		void setAlignment(HorizontalAlignment _alignX, VerticalAlignment _alignY);

		[[nodiscard]] const Alignment& getAlignment() const noexcept;

		void setOffset(const sf::Vector2i& _offset);

		void setOffset(int _offsetX, int _offsetY);

		[[nodiscard]] const sf::Vector2i& getOffset() const noexcept;

		void setPanelBackgroundColor(const sf::Color& _color);

		[[nodiscard]] const sf::Color& getPanelBackgroundColor() const noexcept;

		UIVisualContainer* getRootElement() const noexcept
		{
			return m_rootElement;
		}
	private:
		bool m_active = false;
		Alignment m_alignment;
		sf::Color m_panelBackgroundColor = sf::Color::Transparent;
		sf::Vector2u m_size;
		sf::Vector2i m_offset = sf::Vector2i(0, 0);
		sf::RenderTexture m_renderTexture;
		UIVisualContainer* m_rootElement = nullptr;
	};
}