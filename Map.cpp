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

	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;

		if(tileTexture.loadFromFile(tileLocation))
		tile.setTexture(&tileTexture);

		tile.setSize(sf::Vector2f((float)powOfN, (float)powOfN));
		while (!openfile.eof())
		{
			std::string str;
			openfile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			else
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');

			if (openfile.peek() == '\n')
			{
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
				//tile.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
				tile.setTextureRect(sf::IntRect(0, 0, 405, 411));
				window.draw(tile);
			}
		}
	}
}

