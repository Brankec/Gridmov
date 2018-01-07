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
	void sound();
	void image();
	void setOriginCenter();
	void execution(float dt);
	float lerp(float v0, float v1, float t);

	void drawHealth(sf::RenderWindow& window);
	void drawFuel(sf::RenderWindow& window, float dt);
	void hurt(float n);
	void heal(float n);
	void replenishFuel(float n);
	void drainFuel(float n);
	void NoFuel(bool set);
	void drawWarningFuel(sf::RenderWindow& window, float dt);

	void healthbarPositionnit();

	void drawProjectile(sf::RenderWindow& window);
	void update(float angle, float dt);

	void WallCollisionDetection();

public:
	sf::RectangleShape playerRec;
	sf::Texture playerTexture;

	sf::Texture healthTexture;
	sf::RectangleShape healthbar, fuelbar;

	//artillery
	PlasmaCannon cannon;
	PlasmaAutomatic automatic;

	//warning sounds and icons
	sf::SoundBuffer out_of_fuel_buffer;
	sf::Sound out_of_fuel_sound;
	sf::Texture out_of_fuel_texture;
	sf::RectangleShape out_of_fuel_icon;

	std::string imageName;

	bool execute;

	//int movDistance;
	std::string commands;
	int instructions = 0;
	int N_inst = 0;
	float angle = 0; //very important for artillery aim
	float rotation;

	float timer = 1.2;

	int powOfN;

public:
	float health = 125, healthMAX = 125;
	float fuel = 60, fuelMAX = 60;
	bool fuelEmptyWarning = false;
	float speed = 1;
	int movDistance = 64;
};

