#include <SFML\Graphics.hpp>
#include <iostream>
#include <array>
#include <cctype>
#include <map>
#include <vector>
#include <string>
#include <fstream>

#pragma once
class Map
{
public:
	Map(std::string fileName, int n, sf::Vector2i amountOfTiles, sf::Vector2i tileSize);

public:
	void loadTiles();
	void setTilePositions(sf::RenderWindow& window);
	void setOriginCenter();
	sf::Vector2i Sprite_sheet_coordinates(int tileIndex);

public:
	int powOfN;
	sf::Texture tileTexture;
	sf::RectangleShape tile;

	std::vector<std::vector<sf::Vector2i>> map; 
	std::vector<sf::Vector2i> tempMap;
	sf::Vector2i loadCounter;
	sf::Vector2i tileSize;
	sf::Vector2i amountOfTiles;

	//open the file containing the tile name and tile positions
	std::ifstream openfile;
};

