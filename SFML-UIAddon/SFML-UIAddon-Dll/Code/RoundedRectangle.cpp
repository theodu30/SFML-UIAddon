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
			size_t cornerType = _index / m_pointsPerCorner;
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
			sf::Vector2f point;
			switch (cornerType)
			{
			case 0:
				point = { m_radius, m_radius };
				angle -= 180;
				break;
			case 1:
				point = { m_size.x - m_radius, m_radius };
				angle -= 90;
				break;
			case 2:
				point = { m_size.x - m_radius, m_size.y - m_radius };
				break;
			default:
				point = { m_radius, m_size.y - m_radius };
				angle += 90;
			}
			point += { cosf(angle * M_PI / 180) * m_radius, sinf(angle * M_PI / 180) * m_radius };
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

	void RoundedRectangle::setPointsPerCorner(float _points)
	{
		m_pointsPerCorner = _points;
		update();
	}

	int RoundedRectangle::getPointsPerCorner()
	{
		return m_pointsPerCorner;
	}
}