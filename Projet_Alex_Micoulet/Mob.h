#ifndef MOB_H__
#define MOB_H__

#include "AnimatedEntity.h"
#include "AMovable.h"
#include "IAttacker.h"
#include "Scorable.h"
#include "Alive.h"

class Mob : public AnimatedEntity, public IAttacker, public Alive, public AMovable, public Scorable {

public: 
	Mob(sf::Texture& _tex, sf::IntRect _rect, float _frameTime, float _life, sf::Vector2f _direction, float _speed, int _pts);
	virtual void update(float _time) override;
	virtual void attack(Alive* _target);
};

#endif