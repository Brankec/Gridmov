#include "Map.h"

Map::Map(std::string fileName, int n) : openfile("images/" + fileName + ".txt")
{
	this->powOfN = (int)pow(2, n);
	loadTiles();
	setOriginCenter();
}

void Map::setOriginCenter()
{
	tile.setOrigin(sf::Vector2f(tile.getSize().x / 2, tile.getSize().y / 2));
}

void Map::loadTiles()
{
	
	loadCounter = sf::Vector2i(0, 0);
	//openfile.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);
	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;

		if (tileTexture.loadFromFile(tileLocation))
			tile.setTexture(&tileTexture);

		int tileIndex = 0;

		tile.setSize(sf::Vector2f((float)powOfN, (float)powOfN));
		//openfile.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);
		while (openfile.good())
		{
			//int tileIndex;
			openfile >> tileIndex;
			//map[loadCounter.x][loadCounter.y] = Sprite_sheet_coordinates(tileIndex);

			if (openfile.peek() == '\n')
			{
				openfile.get();
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else
				loadCounter.x++;
		}
		loadCounter.y++;
		
	}
	
}

void Map::setTilePositions(sf::RenderWindow& window)
{
	
	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j < loadCounter.y; j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1)
			{
				tile.setPosition(i * (float)powOfN, j * (float)powOfN);
				tile.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
				//tile.setTextureRect(sf::IntRect(0, 0, 405, 411));
				window.draw(tile);
			}
		}
	}
	
}

sf::Vector2i Map::Sprite_sheet_coordinates(int tileIndex) 
{
	sf::Vector2i coords;
	coords.x = (tileIndex % 2) * 64;
	coords.y = (tileIndex / 2) * 64;
	return coords;
}

