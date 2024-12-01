#include "VisualEntity.h"

VisualEntity::VisualEntity(sf::Texture& _tex, sf::IntRect _rect) : Entity() {
	m_sprite.setTexture(_tex);
	this->setRectSprite(_rect);
	m_sprite.setPosition(-m_sprite.getLocalBounds().width / 2, -m_sprite.getLocalBounds().height / 2);
}

void VisualEntity::setRectSprite(sf::IntRect _rect) {
	m_sprite.setTextureRect(_rect);
}

sf::Sprite VisualEntity::getSprite() {
	return this->m_sprite;
}

float VisualEntity::getWidth() {
	return this->getSprite().getLocalBounds().getSize().x* this->getScale().x;
}

sf::FloatRect VisualEntity::getHitBox() {
	sf::FloatRect hitbox = this->getSprite().getLocalBounds();
	hitbox.left += this->getPosition().x;
	hitbox.top += this->getPosition().y;
	return hitbox;
}

void VisualEntity::setColor(sf::Color _color) {
	m_sprite.setColor(_color);
}

void VisualEntity::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
	_states.transform = _states.transform.combine(this->getTransform());
	_target.draw(m_sprite, _states);
}