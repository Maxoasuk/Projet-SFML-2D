#ifndef BULLET_H__
#define BULLET_H__

#include "VisualEntity.h"
#include "AMovable.h"
#include "IAttacker.h"

class Bullet : public VisualEntity, public AMovable, public IAttacker {
	float m_lifeCooldown;
	float m_dmg;
	Entity* m_parent;

public: 
	Bullet(sf::Texture& _tex, sf::IntRect _rect, Entity* _parent, sf::Vector2f _direction, float _speed, float _dmg);
	virtual void update(float _time) override;
	virtual void attack(Alive* _target);
	bool isParent(Entity* _target);
};

#endif