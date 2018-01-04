#include <SFML\Graphics.hpp>
#include <math.h>
#include "PlasmaCannon.h"
#include "Projectile.h"
#include "PlasmaAutomatic.h"
#include "TextureResources.h"

#pragma once
class Player
{
public:
	Player(int PosX, int PosY, int n, std::string imageName);

public:
	void image();
	void setOriginCenter();
	void execution(float dt);
	float lerp(float v0, float v1, float t);

	void drawHealth(sf::RenderWindow& window);
	void hurt(int n);
	void heal(int n);

	void healthbarPositionnit();

	void drawProjectile(sf::RenderWindow& window, float angle, float dt);
	void preloadTexture();

public:
	sf::Texture artilleryTexture;

	sf::RectangleShape playerRec;
	sf::Texture playerTexture;

	sf::Texture healthTexture;
	sf::RectangleShape healthbar;

	//artillery
	PlasmaCannon cannon;
	PlasmaAutomatic automatic;

	std::string imageName;

	bool execute;

	int movDistance;
	std::string commands;
	int instructions = 0;
	int N_inst = 0;
	float angle = 0; //very important for artillery aim
	float rotation;


	int powOfN;

public:
	float health = 125;
};

