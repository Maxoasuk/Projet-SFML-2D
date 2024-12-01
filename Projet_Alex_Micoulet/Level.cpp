#include "Level.h"

#include <iostream>
#include "IAttacker.h"
#include "EntityGenerator.h"
#include "SceneManager.h"

void Level::attackerCollision(VisualEntity* _entity1, VisualEntity* _entity2, float _time) {
	if (IAttacker* attacker = dynamic_cast<IAttacker*>(_entity1)) {
		if (Alive* aliveEntity = dynamic_cast<Alive*>(_entity2)) {

			sf::FloatRect aliveHitBox = _entity2->getHitBox();
			sf::FloatRect attackerHitBox = _entity1->getHitBox();

			if (aliveHitBox.intersects(attackerHitBox)) {					
				attacker->attack(aliveEntity);
			}
		}
		else if (dynamic_cast<StaticObject*>(_entity2)) {
			if (Bullet* bullet = dynamic_cast<Bullet*>(_entity1)) {

				sf::FloatRect staticObjectHitBox = _entity2->getHitBox();
				sf::FloatRect attackerHitBox = _entity1->getHitBox();

				if (staticObjectHitBox.intersects(attackerHitBox) && !bullet->isParent(_entity2)) {
					_entity1->destroy();
				}
			}
		}
	}
}

void Level::batCollision(VisualEntity* _entity1, VisualEntity* _entity2, float _time) {
	if (Bat* bat = dynamic_cast<Bat*>(_entity1)) {
		if (!bat->isDead()) {
			if (dynamic_cast<EndingFlag*>(_entity2)) {

				sf::FloatRect EndingFlagHitBox = _entity2->getHitBox();
				sf::FloatRect batHitBox = _entity1->getHitBox();

				if (EndingFlagHitBox.intersects(batHitBox)) {
					SceneManager* sceneManager = SceneManager::getInstance();
					sceneManager->changesScene("ending");
				}
			}
			else if (dynamic_cast<StaticObject*>(_entity2)) {

				sf::FloatRect StaticObjectHitBox = _entity2->getHitBox();
				sf::FloatRect batHitBox = _entity1->getHitBox();

				if (StaticObjectHitBox.intersects(batHitBox)) {
					_entity1->move(-1 * 15 * _time, 0);
				}
			}
		}
	}
}

void Level::init() {
	this->clear();
	m_levelTime = 20.f;

	if (!m_backgroundTexture.loadFromFile("city_background_night.png")) {
		std::cout << "Background not load" << std::endl;
	}
	m_entites.push_back(EntityGenerator::generatesBackgroundLevel(m_backgroundTexture, &m_levelTime));
	
	if (!m_font.loadFromFile("ARIAL.ttf"))
	{
		std::cout << "Erreur : font don't load" << std::endl;
	}

	m_entites.push_back(EntityGenerator::generatesScore(m_font, sf::Vector2f(85.f, -95.f)));

	if (!m_texture.loadFromFile("texture.png")) {
		std::cout << "Texture not load" << std::endl;
	}

	Bat* bat = EntityGenerator::generatesBat(m_texture, this, sf::Vector2f(-120.f, 0.f));
	m_entites.push_back(EntityGenerator::generatesHealthBar(m_texture, sf::Vector2f(-90, -90), bat));
	m_entites.push_back(bat); 

	m_entites.push_back(EntityGenerator::generatesFly(m_texture, sf::Vector2f(110, -70)));
	m_entites.push_back(EntityGenerator::generatesFly(m_texture, sf::Vector2f(135, -70)));
	m_entites.push_back(EntityGenerator::generatesFly(m_texture, sf::Vector2f(160, -70)));

	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(110, 100)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(110, 79)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(110, 58)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(110, 37)));

	m_entites.push_back(EntityGenerator::generatesSolidBlocInterior(m_texture, this, sf::Vector2f(130, 100)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocInterior(m_texture, this, sf::Vector2f(130, 79)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocInterior(m_texture, this, sf::Vector2f(130, 58)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocInterior(m_texture, this, sf::Vector2f(130, 37)));

	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(150, 100)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(150, 79)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(150, 58)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(150, 37)));

	m_entites.push_back(EntityGenerator::generatesCannon(m_texture, this, sf::Vector2f(150, 16)));

	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(220, 100)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(220, 79)));
	m_entites.push_back(EntityGenerator::generatesBreakableObjectExteriorLeft(m_texture, this, sf::Vector2f(220, 58)));
	m_entites.push_back(EntityGenerator::generatesBreakableObjectExteriorLeft(m_texture, this, sf::Vector2f(220, 37)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(220, 16)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorLeft(m_texture, this, sf::Vector2f(220, -5)));

	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(240, 100)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(240, 79)));
	m_entites.push_back(EntityGenerator::generatesBreakableObjectExteriorRight(m_texture, this, sf::Vector2f(240, 58)));
	m_entites.push_back(EntityGenerator::generatesBreakableObjectExteriorRight(m_texture, this, sf::Vector2f(240, 37)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(240, 16)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(240, -5)));

	m_entites.push_back(EntityGenerator::generatesCannon(m_texture, this, sf::Vector2f(240, -26)));

	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(350, 100)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(350, 79)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(350, 58)));
	m_entites.push_back(EntityGenerator::generatesSolidBlocExteriorRight(m_texture, this, sf::Vector2f(350, 37)));

	m_entites.push_back(EntityGenerator::generatesEndingFlag(m_texture, this, sf::Vector2f(360, 16)));
}

void Level::update(float _time) {
	Scene::update(_time);
	m_levelTime -= _time;

	for (int i = 0; i < m_entites.size(); ++i) {		
		for (int j = 0; j < m_entites.size(); ++j) {
			if (VisualEntity* entity1 = dynamic_cast<VisualEntity*>(m_entites[i])) {
				if (VisualEntity* entity2 = dynamic_cast<VisualEntity*>(m_entites[j])) {
					if (entity1 != entity2) {
						this->attackerCollision(entity1, entity2, _time);
						this->batCollision(entity1, entity2, _time);
					}
				}
			} 
			else if (Score* score = dynamic_cast<Score*>(m_entites[i])) {
				if (Scorable* scorable = dynamic_cast<Scorable*>(m_entites[j])) {
					if (scorable->mustGivePts()) {
						score->increaseScore(scorable->getPts());
						m_entites[j]->destroy();
					}
				}
			}
		}
	}
}

bool Level::isContinue() {
	return m_levelTime > 0;
}

sf::Texture& Level::getTexture() {
	return this->m_texture;
}

bool Level::isACollisionWithStaticObject(VisualEntity* _entity) {
	for (int i = 0; i < m_entites.size(); ++i) {
		if (StaticObject* staticObject = dynamic_cast<StaticObject*>(m_entites[i])) {
			if (_entity->getHitBox().intersects(staticObject->getHitBox())) {
				return true; 
			}
		}
	}
	return false;
}