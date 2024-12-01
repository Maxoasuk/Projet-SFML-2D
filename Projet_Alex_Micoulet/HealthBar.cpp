#include "HealthBar.h"

#include <iostream> 
#include "EntityGenerator.h"

HealthBar::HealthBar(sf::Texture& _tex, sf::Vector2f _position, sf::Vector2f _scale, Alive* _parent) : m_parent(_parent) {
	this->setPosition(_position);
	this->setScale(_scale);
	
	sf::Vector2f position = _position;
	for (int i = 0; i < _parent->getMaxLife(); i++) {
		m_hearts.push_back(EntityGenerator::generatesHeart(_tex, position, _scale));
		position.x += 22.f * _scale.y; 
	}
}

HealthBar::~HealthBar() {
	for (int i = 0; i < m_hearts.size(); i++) {
		delete m_hearts[i];
	}
}

void HealthBar::update(float _time) {
	if (m_parent) {
		for (int i = 0; i < m_hearts.size(); i++) {
			if (m_parent->getCurrentLife() < i + 1) {
				m_hearts[i]->setRectSprite(sf::IntRect(21 * 16 + 7, 21 * 13 + 5, 21, 21));
			}
		}
		Entity* entity = dynamic_cast<Entity*>(m_parent); 
		if (entity->mustBeDestroy()) {
			m_parent = nullptr;
		}
	}
}

void HealthBar::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
	for (int i = 0; i < m_hearts.size(); i++) {
		m_hearts[i]->draw(_target, _states);
	}
}