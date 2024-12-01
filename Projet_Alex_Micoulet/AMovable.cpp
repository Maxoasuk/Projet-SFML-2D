#include "AMovable.h"

AMovable::AMovable(sf::Vector2f _direction, float _speed) : m_direction(_direction), m_speed(_speed) {}

void AMovable::setDirection(sf::Vector2f _dir) {
	this->m_direction = _dir;
}

void AMovable::setSpeed(float _speed) {
	this->m_speed = _speed;
}