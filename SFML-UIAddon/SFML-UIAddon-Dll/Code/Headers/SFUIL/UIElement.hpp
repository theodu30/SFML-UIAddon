#pragma once

#include "System/Exports.hpp"
#include "System/UIElementProperty.hpp"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <vector>
#include <concepts>

namespace sfui
{
	// Forward declaration of UIElement
	class UIElement;

	// Template concept to ensure T is derived from UIElement
	template<typename T>
	concept UIElementSubClass = std::derived_from<T, UIElement>;

	/// <summary>
	/// <paragraph>Base class for all UI Elements in the SFML-UIAddon library.</paragraph>
	/// </summary>
	class SFUIL_API UIElement
	{
	public:
		UIElement() = default;
		UIElement(const char* _name) : m_name(_name) {}
		virtual ~UIElement() = default;

		/// <summary>
		/// <paragraph>Draws the UI Element to the provided RenderTarget.</paragraph>
		/// </summary>
		/// <param name="_target">The RenderTarget to draw to.</param>
		virtual void drawToTarget(sf::RenderTexture& _target) = 0;

		/// <summary>
		/// <paragraph>Getter for Spacing Property.</paragraph>
		/// <paragraph>Allows access to margin and padding properties.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		SpacingProperty& getSpacingProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Spacing Property.</paragraph>
		/// <paragraph>Allows access to margin and padding properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		const SpacingProperty& getConstSpacingProperty() const;

		/// <summary>
		/// <paragraph>Getter for Border Property.</paragraph>
		/// <paragraph>Allows access to border color, width, and radius properties.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		BorderProperty& getBorderProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Border Property.</paragraph>
		/// <paragraph>Allows access to border color, width, and radius properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		const BorderProperty& getConstBorderProperty() const;

		/// <summary>
		/// <paragraph>Getter for Transform Property.</paragraph>
		/// <paragraph>Allows access to transform origin, translate, scale, and rotate properties.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		TransformProperty& getTransformProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Transform Property.</paragraph>
		/// <paragraph>Allows access to transform origin, translate, scale, and rotate properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		const TransformProperty& getConstTransformProperty() const;

		/// <summary>
		/// <paragraph>Getter for Size Property.</paragraph>
		/// <paragraph>Allows access to width and height properties, including min and max constraints.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		SizeProperty& getSizeProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Size Property.</paragraph>
		/// <paragraph>Allows access to width and height properties, including min and max constraints.</paragraph>
		/// </summary>
		/// <returns></returns>
		const SizeProperty& getConstSizeProperty() const;

		/// <summary>
		/// <paragraph>Getter for Position Property.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		PositionProperty& getPositionProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Position Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		const PositionProperty& getConstPositionProperty() const;

		/// <summary>
		/// <paragraph>Getter for Background Property.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		BackgroundProperty& getBackgroundProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Background Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		const BackgroundProperty& getConstBackgroundProperty() const;

		/// <summary>
		/// <paragraph>Getter for Flex Property.</paragraph>
		/// <paragraph>Allows access to shrink, grow, direction, and wrap properties.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		FlexProperty& getFlexProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Flex Property.</paragraph>
		/// <paragraph>Allows access to shrink, grow, direction, and wrap properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		const FlexProperty& getConstFlexProperty() const;

		/// <summary>
		/// <paragraph>Getter for Align Property.</paragraph>
		/// <paragraph>Allows access to align items, justify content, align self and align contents properties.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		AlignProperty& getAlignProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Align Property.</paragraph>
		/// <paragraph>Allows access to align items, justify content, align self and align contents properties.</paragraph>
		/// </summary>
		/// <returns></returns>
		const AlignProperty& getConstAlignProperty() const;

		/// <summary>
		/// <paragraph>Getter for Opacity Property.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		OpacityProperty& getOpacityProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Opacity Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		const OpacityProperty& getConstOpacityProperty() const;

		/// <summary>
		/// <paragraph>Getter for Visibility Property.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		VisibilityProperty& getVisibilityProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Visibility Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		const VisibilityProperty& getConstVisibilityProperty() const;

		/// <summary>
		/// <paragraph>Getter for Display Property.</paragraph>
		/// <paragraph>Assume modification and set dirty flag to true.</paragraph>
		/// </summary>
		/// <returns></returns>
		DisplayProperty& getDisplayProperty();

		/// <summary>
		/// <paragraph>Const version: Getter for Display Property.</paragraph>
		/// </summary>
		/// <returns></returns>
		const DisplayProperty& getConstDisplayProperty() const;

