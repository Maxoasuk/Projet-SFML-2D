#ifndef ENTITYGENERATOR_H__
#define ENTITYGENERATOR_H__

#include "Bat.h"
#include "Bullet.h"
#include "Mob.h"
#include "Cannon.h"
#include "BreakableObject.h"
#include "HealthBar.h"
#include "Score.h"
#include "EndingFlag.h"
#include "Background.h"

class EntityGenerator {
	
public: 
	static Background* generatesBackgroundMenus(sf::Texture& _tex);
	static Background* generatesBackgroundLevel(sf::Texture& _tex, float* _levelTime);
	static TextEntity* generatesTextEntity(sf::Font& _font, std::string _text, int _characterSize, sf::Vector2f _position);
	static Bat* generatesBat(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
	static AnimatedEntity* generatesBatMenus(sf::Texture& _tex, sf::Vector2f _position);
	static Bullet* generatesBatBullet(sf::Texture& _tex, sf::Vector2f _position, Bat* _parent);
	static Mob* generatesFly(sf::Texture& _tex, sf::Vector2f _position);
	static Cannon* generatesCannon(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
	static Bullet* generatesCannonBullet(sf::Texture& _tex, sf::Vector2f _position, Cannon* _parent);
	static StaticObject* generatesSolidBlocExteriorLeft(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
	static StaticObject* generatesSolidBlocInterior(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
	static StaticObject* generatesSolidBlocExteriorRight(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
	static BreakableObject* generatesBreakableObjectExteriorLeft(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
	static BreakableObject* generatesBreakableObjectExteriorRight(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
	static Score* generatesScore(sf::Font& _font, sf::Vector2f _position);
	static HealthBar* generatesHealthBar(sf::Texture& _tex, sf::Vector2f _position, Alive* _parent);
	static VisualEntity* generatesHeart(sf::Texture& _tex, sf::Vector2f _position, sf::Vector2f _scale);
	static EndingFlag* generatesEndingFlag(sf::Texture& _tex, Level* _level, sf::Vector2f _position);
};

#endif
