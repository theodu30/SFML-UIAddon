#pragma once

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

		void drawToTarget(sf::RenderTexture& _target) override;

	protected:
		void reRenderIfDirty(sf::RenderTexture& _texture) override;

		void Initialize() override;

	private:
		void calculateNewSize(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		void calculateNewSizeInAbsolute(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		void calculateNewSizeInRelative(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		void calculateFinalMinMaxSizes(sf::Vector2u& minSize, sf::Vector2u& maxSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex) const;

		void calculateContentSize(sf::Vector2u& contentSize) const;

		float resolveFinalBasicWidth(const UIVisualContainer& _child, const float& _parentWidth) const;

		float resolveFinalBasicHeight(const UIVisualContainer& _child, const float& _parentHeight) const;
	};
}