#include "decoration.h"



decoration::decoration(std::string fileName, int posX, int posY, float scaleX, float scaleY)
{
	this->fileName = fileName;
	sprite.setScale(scaleX, scaleY);
	sprite.setPosition(sf::Vector2f((float)posX, (float)posY));
	loadFile();
}

void decoration::loadFile()
{
	if (texture.loadFromFile("images/"+ fileName))
		sprite.setTexture(texture);

}

