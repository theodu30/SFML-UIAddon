#pragma once

// Include Export.hpp and UIElement.hpp
#include "../System/Exports.hpp"
#include "../UIElement.hpp"

namespace sfui
{
	class SFUIL_API UIVisualContainer : public UIElement
	{
	public:
		UIVisualContainer();
		UIVisualContainer(const char* _name);
		~UIVisualContainer();

		void render(sf::RenderTexture& _texture) override;
		void drawToTarget(sf::RenderTarget& _target) override;
	protected:
		void reRenderIfDirty(sf::RenderTexture& _texture) override;
	private:
		void calculateNewSize(sf::Vector2u& newSize, const sf::Vector2u& _parentSize);
		void calculateNewSizeInAbsolute(sf::Vector2u& newSize, const sf::Vector2u& _parentSize);
		void calculateNewSizeInRelative(sf::Vector2u& newSize, const sf::Vector2u& _parentSize);
		void calculateFinalMinMaxSizes(sf::Vector2u& minSize, sf::Vector2u& maxSize, const sf::Vector2u& _parentSize) const;
		void calculateContentSize(sf::Vector2u& contentSize) const;
	};
}