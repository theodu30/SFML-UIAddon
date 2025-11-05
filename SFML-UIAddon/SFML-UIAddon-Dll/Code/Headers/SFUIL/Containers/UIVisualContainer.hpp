#pragma once

// Include Export.hpp and UIElement.hpp
#include "../System/Exports.hpp"
#include "../UIElement.hpp"

namespace sfui
{
	class SFUIL_API UIVisualContainer : public UIElement
	{
	public:
		/// <summary>
		/// <paragraph>Constructs a UIVisualContainer with default name.</paragraph>
		/// </summary>
		UIVisualContainer();

		/// <summary>
		/// <paragraph>Constructs a UIVisualContainer with the provided name.</paragraph>
		/// </summary>
		/// <param name="_name"></param>
		UIVisualContainer(const char* _name);

		/// <summary>
		/// <paragraph>Destructs the UIVisualContainer.</paragraph>
		/// </summary>
		~UIVisualContainer();

		/// <summary>
		/// <paragraph>Draws the UIVisualContainer to the provided RenderTarget.</paragraph>
		/// </summary>
		/// <param name="_target"></param>
		void drawToTarget(sf::RenderTexture& _target) override;
	protected:
		/// <summary>
		/// <paragraph>Re-renders the UIVisualContainer texture if it is marked as dirty.</paragraph>
		/// </summary>
		/// <param name="_texture"></param>
		void reRenderIfDirty(sf::RenderTexture& _texture) override;

		void Initialize() override;
	private:
		/// <summary>
		/// <paragraph>Calculates the new size of the UIVisualContainer based on its SizeProperty and the parent size.</paragraph>
		/// </summary>
		/// <param name="newSize"></param>
		/// <param name="_parentSize"></param>
		void calculateNewSize(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		/// <summary>
		/// <paragraph>Calculates the new size in absolute mode.</paragraph>
		/// </summary>
		/// <param name="newSize"></param>
		/// <param name="_parentSize"></param>
		void calculateNewSizeInAbsolute(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		/// <summary>
		/// <paragraph>Calculates the new size in relative mode.</paragraph>
		/// </summary>
		/// <param name="newSize"></param>
		/// <param name="_parentSize"></param>
		void calculateNewSizeInRelative(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		/// <summary>
		/// <paragraph>Calculates the final minimum and maximum sizes based on SizeProperty constraints.</paragraph>
		/// </summary>
		/// <param name="minSize"></param>
		/// <param name="maxSize"></param>
		/// <param name="_parentSize"></param>
		void calculateFinalMinMaxSizes(sf::Vector2u& minSize, sf::Vector2u& maxSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex) const;

		/// <summary>
		/// <paragraph>Calculates the content size based on the sizes of child elements.</paragraph>
		/// </summary>
		/// <param name="contentSize"></param>
		void calculateContentSize(sf::Vector2u& contentSize) const;

		/// <summary>
		/// <paragraph>Resolves the final basic width for flex layout calculations.</paragraph>
		/// </summary>
		/// <param name="_child"></param>
		/// <param name="_parentWidth"></param>
		/// <returns></returns>
		float resolveFinalBasicWidth(const UIVisualContainer& _child, const float& _parentWidth) const;

		/// <summary>
		/// <paragraph>Resolves the final basic height for flex layout calculations.</paragraph>
		/// </summary>
		/// <param name="_child"></param>
		/// <param name="_parentHeight"></param>
		/// <returns></returns>
		float resolveFinalBasicHeight(const UIVisualContainer& _child, const float& _parentHeight) const;
	};
}