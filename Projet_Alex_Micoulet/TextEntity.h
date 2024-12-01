#ifndef TEXTENTITY_H__
#define TEXTENTITY_H__

#include "Entity.h"

class TextEntity : public Entity {
	sf::Text m_text;

public: 
	TextEntity(sf::Font& _font, std::string _text, int _characterSize);
	void changeText(std::string _text);
	sf::Text getText();
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;
};

#endif