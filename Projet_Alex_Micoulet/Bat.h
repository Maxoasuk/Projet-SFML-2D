#ifndef BAT_H__
#define BAT_H__

#include "AnimatedEntity.h"
#include "Alive.h"
#include "Animation.h"
#include "Level.h"

class Bat : public AnimatedEntity, public Alive {
	float m_speed;
	float m_shotCooldown;
	Animation m_enterAnimation;
	Animation m_deadAnimation;
	Level* m_level;

	void shift(float _time);
	void shoot(float _time);
	void checkLife(float _time);

public: 
	Bat(sf::Texture& _tex, sf::IntRect _rect, float _frameTime, float _life, float _invincibilityFrame, float _speed, float shotCooldown, Level* _level);
	void update(float _time);
	bool isDead();
};

#endif
