#include <SFML\Graphics.hpp>
#include <math.h>
#include <string>

#pragma once
class decoration
{
public:
	decoration(std::string fileName, int posX = 0, int posY = 0, float scaleX = 1, float scaleY = 1);

public:
	void loadFile();

public:
	std::string fileName;
	sf::Texture texture;
	sf::Sprite sprite;
};

