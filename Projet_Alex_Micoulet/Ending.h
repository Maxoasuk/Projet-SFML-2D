#ifndef ENDING_H__
#define ENDING_H__

#include "Scene.h"

class Ending : public Scene {
	sf::Font m_font;
	sf::Texture m_backgroundTexture;

public:
	virtual void init();
	virtual void update(float _time) override;
};

#endif