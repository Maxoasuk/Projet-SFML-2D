#ifndef ENDINGFLAG_H__
#define ENDINGFLAG_H__

#include "AnimatedEntity.h"

class Level;

class EndingFlag : public AnimatedEntity {
	Level* m_level;

public:
	EndingFlag(sf::Texture& _tex, sf::IntRect _rect, float _frameTime, Level* _level);
	void update(float _time);
};

#endif