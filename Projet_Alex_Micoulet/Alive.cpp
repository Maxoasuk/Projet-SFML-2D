#include "Alive.h"

Alive::Alive(float _life, float _invincibilityFrame) : 
	m_maxLife(_life), 
	m_currentLife(_life),
	m_invincibilityFrame(_invincibilityFrame),
	m_currentInvincibility(0) {}

float Alive::getMaxLife() {
	return this->m_maxLife;
}

float Alive::getCurrentLife() {
	return this->m_currentLife;
}

void Alive::decreaseInvincibilityFrame(float _time) {
	if (m_currentInvincibility > 0) {
		m_currentInvincibility -= _time;
	}
}

void Alive::takeDamage(float _dmg) {
	if (m_currentInvincibility <= 0) {
		this->m_currentLife -= _dmg;
		this->m_currentInvincibility = m_invincibilityFrame;
	}
}