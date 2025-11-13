#include "Headers/SFUIL/UIPanel.hpp"
#include "Headers/SFUIL/Containers/UIVisualContainer.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

namespace sfui
{
	UIPanel::UIPanel()
	{
		m_size = sf::Vector2u(640, 360);
		m_renderTexture = sf::RenderTexture(m_size);

		m_rootElement = new UIVisualContainer("__ROOT_ELEMENT__");
		m_rootElement->getProperty<PositionProperty>().setMode(PositionProperty::Mode::Absolute);
		SizeProperty& rootSize = m_rootElement->getProperty<SizeProperty>();
		rootSize.setWidth(100.f, SizeProperty::SizeType::Percentage);
		rootSize.setHeight(100.f, SizeProperty::SizeType::Percentage);
	}

	UIPanel::~UIPanel()
	{
		delete m_rootElement;
	}

	void UIPanel::render()
	{
		if (!m_active)
		{
			return;
		}

		m_renderTexture.clear(m_panelBackgroundColor);

		m_rootElement->drawToTarget(m_renderTexture);

		m_renderTexture.display();
	}

	void UIPanel::drawToTarget(sf::RenderTarget& _target)
	{
		if (!m_active)
		{
			return;
		}

		// Get Texture of RenderTexture and make a Sprite with it
		const sf::Texture& texture = m_renderTexture.getTexture();
		sf::Sprite sprite(texture);

		// Set Position of Sprite based on Alignment and Offset
		sf::Vector2u targetSize = _target.getSize();
		sf::Vector2f position = Anchor::getAnchoredPosition(targetSize, m_size, m_alignment, m_offset);
		sprite.setPosition(sf::Vector2f(position));

		// Draw RenderTexture to _target
		_target.draw(sprite);
	}

	void UIPanel::setActive(bool _active)
	{
		m_active = _active;
	}

	const bool& UIPanel::isActive() const noexcept
	{
		return m_active;
	}

	void UIPanel::setSize(const sf::Vector2u& _size)
	{
		m_size = _size;
		static_cast<void>(m_renderTexture.resize(m_size));
	}

	void UIPanel::setSize(unsigned int _width, unsigned int _height)
	{
		setSize(sf::Vector2u(_width, _height));
	}

	const sf::Vector2u& UIPanel::getSize() const noexcept
	{
		return m_size;
	}

	const unsigned int& UIPanel::getWidth() const noexcept
	{
		return m_size.x;
	}

	const unsigned int& UIPanel::getHeight() const noexcept
	{
		return m_size.y;
	}

	void UIPanel::setAlignment(const Alignment& _alignment)
	{
		m_alignment = _alignment;
	}

	void UIPanel::setAlignment(HorizontalAlignment _alignX, VerticalAlignment _alignY)
	{
		setAlignment(Alignment(_alignX, _alignY));
	}

	const Alignment& UIPanel::getAlignment() const noexcept
	{
		return m_alignment;
	}

	void UIPanel::setOffset(const sf::Vector2i& _offset)
	{
		m_offset = _offset;
	}

	void UIPanel::setOffset(int _offsetX, int _offsetY)
	{
		setOffset(sf::Vector2i(_offsetX, _offsetY));
	}

	const sf::Vector2i& UIPanel::getOffset() const noexcept
	{
		return m_offset;
	}

	void UIPanel::setPanelBackgroundColor(const sf::Color& _color)
	{
		m_panelBackgroundColor = _color;
	}

	const sf::Color& UIPanel::getPanelBackgroundColor() const noexcept
	{
		return m_panelBackgroundColor;
	}
}
