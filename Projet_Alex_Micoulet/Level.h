#ifndef LEVEL_H__
#define LEVEL_H__

#include "Scene.h"

class Level : public Scene {
	float m_levelTime;
	sf::Font m_font;
	sf::Texture m_texture;
	sf::Texture m_backgroundTexture;
	
	void attackerCollision(VisualEntity* _entity1, VisualEntity* _entity2, float _time);
	void batCollision(VisualEntity* _entity1, VisualEntity* _entity2, float _time);

public: 
	virtual void init();
	virtual void update(float _time) override;
	bool isContinue();
	sf::Texture& getTexture();

	bool isACollisionWithStaticObject(VisualEntity* _entity); 
};

#endif