		/// <summary>
		/// <paragraph>Sets the name of the UI Element.</paragraph>
		/// </summary>
		/// <param name="_name">The name to set for the UI Element.</param>
		void setName(const char* _name);

		/// <summary>
		/// <paragraph>Gets the name of the UI Element.</paragraph>
		/// </summary>
		/// <returns></returns>
		const char* getName() const;

		/// <summary>
		/// <paragraph>Returns the number of child UI Elements.</paragraph>
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] size_t getChildCount() const noexcept;

		/// <summary>
		/// <paragraph>Adds a child UI Element to this element.</paragraph>
		/// </summary>
		/// <param name="_child">Pointer to the child UI Element to add.</param>
		/// <returns>True if the child was added successfully, false otherwise.</returns>
		bool addChild(UIElement* _child);

		/// <summary>
		/// <paragraph>Removes itself from its parent UI Element.</paragraph>
		/// </summary>
		/// <returns>True if successfully removed from parent, false otherwise.</returns>
		bool removeFromParent();

		/// <summary>
		/// <paragraph>Removes itself and all its children from the UI hierarchy.</paragraph>
		/// <paragraph>Destroys itself all child UI Elements recursively.</paragraph>
		/// </summary>
		/// <returns>Will always return true right after successful removal.</returns>
		bool removeFromHierarchy();

		/// <summary>
		/// <paragraph>Gets a reference to the vector of child UI Elements.</paragraph>
		/// </summary>
		/// <returns></returns>
		std::vector<UIElement*>& getChildren();

		/// <summary>
		/// <paragraph>Gets the render size of the UI Element after applying sizing and layout calculations.</paragraph>
		/// </summary>
		/// <returns></returns>
		sf::Vector2f getRenderSize() const;

		/// <summary>
		/// <paragraph>Gets the render position of the UI Element after applying positioning and transformations.</paragraph>
		/// </summary>
		/// <returns></returns>
		sf::Vector2f getRenderPosition() const;

		/// <summary>
		/// <paragraph>Cast the UI Element to a specific derived type from UIElement.</paragraph>
		/// </summary>
		/// <typeparam name="T">The target derived type to cast to.</typeparam>
		/// <returns>Pointer to the casted type if successful, nullptr otherwise.</returns>
		template<UIElementSubClass T>
		T* as()
		{
			return dynamic_cast<T*>(this);
		}

		/// <summary>
		/// <paragraph>Const version: Cast the UI Element to a specific derived type from UIElement.</paragraph>
		/// </summary>
		/// <typeparam name="T">The target derived type to cast to.</typeparam>
		/// <returns>Pointer to the casted type if successful, nullptr otherwise.</returns>
		template<UIElementSubClass T>
		T* as() const
		{
			return dynamic_cast<T*>(this);
		}

		/// <summary>
		/// <paragraph>Queries the UI Element hierarchy for a descendant of a specific derived type from UIElement.</paragraph>
		/// <paragraph>Will return the first matching descendant found in a depth-first search manner.</paragraph>
		/// </summary>
		/// <typeparam name="T">The target derived type to search for.</typeparam>
		/// <returns>Pointer to the found descendant if successful, nullptr otherwise.</returns>
		template<UIElementSubClass T>
		T* query()
		{
			for (UIElement* child : m_children)
			{
				if (T* castedChild = child->as<T>())
				{
					return castedChild;
				}
				if (T* descendant = child->query<T>())
				{
					return descendant;
				}
			}
			return nullptr;
		}

		/// <summary>
		/// <paragraph>Queries the UI Element hierarchy for a descendant of a specific derived type from UIElement with a specific name.</paragraph>
		/// <paragraph>Will return the first matching descendant found in a depth-first search manner.</paragraph>
		/// </summary>
		/// <typeparam name="T">The target derived type to search for.</typeparam>
		/// <param name="_name">The name of the UI Element to search for.</param>
		/// <returns>Pointer to the found descendant if successful, nullptr otherwise.</returns>
		template <UIElementSubClass T>
		T* query(const char* _name)
		{
			for (UIElement* child : m_children)
			{
				if (T* castedChild = child->as<T>())
				{
					if (std::strcmp(castedChild->getName(), _name) == 0)
					{
						return castedChild;
					}
				}
				if (T* descendant = child->query<T>(_name))
				{
					return descendant;
				}
			}
			return nullptr;
		}

