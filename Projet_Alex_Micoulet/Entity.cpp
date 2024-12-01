#include "Entity.h"

Entity::Entity() : m_mustBeDestroy(false) {
}

bool Entity::mustBeDestroy() {
	return this->m_mustBeDestroy;
}

void Entity::destroy() {
	m_mustBeDestroy = true;
}

void Entity::update(float _time) {}