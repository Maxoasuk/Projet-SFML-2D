#ifndef	BREAKABLEOBJECT_H__
#define BREAKABLEOBJECT_H__

#include "StaticObject.h"
#include "Alive.h"
#include "Scorable.h"

class BreakableObject : public StaticObject, public Alive, public Scorable {

public: 
	BreakableObject(sf::Texture& _tex, sf::IntRect _rect, Level* _level, float _life, int _pts);
	virtual void update(float _time) override;
};

#endif
