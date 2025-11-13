#pragma once

#include "System/Exports.hpp"
#include "System/UIElementProperty.hpp"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <vector>
#include <concepts>
#include <type_traits>

namespace sfui
{
	class UIElement;

	template<typename T>
	concept UIElementSubClass = std::derived_from<T, UIElement>;

	template<typename T>
	concept UIElementProperty = std::derived_from<T, Property>;

	template<typename T>
	struct always_false : std::false_type {};

	class SFUIL_API UIElement
	{
	public:
		UIElement() = default;
		UIElement(const char* _name) : m_name(_name) {}
		virtual ~UIElement() = default;

		virtual void drawToTarget(sf::RenderTexture& _target) = 0;

		template<UIElementProperty T>
		T& getProperty()
		{
			markDirty();

			if constexpr (std::is_same_v<T, OpacityProperty>)
			{
				return m_opacity;
			}
			else if constexpr (std::is_same_v<T, DisplayProperty>)
			{
				return m_display;
			}
			else if constexpr (std::is_same_v<T, VisibilityProperty>)
			{
				return m_visibility;
			}
			else if constexpr (std::is_same_v<T, PositionProperty>)
			{
				return m_position;
			}
			else if constexpr (std::is_same_v<T, FlexProperty>)
			{
				return m_flex;
			}
			else if constexpr (std::is_same_v<T, AlignProperty>)
			{
				return m_align;
			}
			else if constexpr (std::is_same_v<T, SizeProperty>)
			{
				return m_size;
			}
			else if constexpr (std::is_same_v<T, SpacingProperty>)
			{
				return m_spacing;
			}
			else if constexpr (std::is_same_v<T, BackgroundProperty>)
			{
				return m_background;
			}
			else if constexpr (std::is_same_v<T, BorderProperty>)
			{
				return m_border;
			}
			else if constexpr (std::is_same_v<T, TransformProperty>)
			{
				return m_transform;
			}
			else
			{
				static_assert(always_false<T>::value, "Unsupported UIElementProperty type");
			}
		}

		template<UIElementProperty T>
		const T& getConstProperty() const
		{
			if constexpr (std::is_same_v<T, OpacityProperty>)
			{
				return m_opacity;
			}
			else if constexpr (std::is_same_v<T, DisplayProperty>)
			{
				return m_display;
			}
			else if constexpr (std::is_same_v<T, VisibilityProperty>)
			{
				return m_visibility;
			}
			else if constexpr (std::is_same_v<T, PositionProperty>)
			{
				return m_position;
			}
			else if constexpr (std::is_same_v<T, FlexProperty>)
			{
				return m_flex;
			}
			else if constexpr (std::is_same_v<T, AlignProperty>)
			{
				return m_align;
			}
			else if constexpr (std::is_same_v<T, SizeProperty>)
			{
				return m_size;
			}
			else if constexpr (std::is_same_v<T, SpacingProperty>)
			{
				return m_spacing;
			}
			else if constexpr (std::is_same_v<T, BackgroundProperty>)
			{
				return m_background;
			}
			else if constexpr (std::is_same_v<T, BorderProperty>)
			{
				return m_border;
			}
			else if constexpr (std::is_same_v<T, TransformProperty>)
			{
				return m_transform;
			}
			else
			{
				static_assert(always_false<T>::value, "Unsupported UIElementProperty type");
			}
		}

		void setName(const char* _name);

		const char* getName() const;

		[[nodiscard]] size_t getChildCount() const noexcept;

		bool addChild(UIElement* _child);

		bool removeFromParent();

		bool removeFromHierarchy();

		std::vector<UIElement*>& getChildren();

		sf::Vector2f getRenderSize() const;

		sf::Vector2f getRenderPosition() const;

		template<UIElementSubClass T>
		T* as()
		{
			return dynamic_cast<T*>(this);
		}

		template<UIElementSubClass T>
		T* as() const
		{
			return dynamic_cast<T*>(this);
		}

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
		const char* m_name = "UIElement";
		std::vector<UIElement*> m_children;
		UIElement* m_parent = nullptr;
		bool m_dirty = true;

		sf::Vector2f m_renderSize;
		sf::Vector2f m_renderPosition;

		OpacityProperty m_opacity;
		DisplayProperty m_display;
		VisibilityProperty m_visibility;
		PositionProperty m_position;
		FlexProperty m_flex;
		AlignProperty m_align;
		SizeProperty m_size;
		SpacingProperty m_spacing;
		BackgroundProperty m_background;
		BorderProperty m_border;
		TransformProperty m_transform;

		void markDirty();

		virtual void reRenderIfDirty(sf::RenderTexture& _texture) = 0;

		void computePosition(const sf::Vector2f& _targetSize, const sf::FloatRect& _bounds);

		void applyTransformations(const sf::Vector2f& _targetSize, sf::Sprite& _sprite);

		void applyTransformations(const sf::Vector2f& _targetSize, sf::Shape& _shape);

		void drawBackground(sf::RenderTexture& _target, const sf::Vector2f& _targetSize);

		virtual void Initialize() {};
	};
}