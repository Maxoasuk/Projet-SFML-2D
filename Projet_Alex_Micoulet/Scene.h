#ifndef SCENE_H__
#define SCENE_H__

#include "Entity.h"
#include "Background.h"

class Scene : public sf::Drawable {
protected:
	std::vector<Entity*> m_entites;

public:
	virtual void init() = 0;
	void clear();
	virtual void update(float _time);
	void addEntity(Entity* _entity);
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;
};

#endif

