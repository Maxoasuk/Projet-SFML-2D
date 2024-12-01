#include "GameOver.h"

#include <iostream>
#include "EntityGenerator.h"
#include "SceneManager.h"

void GameOver::init() {
	if (!m_backgroundTexture.loadFromFile("back.png")) {
		std::cout << "Background not load" << std::endl;
	}
	m_entites.push_back(EntityGenerator::generatesBackgroundMenus(m_backgroundTexture));

	if (!m_font.loadFromFile("ARIAL.ttf"))
	{
		std::cout << "Erreur : font don't load" << std::endl;
	}

	m_entites.push_back(EntityGenerator::generatesTextEntity(m_font, "Vous êtes mort !", 15, sf::Vector2f(0, -25)));
	m_entites.push_back(EntityGenerator::generatesTextEntity(m_font, "Espace pour recommancer", 8, sf::Vector2f(0, 25)));
	m_entites.push_back(EntityGenerator::generatesTextEntity(m_font, "Entrer pour revenir à l'écran d'accueil", 8, sf::Vector2f(0, 18)));
}

void GameOver::update(float _time) {
	Scene::update(_time);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		SceneManager* sceneManager = SceneManager::getInstance();
		sceneManager->changesScene("level");
		sceneManager->getCurrentScene()->init();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		SceneManager* sceneManager = SceneManager::getInstance();
		sceneManager->changesScene("starting");
	}
}