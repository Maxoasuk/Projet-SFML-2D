#include "TextEntity.h"

TextEntity::TextEntity(sf::Font& _font, std::string _text, int _characterSize) {
	m_text.setFont(_font);
	m_text.setString(_text);
	m_text.setCharacterSize(_characterSize);
	m_text.setPosition(-m_text.getLocalBounds().width / 2, -m_text.getLocalBounds().height / 2);
}

void TextEntity::changeText(std::string _text) {
	m_text.setString(_text);
}

sf::Text TextEntity::getText() {
	return m_text;
}

void TextEntity::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
	_states.transform = _states.transform.combine(this->getTransform());
	_target.draw(m_text, _states);
}