#include "StaticObject.h"

StaticObject::StaticObject(sf::Texture& _tex, sf::IntRect _rect, Level* _level) :
	VisualEntity(_tex, _rect), m_level(_level) {}

void StaticObject::update(float _time) {
	if (m_level->isContinue()) {
		this->move(-1 * 15 * _time, 0);
	}

	if (this->getPosition().x < -140) {
		this->destroy();
	}
}