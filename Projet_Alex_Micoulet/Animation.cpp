#include "Animation.h"

Animation::Animation(sf::Vector2f _direction, float _speed, float _animationTime) :
	AMovable(_direction, _speed), m_maxAnimationTime(_animationTime), m_animationTime(_animationTime), m_isActive(false) {}

bool Animation::isActive() {
	if (this->terminate()) {
		m_isActive = false;
	}
	return m_isActive;
}

bool Animation::terminate() {
	return m_animationTime <= 0.f;
}

void Animation::activate() {
	m_isActive = true;
}

void Animation::move(Entity* _entity, float _time) {
	m_animationTime -= _time;
	_entity->move(m_direction.x * m_speed * _time, m_direction.y * m_speed * _time);
}

void Animation::restart() {
	m_animationTime = m_maxAnimationTime;
}