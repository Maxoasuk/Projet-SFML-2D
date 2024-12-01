#ifndef SCORE_H__
#define SCORE_H__

#include "TextEntity.h"

class Score : public TextEntity {
	int m_score;

public:
	Score(sf::Font& _font, int _characterSize);
	virtual void update(float _time) override;
	void increaseScore(int _pts);
};

#endif
