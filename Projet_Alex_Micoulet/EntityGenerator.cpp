#include "EntityGenerator.h"

Background* EntityGenerator::generatesBackgroundMenus(sf::Texture& _tex) {
	sf::IntRect rect = sf::IntRect(0, 0, _tex.getSize().x, _tex.getSize().y);
	Background* background = new Background(_tex, rect, sf::Vector2f(0.f, 0.f), 0.f, nullptr);
	background->scale(0.2f, 0.2f);
	return background;
}

Background* EntityGenerator::generatesBackgroundLevel(sf::Texture& _tex, float* _levelTime) {
	sf::IntRect rect = sf::IntRect(0, 0, _tex.getSize().x, _tex.getSize().y);
	Background* background = new Background(_tex, rect, sf::Vector2f(-1.f, 0.f), 8.f, _levelTime);
	background->scale(0.2f, 0.2f);
	background->setPosition(background->getWidth() / 2 - 100.f, 0.f);
	return background;
}

TextEntity* EntityGenerator::generatesTextEntity(sf::Font& _font, std::string _text, int _characterSize, sf::Vector2f _position) {
	TextEntity* textEntity = new TextEntity(_font, _text, _characterSize);
	textEntity->setPosition(_position);
	return textEntity;
}

Bat* EntityGenerator::generatesBat(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect firstSprite = sf::IntRect(21 * 23, 21 * 15 + 11, 21, 16);
	sf::IntRect secondeSprite = sf::IntRect(21 * 24, 21 * 15 + 11, 21, 16);
	Bat* bat = new Bat(_tex, firstSprite, 0.5f, 3.f, 1.f, 50.f, 0.8f, _level);
	bat->scale(-1.f, bat->getScale().y);
	bat->addSprite(secondeSprite);
	bat->setPosition(_position);
	return bat;
}

AnimatedEntity* EntityGenerator::generatesBatMenus(sf::Texture& _tex, sf::Vector2f _position) {
	sf::IntRect firstSprite = sf::IntRect(21 * 23, 21 * 15 + 11, 21, 16);
	sf::IntRect secondeSprite = sf::IntRect(21 * 24, 21 * 15 + 11, 21, 16);
	AnimatedEntity* bat = new AnimatedEntity(_tex, firstSprite, 0.5f);
	bat->addSprite(secondeSprite);
	bat->scale(-1.f, bat->getScale().y);
	bat->setPosition(_position);
	return bat;
}

Bullet* EntityGenerator::generatesBatBullet(sf::Texture& _tex, sf::Vector2f _position, Bat* _parent) {
	sf::IntRect bulletRect = sf::IntRect(21 * 29 + 13, 21 * 10 + 10, 21, 14);
	Bullet* bullet = new Bullet(_tex, bulletRect, _parent, sf::Vector2f(1.f, 0.f), 250.f, 10.f);
	bullet->setPosition(_position);
	bullet->setScale(0.5f, 0.5f);
	bullet->setColor(sf::Color(128, 128, 128));
	return bullet;
}

Mob* EntityGenerator::generatesFly(sf::Texture& _tex, sf::Vector2f _position) {
	sf::IntRect firstSprite = sf::IntRect(21 * 22, 21 * 11, 21, 16);
	sf::IntRect secondSprite = sf::IntRect(21 * 23, 21 * 11, 21, 16);
	Mob* fly = new Mob(_tex, firstSprite, 0.2f, 20.f, sf::Vector2f(-1.f, 0.f), 20.f, 50);
	fly->addSprite(secondSprite);
	fly->scale(0.75f, 0.75f);
	fly->setPosition(_position);
	return fly;
}

Cannon* EntityGenerator::generatesCannon(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect cannonRect = sf::IntRect(21 * 20 - 5, 21 * 31 - 5, 21, 21);
	Cannon* cannon = new Cannon(_tex, cannonRect, _level, 3.f);
	cannon->setPosition(_position);
	return cannon;
}

Bullet* EntityGenerator::generatesCannonBullet(sf::Texture& _tex, sf::Vector2f _position, Cannon* _parent) {
	sf::IntRect bulletRect = sf::IntRect(21 * 30 - 8, 21 * 27 -14, 21, 21);
	Bullet* bullet = new Bullet(_tex, bulletRect, _parent, sf::Vector2f(-1.f, 0.f), 100.f, 1.f);
	bullet->setPosition(_position);
	bullet->setScale(0.5f, 0.5f);
	return bullet;
}

StaticObject* EntityGenerator::generatesSolidBlocExteriorLeft(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect objectRect = sf::IntRect(21 * 3 + 5, 21 * 25 + 5, 21, 21);
	StaticObject* bloc = new StaticObject(_tex, objectRect, _level); 
	bloc->setPosition(_position);
	return bloc;
}

StaticObject* EntityGenerator::generatesSolidBlocExteriorRight(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect objectRect = sf::IntRect(21 * 5 + 8, 21 * 25 + 5, 21, 21);
	StaticObject* bloc = new StaticObject(_tex, objectRect, _level);
	bloc->setPosition(_position);
	return bloc;
}

StaticObject* EntityGenerator::generatesSolidBlocInterior(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect objectRect = sf::IntRect(21 * 4 + 6, 21 * 25 + 5, 21, 21);
	StaticObject* bloc = new StaticObject(_tex, objectRect, _level);
	bloc->setPosition(_position);
	return bloc;
}

BreakableObject* EntityGenerator::generatesBreakableObjectExteriorLeft(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect objectRect = sf::IntRect(21 * 3 + 5, 21 * 25 + 5, 21, 21);
	BreakableObject* bloc = new BreakableObject(_tex, objectRect, _level, 20.f, 5);
	bloc->setPosition(_position);
	return bloc;
}

BreakableObject* EntityGenerator::generatesBreakableObjectExteriorRight(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect objectRect = sf::IntRect(21 * 5 + 8, 21 * 25 + 5, 21, 21);
	BreakableObject* bloc = new BreakableObject(_tex, objectRect, _level, 20.f, 5);
	bloc->setPosition(_position);
	return bloc;
}

Score* EntityGenerator::generatesScore(sf::Font& _font, sf::Vector2f _position) {
	Score* score = new Score(_font, 8);
	score->setPosition(_position);
	return score;
}

HealthBar* EntityGenerator::generatesHealthBar(sf::Texture& _tex, sf::Vector2f _position, Alive* _parent) {
	HealthBar* healthBar = new HealthBar(_tex, _position, sf::Vector2f(0.5f, 0.5f), _parent);
	return healthBar;
}

VisualEntity* EntityGenerator::generatesHeart(sf::Texture& _tex, sf::Vector2f _position, sf::Vector2f _scale) {
	VisualEntity* heart = new VisualEntity(_tex, sf::IntRect(21 * 14 + 5, 21 * 13 + 5, 21, 21));
	heart->setScale(_scale);
	heart->setPosition(_position);
	return heart;
}

EndingFlag* EntityGenerator::generatesEndingFlag(sf::Texture& _tex, Level* _level, sf::Vector2f _position) {
	sf::IntRect firstSprite = sf::IntRect(21 * 13 + 5, 21 * 11, 21, 21);
	sf::IntRect secondSprite = sf::IntRect(21 * 13 + 5, 21 * 12 + 2, 21, 21);
	EndingFlag* endingFlag = new EndingFlag(_tex, firstSprite, 0.2f, _level);
	endingFlag->addSprite(secondSprite);
	endingFlag->setPosition(_position);
	return endingFlag;
}