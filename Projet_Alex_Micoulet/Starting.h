#ifndef STARTING_H__
#define STARTING_H__

#include "Scene.h"

class Starting : public Scene {
	sf::Font m_font;
	sf::Texture m_texture;
	sf::Texture m_backgroundTexture;

public:
	virtual void init();
	virtual void update(float _time) override;
};

#endif