#include "Bat.h"

#include <iostream>
#include "EntityGenerator.h"
#include "SceneManager.h"
#include "Level.h"

Bat::Bat(sf::Texture& _tex, sf::IntRect _rect, float _frameTime, float _life, float _invincibilityFrame, float _speed, float _shotCooldown, Level* _level) :
	AnimatedEntity(_tex, sf::IntRect(21 * 23, 21 * 15 + 11, 21, 16), _frameTime),
	m_level(_level),
	Alive(_life, _invincibilityFrame),
	m_speed(_speed),
	m_shotCooldown(_shotCooldown),
	m_enterAnimation(Animation(sf::Vector2f(1.f, 0.f), _speed*1.5f, 1.5f)),
	m_deadAnimation(Animation(sf::Vector2f(1.f, 1.f), _speed, 2.f)) {
	m_enterAnimation.activate();
}

void Bat::shift(float _time) {
	sf::Vector2f oldPosition = this->getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getPosition().x > -89.5f) {
		this->move(-1.f * m_speed * _time, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getPosition().x < 89.5f) {
		this->move(1.f * m_speed * _time, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->getPosition().y > -89.5f) {
		this->move(0.f, -1.f * m_speed * _time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->getPosition().y < 89.5f) {
		this->move(0.f, 1.f * m_speed * _time);
	}

	if (m_level->isACollisionWithStaticObject(this)) {
		this->setPosition(oldPosition);
	}
}

void Bat::shoot(float _time) {

	if (m_shotCooldown <= 0.f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_shotCooldown += 0.5f;

		sf::Vector2f position = sf::Vector2f(this->getPosition().x, this->getPosition().y);
		m_level->addEntity(EntityGenerator::generatesBatBullet(m_level->getTexture(), position, this));
	}
	if (m_shotCooldown > 0.f) {
		m_shotCooldown -= _time;
	}
}

void Bat::checkLife(float _time) {
	if (this->getPosition().x < -140) {
		this->takeDamage(this->getCurrentLife());
	}
	if (this->getCurrentLife() <= 0) {
		this->setRectSprite(sf::IntRect(21 * 25 + 4, 21 * 15 + 11, 21, 16));
		m_deadAnimation.activate();
	}

	this->decreaseInvincibilityFrame(_time);
	if (m_deadAnimation.terminate()) {
		SceneManager* sceneManager = SceneManager::getInstance();
		sceneManager->changesScene("gameover");
	}
}

void Bat::update(float _time) {
	AnimatedEntity::update(_time);

	if (m_enterAnimation.isActive()) {
		m_enterAnimation.move(this, _time);
	}
	else if (m_deadAnimation.isActive()) {
		m_deadAnimation.move(this, _time);
	}
	else {
		this->shift(_time);
		this->shoot(_time);
	}

	this->checkLife(_time);
}

bool Bat::isDead() {
	return m_deadAnimation.isActive();
}