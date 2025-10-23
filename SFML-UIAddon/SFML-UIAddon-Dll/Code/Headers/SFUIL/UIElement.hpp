#pragma once

#include "System/Exports.hpp"
#include <SFML/Graphics/RenderTexture.hpp>

namespace sfui
{
	class SFUIL_API UIElement
	{
	public:
		UIElement() = default;
		virtual ~UIElement() = default;
		virtual void render(sf::RenderTexture& _texture) = 0;
		virtual void drawToTarget(sf::RenderTarget& _target) = 0;
	private:
	};
}