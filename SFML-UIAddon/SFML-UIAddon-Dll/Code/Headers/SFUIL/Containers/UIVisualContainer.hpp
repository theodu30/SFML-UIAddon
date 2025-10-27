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
	};
}