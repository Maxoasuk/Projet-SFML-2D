#include "AnimatedEntity.h"

#include <iostream>

AnimatedEntity::AnimatedEntity(sf::Texture& _tex, sf::IntRect _rect, float _frameTime) :
	VisualEntity(_tex, _rect),
	m_actualSprite(0),
	m_maxFrameTime(_frameTime),
	m_frameTime(_frameTime) {
	m_sprites.push_back(_rect);
}

void AnimatedEntity::addSprite(sf::IntRect _rect) {
	m_sprites.push_back(_rect);
}

void AnimatedEntity::nextSprite() {
	m_actualSprite += 1;
	if (m_actualSprite == m_sprites.size()) {
		m_actualSprite = 0;
	}
	this->setRectSprite(m_sprites[m_actualSprite]);
}

void AnimatedEntity::update(float _time) {
	m_frameTime -= _time;
	if (m_frameTime <= 0) {
		this->nextSprite();
		m_frameTime += m_maxFrameTime;
	}
}