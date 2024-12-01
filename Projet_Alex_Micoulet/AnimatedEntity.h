#ifndef ANIMATEDENTITY_H__
#define ANIMATEDENTITY_H__

#include "VisualEntity.h"

class AnimatedEntity : public VisualEntity {
	std::vector<sf::IntRect> m_sprites;
	int m_actualSprite;
	float m_maxFrameTime; 
	float m_frameTime;

public:
	AnimatedEntity(sf::Texture& _tex, sf::IntRect _rect, float _frameTime);
	void addSprite(sf::IntRect _rect);
	void nextSprite();
	virtual void update(float _time) override;
};

#endif