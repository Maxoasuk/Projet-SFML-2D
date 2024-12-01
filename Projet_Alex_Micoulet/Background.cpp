#include "Background.h"

Background::Background(sf::Texture& _tex, sf::IntRect _rect, sf::Vector2f _direction, float _speed, float* _timeToScroll) :
	VisualEntity(_tex, _rect), 
	AMovable(_direction, _speed), 
	m_timeToScroll(_timeToScroll) {}

void Background::update(float _time) {
	if (m_timeToScroll != nullptr) {
		if (*m_timeToScroll > 0.f) {
			this->move(m_direction.x * m_speed * _time, m_direction.y * m_speed * _time);
		}
	}
}