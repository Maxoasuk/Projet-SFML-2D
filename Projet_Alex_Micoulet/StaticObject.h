#ifndef STATICOBJECT_H__
#define STATICOBJECT_H__

#include "VisualEntity.h"
#include "Level.h"

class StaticObject : public VisualEntity {

protected: 
	Level* m_level;

public: 
	StaticObject(sf::Texture& _tex, sf::IntRect _rect, Level* _level);
	virtual void update(float _time) override;
};

#endif

