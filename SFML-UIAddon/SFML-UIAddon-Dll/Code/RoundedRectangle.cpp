#include "Headers/SFUIL/Graphics/RoundedRectangle.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

namespace sfui
{
	size_t RoundedRectangle::getPointCount() const
	{
		return m_pointsPerCorner * 4;
	}

	sf::Vector2f RoundedRectangle::getPoint(size_t _index) const
	{
		// If no rounding (radius is 0) or only 1 point per corner, return regular rectangle points
		if (m_pointsPerCorner == 1 || m_radius == 0.0f)
		{
			sf::RectangleShape rect(m_size);
			return rect.getPoint(_index);
		}
		// Otherwise, calculate rounded corner points
		else
		{
			// Cap radius to half the smallest dimension if m_radius is too large
			float finalRadius = std::min(std::min(m_size.x, m_size.y) / 2.0f, m_radius);
			// Calculate angle for the current point
			float angle = 0;
			bool isLastPointOnCorner = (_index % m_pointsPerCorner == m_pointsPerCorner - 1);
			if (isLastPointOnCorner)
			{
				angle = 90.0f;
			}
			else
			{
				angle = (_index % m_pointsPerCorner) * 90.f / m_pointsPerCorner;
			}
			// Determine which corner we are in and adjust the base point and angle accordingly
			sf::Vector2f point;
			size_t cornerType = _index / m_pointsPerCorner;
			switch (cornerType)
			{
			case 0: // Top-left corner
				point.x = finalRadius;
				point.y = finalRadius;
				angle -= 180;
				break;
			case 1: // Top-right corner
				point.x = m_size.x - finalRadius;
				point.y = finalRadius;
				angle -= 90;
				break;
			case 2: // Bottom-right corner
				point.x = m_size.x - finalRadius;
				point.y = m_size.y - finalRadius;
				break;
			default: // Bottom-left corner (could be case 3)
				point.x = finalRadius;
				point.y = m_size.y - finalRadius;
				angle += 90;
			}
			point.x += cosf(angle * M_PI / 180) * finalRadius;
			point.y += sinf(angle * M_PI / 180) * finalRadius;
			return point;
		}
	}

	void RoundedRectangle::setSize(sf::Vector2f _size)
	{
		m_size = _size;
		update();
	}

	sf::Vector2f RoundedRectangle::getSize()
	{
		return m_size;
	}

	void RoundedRectangle::setRadius(float _radius)
	{
		m_radius = _radius;
		update();
	}

	float RoundedRectangle::getRadius()
	{
		return m_radius;
	}

	void RoundedRectangle::setPointsPerCorner(size_t _points)
	{
		m_pointsPerCorner = _points;
		update();
	}

	size_t RoundedRectangle::getPointsPerCorner()
	{
		return m_pointsPerCorner;
	}
}