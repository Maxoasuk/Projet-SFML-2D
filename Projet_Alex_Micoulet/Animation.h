#ifndef ANIMATION_H__
#define ANIMATION_H__

#include "AMovable.h"
#include "Entity.h"

class Animation : public AMovable {
	float m_maxAnimationTime;
	float m_animationTime;
	bool m_isActive;

public:
	Animation(sf::Vector2f _direction, float _speed, float _animationTime);
	bool isActive();
	bool terminate();
	void activate();
	void move(Entity* _entity, float _time);
	void restart();
};

#endif