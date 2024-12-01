#ifndef GAMEOVER_H__
#define GAMEOVER_H__

#include "Scene.h"

class GameOver : public Scene {
	sf::Font m_font;
	sf::Texture m_backgroundTexture;

public:
	virtual void init();
	virtual void update(float _time) override;
};

#endif