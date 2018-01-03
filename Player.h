#include <SFML\Graphics.hpp>
#include <math.h>
#include "PlasmaCannon.h"
#include "Projectile.h"
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

	void guns(std::vector<Projectile>& projectiles);
	void onUpdate(sf::Vector2f& velocity);
	void drawBullets(sf::RenderWindow& window, float angle, float dt);
	void preloadTexture();

public:
	sf::Texture artilleryTexture;

	sf::RectangleShape playerRec;
	sf::Texture playerTexture;

	sf::Texture healthTexture;
	sf::Sprite healthbar[5];

	PlasmaCannon cannon;

	std::string imageName;

	bool execute;

	int movDistance;
	std::string commands;
	int instructions = 0;
	int N_inst = 0;
	float angle = 0; //very important for artillery aim
	float rotation;

	std::vector<Projectile> projectiles;
	
	sf::Clock m_bulletTimer;

	int powOfN;

public:
	int health = 5;
};

