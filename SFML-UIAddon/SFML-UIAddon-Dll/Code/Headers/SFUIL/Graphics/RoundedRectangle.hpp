#pragma once

#include "../System/Exports.hpp"
#include <SFML/Graphics/Shape.hpp>

namespace sfui
{
	class SFUIL_API RoundedRectangle : public sf::Shape
	{
    public:
        virtual size_t getPointCount() const override;

        virtual sf::Vector2f getPoint(size_t _index) const override;

        void setSize(sf::Vector2f _size);

        sf::Vector2f getSize();

        void setRadius(float _radius);

        float getRadius();

        void setPointsPerCorner(size_t _points);

        size_t getPointsPerCorner();

    private:
        size_t m_pointsPerCorner = 2;
        float m_radius = 1.0f;
        sf::Vector2f m_size;
	};
}