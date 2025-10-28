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

		calculateNewSize(newSize, _texture.getSize());

		(void)m_renderTexture.resize(newSize);
	}

	void UIVisualContainer::calculateNewSize(sf::Vector2u& newSize, const sf::Vector2u& _parentSize)
	{
		// Calculate final minimum and maximum sizes based on SizeProperty constraints
		sf::Vector2u minSize;
		sf::Vector2u maxSize;
		calculateFinalMinMaxSizes(minSize, maxSize, _parentSize);

		// Calculate new size based on position mode
		if (m_position.mode == PositionModeProperty::Absolute)
		{
			calculateNewSizeInAbsolute(newSize, _parentSize);
		}
		else if (m_position.mode == PositionModeProperty::Relative)
		{
			calculateNewSizeInRelative(newSize, _parentSize);
		}

		// Clamp new size within min and max sizes
		newSize.x = std::max(minSize.x, std::min(newSize.x, maxSize.x));
		newSize.y = std::max(minSize.y, std::min(newSize.y, maxSize.y));
	}

	void UIVisualContainer::calculateNewSizeInAbsolute(sf::Vector2u& newSize, const sf::Vector2u& _parentSize)
	{
		// Compute new size
		const SizeVectorProperty& sizeProp = m_size.size;

		// Width
		switch (sizeProp.width.type)
		{
		case SizeValueTypeProperty::Pixels:
			newSize.x = static_cast<unsigned int>(sizeProp.width.value);
			break;
		case SizeValueTypeProperty::Percentage:
			newSize.x = static_cast<unsigned int>(_parentSize.x * (sizeProp.width.value / 100.f));
			break;
		case SizeValueTypeProperty::Auto:
			// Here we calculate auto size based on content or default to zero
			
		}
	}

	void UIVisualContainer::calculateNewSizeInRelative(sf::Vector2u& newSize, const sf::Vector2u& _parentSize)
	{
	}

	void UIVisualContainer::calculateFinalMinMaxSizes(sf::Vector2u& minSize, sf::Vector2u& maxSize, const sf::Vector2u& _parentSize) const
	{
		// Compute minimum size
		const MinSizeVectorProperty& minProp = m_size.minSize;

		// Width
		switch (minProp.width.type)
		{
		case MinSizeValueTypeProperty::Pixels:
			minSize.x = static_cast<unsigned int>(minProp.width.value);
			break;
		case MinSizeValueTypeProperty::Percentage:
			minSize.x = static_cast<unsigned int>(_parentSize.x * (minProp.width.value / 100.f));
			break;
		case MinSizeValueTypeProperty::Auto:
			minSize.x = 0u;
			break;
		default:
			minSize.x = 0u;
			break;
		}

		// Height
		switch (minProp.height.type)
		{
		case MinSizeValueTypeProperty::Pixels:
			minSize.y = static_cast<unsigned int>(minProp.height.value);
			break;
		case MinSizeValueTypeProperty::Percentage:
			minSize.y = static_cast<unsigned int>(_parentSize.y * (minProp.height.value / 100.f));
			break;
		case MinSizeValueTypeProperty::Auto:
			minSize.y = 0u;
			break;
		default:
			minSize.y = 0u;
			break;
		}

		// Compute maximum size
		const MaxSizeVectorProperty& maxProp = m_size.maxSize;

		// Width
		switch (maxProp.width.type)
		{
		case MaxSizeValueTypeProperty::Pixels:
			maxSize.x = static_cast<unsigned int>(maxProp.width.value);
			break;
		case MaxSizeValueTypeProperty::Percentage:
			maxSize.x = static_cast<unsigned int>(_parentSize.x * (maxProp.width.value / 100.f));
			break;
		case MaxSizeValueTypeProperty::None:
			maxSize.x = _parentSize.x;
			break;
		default:
			maxSize.x = _parentSize.x;
			break;
		}

		// Height
		switch (maxProp.height.type)
		{
		case MaxSizeValueTypeProperty::Pixels:
			maxSize.y = static_cast<unsigned int>(maxProp.height.value);
			break;
		case MaxSizeValueTypeProperty::Percentage:
			maxSize.y = static_cast<unsigned int>(_parentSize.y * (maxProp.height.value / 100.f));
			break;
		case MaxSizeValueTypeProperty::None:
			maxSize.y = _parentSize.y;
			break;
		default:
			maxSize.y = _parentSize.y;
			break;
		}
	}

	void UIVisualContainer::calculateContentSize(sf::Vector2u& contentSize) const
	{
		// Here we calculate the preffered size based on the hierarchy this element
		if (m_children.empty())
		{
			contentSize = getTextureSize();
			return;
		}

	}
}
