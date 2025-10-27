#include "Headers/SFUIL/Containers/UIVisualContainer.hpp"

namespace sfui
{
	UIVisualContainer::UIVisualContainer() : UIElement()
	{
	}

	UIVisualContainer::UIVisualContainer(const char* _name) : UIElement(_name)
	{
	}

	UIVisualContainer::~UIVisualContainer()
	{
	}

	void UIVisualContainer::render(sf::RenderTexture& _texture)
	{
		// If display property is None, do not render
		if (m_display.type == DisplayValueTypeProperty::None)
		{
			return;
		}

		reRenderIfDirty(_texture);

		// Check for position mode
		if (m_position.mode == PositionModeProperty::Relative)
		{
			// In relative mode, position is determined by the flex layout system
			// Here we calculate position based on parent container and flex properties
		}
		else if (m_position.mode == PositionModeProperty::Absolute)
		{
			// In absolute mode, position is determined by the position values
		}
	}

	void UIVisualContainer::drawToTarget(sf::RenderTarget& _target)
	{
	}

	void UIVisualContainer::reRenderIfDirty(sf::RenderTexture& _texture)
	{
		if (!m_dirty) return;

		// Perform re-rendering logic here
		m_dirty = false;

		sf::Vector2u newSize;

		if (m_position.mode == PositionModeProperty::Absolute)
		{
			unsigned int width = 0;
			unsigned int height = 0;

			// Calculate width based on SizeValueTypeProperty
			switch (m_size.size.width.type)
			{
			case SizeValueTypeProperty::Pixels:
				// Direct pixel value
				width = static_cast<unsigned int>(m_size.size.width.value);
				break;
			case SizeValueTypeProperty::Percentage:
				// Percentage of parent size
				width = static_cast<unsigned int>(_texture.getSize().x * m_size.size.width.value / 100);
				break;
			case SizeValueTypeProperty::Auto:
				// Auto size handling
				width = _texture.getSize().x;
				break;
			default:
				width = _texture.getSize().x;
				break;
			}

			// Clamp width to min and max constraints
			unsigned int minWidth = 0;
			switch (m_size.minSize.width.type)
			{
			case MinSizeValueTypeProperty::Pixels:
				minWidth = static_cast<unsigned int>(m_size.minSize.width.value);
				if (width < minWidth)
					width = static_cast<unsigned int>(m_size.minSize.width.value);
				break;
			case MinSizeValueTypeProperty::Percentage:
				minWidth = static_cast<unsigned int>(_texture.getSize().x * m_size.minSize.width.value / 100);
				if (width < minWidth)
					width = minWidth;
				break;
			case MinSizeValueTypeProperty::Auto:
				// No minimum constraint
				break;
			default:
				break;
			}

			unsigned int maxWidth = _texture.getSize().x;
			switch (m_size.maxSize.width.type)
			{
			case MaxSizeValueTypeProperty::Pixels:
				maxWidth = static_cast<unsigned int>(m_size.maxSize.width.value);
				if (width > maxWidth)
					width = maxWidth;
				break;
			case MaxSizeValueTypeProperty::Percentage:
				maxWidth = static_cast<unsigned int>(_texture.getSize().x * m_size.maxSize.width.value / 100);
				if (width > maxWidth)
					width = maxWidth;
				break;
			case MaxSizeValueTypeProperty::None:
				// No maximum constraint
				break;
			default:
				break;
			}

			// Calculate height based on SizeValueTypeProperty
			switch (m_size.size.height.type)
			{
			case SizeValueTypeProperty::Pixels:
				// Direct pixel value
				height = static_cast<unsigned int>(m_size.size.height.value);
				break;
			case SizeValueTypeProperty::Percentage:
				// Percentage of parent size
				height = static_cast<unsigned int>(_texture.getSize().y * m_size.size.height.value / 100);
				break;
			case SizeValueTypeProperty::Auto:
				// Auto size handling
				height = _texture.getSize().y;
				break;
			default:
				height = _texture.getSize().y;
				break;
			}

			// Clamp height to min and max constraints
			unsigned int minHeight = 0;
			switch (m_size.minSize.height.type)
			{
			case MinSizeValueTypeProperty::Pixels:
				minHeight = static_cast<unsigned int>(m_size.minSize.height.value);
				if (height < minHeight)
					height = minHeight;
				break;
			case MinSizeValueTypeProperty::Percentage:
				minHeight = static_cast<unsigned int>(_texture.getSize().y * m_size.minSize.height.value / 100);
				if (height < minHeight)
					height = minHeight;
				break;
			case MinSizeValueTypeProperty::Auto:
				// No minimum constraint
				break;
			default:
				break;
			}

			unsigned int maxHeight = _texture.getSize().y;
			switch (m_size.maxSize.height.type)
			{
			case MaxSizeValueTypeProperty::Pixels:
				maxHeight = static_cast<unsigned int>(m_size.maxSize.height.value);
				if (height > maxHeight)
					height = maxHeight;
				break;
			case MaxSizeValueTypeProperty::Percentage:
				maxHeight = static_cast<unsigned int>(_texture.getSize().y * m_size.maxSize.height.value / 100);
				if (height > maxHeight)
					height = maxHeight;
				break;
			case MaxSizeValueTypeProperty::None:
				// No maximum constraint
				break;
			default:
				break;
			}

			// Set new size
			newSize = sf::Vector2u(width, height);
		}
		else if (m_position.mode == PositionModeProperty::Relative)
		{
			
		}

		(void)m_renderTexture.resize(newSize);
	}
}
