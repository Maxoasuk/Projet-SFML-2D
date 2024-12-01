#include "Bullet.h"

Bullet::Bullet(sf::Texture& _tex, sf::IntRect _rect, Entity* _parent, sf::Vector2f _direction, float _speed, float _dmg) :
	VisualEntity(_tex, _rect),
	m_parent(_parent),
	AMovable(_direction, _speed), 
	m_lifeCooldown(5.f), 
	m_dmg(_dmg) {}

void Bullet::update(float _time) {
	this->move(m_direction.x * m_speed * _time, m_direction.y * m_speed * _time);

	m_lifeCooldown -= _time;
	if (m_lifeCooldown <= 0.f) {
		this->destroy();
	}
}

void Bullet::attack(Alive* _target) {
	if (!isParent(dynamic_cast<Entity*>(_target))) {
		_target->takeDamage(m_dmg);
		this->destroy();
	}
}

bool Bullet::isParent(Entity* _target) {
	return m_parent != nullptr && _target == m_parent;
}