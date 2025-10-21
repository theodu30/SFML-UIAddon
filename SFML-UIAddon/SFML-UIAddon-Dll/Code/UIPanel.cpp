#include "Headers/SFMLUIAddon/UIPanel.hpp"

namespace sfui
{
	UIPanel::UIPanel()
	{
		m_renderTexture = sf::RenderTexture(sf::Vector2u(100, 100));
	}

	UIPanel::~UIPanel()
	{
	}

	void UIPanel::setActive(bool _active)
	{
		m_active = _active;
	}

	bool UIPanel::isActive() const noexcept
	{
		return m_active;
	}

	void UIPanel::setSize(const sf::Vector2u& _size)
	{
		m_size = _size;
	}

	sf::Vector2u UIPanel::getSize() const noexcept
	{
		return m_size;
	}

	unsigned int UIPanel::getWidth() const noexcept
	{
		return m_size.x;
	}

	unsigned int UIPanel::getHeight() const noexcept
	{
		return m_size.y;
	}
}
