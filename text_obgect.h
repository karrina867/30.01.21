#pragma once
#include "SFML/Graphics.hpp"

class TextObj {
private:
	sf::Font font;
	sf::Text text;
public:
	TextObj(float x, float y) {
		font.loadFromFile("ds-digit.ttf");
		text.setFont(font);
		text.setFillColor(sf::Color::Yellow);
		text.setCharacterSize(46);
		text.setPosition(x, y);
	}
	void update(std::string str) { text.setString(str);}
	sf::Text  getText() { return text;}
};