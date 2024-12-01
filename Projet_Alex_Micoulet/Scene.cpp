#include "Scene.h"

void Scene::clear() {
	for (int i = 0; i < m_entites.size(); ++i) {
		delete m_entites[i];
	}
	m_entites = {};
}

void Scene::update(float _time) {
	std::vector<Entity*> entitiesDelete;
	for (int i = 0; i < m_entites.size(); ++i) {
		m_entites[i]->update(_time);

		if (m_entites[i]->mustBeDestroy()) {
			entitiesDelete.push_back(m_entites[i]);
		}
	}

	m_entites.erase(std::remove_if(m_entites.begin(), m_entites.end(),
		[](Entity* _entity) {return _entity->mustBeDestroy(); }), m_entites.end());

	for (int i = 0; i < entitiesDelete.size(); ++i) {
		delete entitiesDelete[i];
	}
}

void Scene::addEntity(Entity* _entity) {
	this->m_entites.push_back(_entity);
}

void Scene::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
	for (int i = 0; i < m_entites.size(); ++i) {
		m_entites[i]->draw(_target, _states);
	}
}