#include <SFML\Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

#pragma once
class Map
{
public:
	Map(std::string fileName, int n);

public:
	void loadTiles();
	void setTilePositions(sf::RenderWindow& window);
	void setOriginCenter();

public:
	int powOfN;
	sf::Texture tileTexture;
	sf::RectangleShape tile;

	sf::Vector2i map[100][100]; //ok
	sf::Vector2i loadCounter;

	//open the file containing the tile name and tile positions
	std::ifstream openfile;
};

