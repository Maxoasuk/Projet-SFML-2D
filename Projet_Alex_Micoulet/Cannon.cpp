#include "Cannon.h"

#include <iostream>
#include "EntityGenerator.h"	

Cannon::Cannon(sf::Texture& _tex, sf::IntRect _rect, Level* _level, float _shotCooldown) :
	StaticObject(_tex, _rect, _level), m_maxShotCooldown(_shotCooldown), m_shotCooldown(_shotCooldown) {}

void Cannon::update(float _time) {
	StaticObject::update(_time);

	if (m_shotCooldown <= 0.f) {
		m_shotCooldown += m_maxShotCooldown;

		sf::Vector2f position = sf::Vector2f(this->getPosition().x, this->getPosition().y);
		m_level->addEntity(EntityGenerator::generatesCannonBullet(m_level->getTexture(), position, this));
	}
	else {
		m_shotCooldown -= _time;
	}
}