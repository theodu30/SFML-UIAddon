#pragma once

#include "System/Exports.hpp"
#include "System/Anchor.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace sfui
{
	// Forward declaration

	class UIVisualContainer;

	/// <summary>
	/// <paragraph>UIPanel is a container for UI Elements that renders them onto a RenderTexture.</paragraph>
	/// <paragraph>It can be drawn onto any RenderTarget.</paragraph>
	/// </summary>
	class SFUIL_API UIPanel
	{
	public:
		/// <summary>
		/// <paragraph>Constructs a UIPanel with default size 640x360.</paragraph>
		/// </summary>
		UIPanel();

		/// <summary>
		/// <paragraph>Destructs the UIPanel, clears all UI Elements, unsubscribes</paragraph>
		/// <paragraph>from all events and disposes of the RenderTexture.</paragraph>
		/// </summary>
		~UIPanel();

		/// <summary>
		/// <paragraph>Renders every UI Elements on the render texture.</paragraph>
		/// <paragraph>It does not draw anything to the screen yet.</paragraph>
		/// </summary>
		void render();

		/// <summary>
		/// <paragraph>Draws the RenderTexture of the UIPanel to the given RenderTarget.</paragraph>
		/// <paragraph>Make sure to call render() before calling this function.</paragraph>
		/// <paragraph>Needs to be called within the main RenderTarget's drawing loop.</paragraph>
		/// </summary>
		/// <param name="_target">The RenderTarget to draw the UIPanel on.</param>
		void drawToTarget(sf::RenderTarget& _target);

		/// <summary>
		/// <paragraph>Sets whether the UIPanel is active or not.</paragraph>
		/// </summary>
		/// <param name="_active">State to set the UIPanel to.</param>
		void setActive(bool _active);

		/// <summary>
		/// <paragraph>Returns whether the UIPanel is active or not.</paragraph>
		/// </summary>
		/// <returns></returns>
		const bool& isActive() const noexcept;

		/// <summary>
		/// <paragraph>Sets the size of the UIPanel.</paragraph>
		/// </summary>
		/// <param name="_size">The new size of the UIPanel.</param>
		void setSize(const sf::Vector2u& _size);

		/// <summary>
		/// <paragraph>Sets the size of the UIPanel.</paragraph>
		/// </summary>
		/// <param name="_width">The new width of the UIPanel.</param>
		/// <param name="_height">The new height of the UIPanel.</param>
		void setSize(unsigned int _width, unsigned int _height);

		/// <summary>
		/// <paragraph>Returns the size of the UIPanel.</paragraph>
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] const sf::Vector2u& getSize() const noexcept;

		/// <summary>
		/// <paragraph>Returns the width of the UIPanel.</paragraph>
		/// </summary>
		/// <returns></returns>
		const unsigned int& getWidth() const noexcept;

		/// <summary>
		/// <paragraph>Returns the height of the UIPanel.</paragraph>
		/// </summary>
		/// <returns></returns>
		const unsigned int& getHeight() const noexcept;

		/// <summary>
		/// <paragraph>Sets the alignment of the UIPanel.</paragraph>
		/// </summary>
		/// <param name="_alignment">The new alignment of the UIPanel.</param>
		void setAlignment(const Alignment& _alignment);

		/// <summary>
		/// <paragraph>Sets the alignment of the UIPanel.</paragraph>
		/// </summary>
		/// <param name="_alignX">The new horizontal alignment of the UIPanel.</param>
		/// <param name="_alignY">The new vertical alignment of the UIPanel.</param>
		void setAlignment(HorizontalAlignment _alignX, VerticalAlignment _alignY);

		/// <summary>
		/// <paragraph>Returns the alignment of the UIPanel.</paragraph>
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] const Alignment& getAlignment() const noexcept;

		/// <summary>
		/// <paragraph>Sets the offset of the UIPanel.</paragraph>
		/// </summary>
		/// <param name="_offset">The new offset of the UIPanel.</param>
		void setOffset(const sf::Vector2i& _offset);

		/// <summary>
		/// <paragraph>Sets the offset of the UIPanel.</paragraph>
		/// </summary>
		/// <param name="_offsetX">The new X offset of the UIPanel.</param>
		/// <param name="_offsetY">The new Y offset of the UIPanel.</param>
		void setOffset(int _offsetX, int _offsetY);

		/// <summary>
		/// <paragraph>Returns the offset of the UIPanel.</paragraph>
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] const sf::Vector2i& getOffset() const noexcept;

		/// <summary>
		/// <paragraph>Sets the background color of the UIPanel.</paragraph>
		/// </summary>
		/// <param name="_color">The new background color of the UIPanel.</param>
		void setPanelBackgroundColor(const sf::Color& _color);

		/// <summary>
		/// <paragraph>Returns the background color of the UIPanel.</paragraph>
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] const sf::Color& getPanelBackgroundColor() const noexcept;

		/// <summary>
		/// <paragraph>Gets the root UI Visual Container of the UIPanel.</paragraph>
		/// </summary>
		/// <returns></returns>
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