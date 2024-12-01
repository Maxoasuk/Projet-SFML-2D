#include "SceneManager.h"

#include "Level.h"

SceneManager* SceneManager::m_instance = nullptr;

SceneManager::SceneManager() : m_scenes({}), m_currentScene(nullptr) {
	if (m_instance == nullptr) {
		m_instance = this;
	}
}

Scene* SceneManager::getScene(std::string _key) {
	return this->m_scenes[_key];
}

Scene* SceneManager::getCurrentScene() {
	return this->m_currentScene;
}

void SceneManager::changesScene(std::string _key) {
	if (m_scenes.find(_key) == m_scenes.end()) {
		if (_key == "level") {
			Level* level = new Level();
			this->addScene(_key, level);
		}
	}
	this->m_currentScene = this->m_scenes[_key];
}

void SceneManager::addScene(std::string _key, Scene* _scene) {
	this->m_scenes.insert({ _key, _scene });
	if (m_currentScene == nullptr) {
		this->m_currentScene = _scene;
	}
}

SceneManager* SceneManager::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new SceneManager();
	}
	return m_instance;
}