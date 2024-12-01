#ifndef BACKGROUND_H__
#define BACKGROUND_H__

#include "VisualEntity.h"
#include "AMovable.h"

class Background : public VisualEntity, public AMovable {
	float* m_timeToScroll;

public: 
	Background(sf::Texture& _tex, sf::IntRect _rect, sf::Vector2f _direction, float _speed, float* _timeToScroll);
	void update(float _time);
};

#endif