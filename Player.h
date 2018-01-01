#include <SFML\Graphics.hpp>

#pragma once
class Player
{
public:
	Player(int PosX, int PosY, sf::Vector2f size, std::string imageName);

public:
	void image();
	void setOriginCenter();
	void execution();

	void Triangular_move();

public:
	sf::RectangleShape playerRec;
	sf::Texture playerTexture;
	std::string imageName;

	bool execute = false;

	int movDistance = 59;
	int direction = 0;
	std::string commands;
	int instructions = 0;
	int N_inst = 0;
	int forward = 0;
	float angle = 0;

//for Triangular move
public:
	float distance = 400;
	float distanceDECELERATION = 0;
	float distanceACCELERATION = 0;
	float time = 3;
	float timeHALF;
	float velocityAVG = 0;
	float velocityMAX = 0;
	float velocityMIN = 0;
	float acceleration = 0;
	float deceleration = 0;
};

