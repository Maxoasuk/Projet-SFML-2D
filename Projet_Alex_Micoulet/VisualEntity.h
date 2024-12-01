#ifndef VISUALENTITY_H__
#define VISUALENTITY_H__

#include "Entity.h"

class VisualEntity : public Entity {
	sf::Sprite m_sprite;

public: 
	VisualEntity(sf::Texture& _tex, sf::IntRect _rect);
	void setRectSprite(sf::IntRect _rect);
	sf::Sprite getSprite();
	float getWidth();
	sf::FloatRect getHitBox();
	void setColor(sf::Color _color);
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;
};

#endif
