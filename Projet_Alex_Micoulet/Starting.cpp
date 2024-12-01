#include "Starting.h"

#include <iostream>
#include "EntityGenerator.h"
#include "TextEntity.h"
#include "AnimatedEntity.h"
#include "SceneManager.h"
#include "Level.h"

void Starting::init() {
	if (!m_backgroundTexture.loadFromFile("back.png")) {
		std::cout << "Background not load" << std::endl;
	}
	m_entites.push_back(EntityGenerator::generatesBackgroundMenus(m_backgroundTexture));

	if (!m_font.loadFromFile("ARIAL.ttf"))
	{
		std::cout << "Erreur : font don't load" << std::endl;
	}
	if (!m_texture.loadFromFile("texture.png")) {
		std::cout << "Texture not load" << std::endl;
	}

	m_entites.push_back(EntityGenerator::generatesTextEntity(m_font, "Bat's Messy Adventure", 15, sf::Vector2f(0, -75)));
	m_entites.push_back(EntityGenerator::generatesBatMenus(m_texture, sf::Vector2f(0.f, 0.f)));
	m_entites.push_back(EntityGenerator::generatesTextEntity(m_font, "Appuyer sur espace", 10, sf::Vector2f(0, 25)));
}

void Starting::update(float _time) {
	Scene::update(_time);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		SceneManager* sceneManager = SceneManager::getInstance();
		sceneManager->changesScene("level");
		sceneManager->getCurrentScene()->init();
	}
}