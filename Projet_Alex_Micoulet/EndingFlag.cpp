#include "EndingFlag.h"

#include "Level.h"
#include "SceneManager.h"

EndingFlag::EndingFlag(sf::Texture& _tex, sf::IntRect _rect, float _frameTime, Level* _level) :
	AnimatedEntity(_tex, _rect, _frameTime), 
	m_level(_level) {}

void EndingFlag::update(float _time) {
	AnimatedEntity::update(_time);

	if (m_level->isContinue()) {
		this->move(-1 * 15 * _time, 0);
	}
}