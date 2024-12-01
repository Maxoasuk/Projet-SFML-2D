#ifndef CANNON_H__
#define CANNON_H__

#include "StaticObject.h"

class Cannon : public StaticObject {
	float m_maxShotCooldown;
	float m_shotCooldown;

public:
	Cannon(sf::Texture& _tex, sf::IntRect _rect, Level* _level, float _shotCooldown);
	virtual void update(float _time) override;
};

#endif

