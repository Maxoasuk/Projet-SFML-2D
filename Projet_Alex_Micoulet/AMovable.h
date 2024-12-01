#ifndef AMOVABLE_H__
#define AMOVABLE_H__

#include <SFML/Graphics.hpp>

class AMovable {
protected:
	sf::Vector2f m_direction;
	float m_speed;

public:
	AMovable(sf::Vector2f _direction, float _speed);
	void setDirection(sf::Vector2f _dir);
	void setSpeed(float _speed);
};

#endif
