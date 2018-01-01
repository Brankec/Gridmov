#include "decoration.h"



decoration::decoration(std::string fileName, int posX, int posY, float scaleX, float scaleY)
{
	this->fileName = fileName;

	loadFile();
}

void decoration::loadFile()
{
	if (texture.loadFromFile("images/"+ fileName + ".png"))
		sprite.setTexture(texture);

}

