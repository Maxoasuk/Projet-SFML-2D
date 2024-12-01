#ifndef HEALTHBAR_H__
#define HEALTHBAR_H__

#include "VisualEntity.h"
#include "Alive.h"

class HealthBar : public Entity {
	std::vector<VisualEntity*> m_hearts;
	Alive* m_parent; 

public: 
	HealthBar(sf::Texture& _tex, sf::Vector2f _position, sf::Vector2f _scale, Alive* _parent);
	~HealthBar();
	virtual void update(float _time) override;
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const; 
};

#endif
