#include <SFML\Graphics.hpp>

#pragma once
class text
{
public:
	text();

public:
	void loadFont();
	void textPositionSpace();

public:
	sf::Text Text;
	sf::Font font;
};

