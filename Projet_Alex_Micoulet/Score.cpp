#include "Score.h"

Score::Score(sf::Font& _font, int _characterSize) :
	TextEntity(_font, "0", _characterSize), m_score(0) {}

void Score::update(float _time) {
	this->changeText(std::to_string(m_score));
}

void Score::increaseScore(int _pts) {
	m_score += _pts;
}