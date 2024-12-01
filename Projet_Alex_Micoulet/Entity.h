#ifndef ENTITY_H__
#define ENTITY_H__

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
	bool m_mustBeDestroy;

public:
	Entity();
	virtual bool mustBeDestroy();
	void destroy();
	virtual void update(float _time);
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const = 0;
};

#endif