		/// <summary>
		/// <paragraph>Queries the UI Element hierarchy for all descendants of a specific derived type from UIElement.</paragraph>
		/// <paragraph>Will return all matching descendants found in a depth-first search manner.</paragraph>
		/// </summary>
		/// <typeparam name="T">The target derived type to search for.</typeparam>
		/// <returns>Vector of pointers to the found descendants.</returns>
		template <UIElementSubClass T>
		std::vector<T*> queryAll()
		{
			std::vector<T*> results;
			for (UIElement* child : m_children)
			{
				if (T* castedChild = child->as<T>())
				{
					results.push_back(castedChild);
				}
				std::vector<T*> descendantResults = child->queryAll<T>();
				results.insert(results.end(), descendantResults.begin(), descendantResults.end());
			}
			return results;
		}

		/// <summary>
		/// <paragraph>Queries the UI Element hierarchy for all descendants of a specific derived type from UIElement with a specific name.</paragraph>
		/// <paragraph>Will return all matching descendants found in a depth-first search manner.</paragraph>
		/// </summary>
		/// <typeparam name="T">The target derived type to search for.</typeparam>
		/// <param name="_name">The name of the UI Element to search for.</param>
		/// <returns>Vector of pointers to the found descendants.</returns>
		template <UIElementSubClass T>
		std::vector<T*> queryAll(const char* _name)
		{
			std::vector<T*> results;
			for (UIElement* child : m_children)
			{
				if (T* castedChild = child->as<T>())
				{
					if (std::strcmp(castedChild->getName(), _name) == 0)
					{
						results.push_back(castedChild);
					}
				}
				std::vector<T*> descendantResults = child->queryAll<T>(_name);
				results.insert(results.end(), descendantResults.begin(), descendantResults.end());
			}
			return results;
		}

	protected:
		const char* m_name = "UIElement"; // Name of the UI Element
		std::vector<UIElement*> m_children; // Child UI Elements
		UIElement* m_parent = nullptr; // Parent UI Element
		bool m_dirty = true; // Flag indicating if the element needs to be re-rendered

		sf::Vector2f m_renderSize; // Size used during the last render
		sf::Vector2f m_renderPosition; // Position used during the last render

		SpacingProperty m_spacing;
		BorderProperty m_border;
		TransformProperty m_transform;
		SizeProperty m_size;
		PositionProperty m_position;
		BackgroundProperty m_background;
		FlexProperty m_flex;
		AlignProperty m_align;
		OpacityProperty m_opacity;
		VisibilityProperty m_visibility;
		DisplayProperty m_display;

		/// <summary>
		/// <paragraph>Marks the UI Element as dirty, indicating it needs to be re-rendered.</paragraph>
		/// <paragraph>Also propagates the dirty flag to the parent element if it exists.</paragraph>
		/// </summary>
		void markDirty();

		/// <summary>
		/// <paragraph>Re-renders the UI Element texture if it is marked as dirty.</paragraph>
		/// </summary>
		/// <param name="_texture">The RenderTexture assigned for layout calculations.</param>
		virtual void reRenderIfDirty(sf::RenderTexture& _texture) = 0;

		/// <summary>
		/// <paragraph>Computes the position of the UI Element based on its properties and the given bounds.</paragraph>
		/// </summary>
		/// <param name="_target"></param>
		/// <param name="_sprite"></param>
		void computePosition(const sf::Vector2f& _targetSize, const sf::FloatRect& _bounds);

		/// <summary>
		/// <paragraph>Applies transformation properties to the given sprite before drawing.</paragraph>
		/// </summary>
		/// <param name="_target"></param>
		/// <param name="_sprite"></param>
		void applyTransformations(const sf::Vector2f& _targetSize, sf::Sprite& _sprite);

		/// <summary>
		/// <paragraph>Applies transformation properties to the given rectangle shape before drawing.</paragraph>
		/// </summary>
		/// <param name="_target"></param>
		/// <param name="_sprite"></param>
		void applyTransformations(const sf::Vector2f& _targetSize, sf::Shape& _shape);

		/// <summary>
		/// <paragraph>Draws the background of the UI Element based on its background properties.</paragraph>
		/// </summary>
		/// <param name="_target"></param>
		/// <param name="_targetSize"></param>
		void drawBackground(sf::RenderTexture& _target, const sf::Vector2f& _targetSize);

		/// <summary>
		/// <paragraph>Initializes the UI Element. To be called during construction.</paragraph>
		/// </summary>
		virtual void Initialize() {};
	};
}