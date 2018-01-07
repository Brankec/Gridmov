#include "Map.h"

Map::Map(std::string fileName, int n, sf::Vector2i amountOfTiles, sf::Vector2i tileSize) : openfile("images/" + fileName + ".txt")
{
	this->powOfN = (int)pow(2, n);
	this->amountOfTiles = amountOfTiles;
	this->tileSize = tileSize;
	loadTiles();
	setOriginCenter();
}

void Map::setOriginCenter()
{
	tile.setOrigin(sf::Vector2f(tile.getSize().x / 2, tile.getSize().y / 2));
}

void Map::loadTiles()
{
	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;

		if (tileTexture.loadFromFile(tileLocation))
			tile.setTexture(&tileTexture);

		int tileIndex = 0;

		tile.setSize(sf::Vector2f((float)powOfN, (float)powOfN));
		while (openfile.good())
		{
			//int tileIndex;
			openfile >> tileIndex;
			tempMap.push_back(Sprite_sheet_coordinates(tileIndex));

			if (openfile.peek() == '\n')
			{
				map.push_back(tempMap);
				tempMap.clear();
			}
			
		}
	}
}

void Map::setTilePositions(sf::RenderWindow& window)
{
	
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1)
			{
				tile.setPosition(j * (float)powOfN, i * (float)powOfN);
				map[i][j];
				tile.setTextureRect(sf::IntRect(map[i][j].x / amountOfTiles.x, map[i][j].y * 0 /*/ amountOfTiles.y*/, tileSize.x / amountOfTiles.x, tileSize.y / amountOfTiles.y)); //map[i][j] holds coordinates/size of that index, not the index itself
				window.draw(tile);
			}
		}
	}
	
}

sf::Vector2i Map::Sprite_sheet_coordinates(int tileIndex) 
{
	sf::Vector2i coords;
	coords.x = (tileIndex % amountOfTiles.x) * tileSize.x;
	coords.y = (tileIndex / amountOfTiles.y) * tileSize.y;
	return coords;
}

