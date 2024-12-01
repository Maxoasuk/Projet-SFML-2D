#include "Mob.h"

Mob::Mob(sf::Texture& _tex, sf::IntRect _rect, float _frameTime, float _life, sf::Vector2f _direction, float _speed, int _pts) :
	AnimatedEntity(_tex, _rect, _frameTime), 
	Alive(_life, 0), 
	AMovable(_direction, _speed), 
	Scorable(_pts) {}

void Mob::update(float _time) {
	AnimatedEntity::update(_time);

	this->move(m_direction.x * m_speed * _time, m_direction.y * m_speed * _time);

	if (this->getCurrentLife() <= 0) {
		this->ptsMustBeGiven();
	}

	if (this->getPosition().x < -110) {
		this->destroy();
	}
}

void Mob::attack(Alive* _target) {
	_target->takeDamage(1.f);
}