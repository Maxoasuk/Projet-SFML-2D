#include "BreakableObject.h"

BreakableObject::BreakableObject(sf::Texture& _tex, sf::IntRect _rect, Level* _level, float _life, int _pts) :
	StaticObject(_tex, _rect, _level),
	Alive(_life, 0.f),
	Scorable(_pts) {}

void BreakableObject::update(float _time) {
	StaticObject::update(_time);

	if (this->getCurrentLife() <= 0) {
		this->ptsMustBeGiven();
	}
}
