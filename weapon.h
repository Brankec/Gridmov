#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include "Projectile.h"

#pragma once
class weapon
{
public:
	weapon();

public:
	//asthetics
	int animationSequence;
	sf::Texture weaponTexture;
	sf::RectangleShape weaponRec;
	sf::SoundBuffer weaponSound;
	sf::Sound sound;


	//functionality
	int damage;
	float timeBetweenShots;
	float projectileSpeed;
	int amountShots;
	sf::Vector2f projectileSize;

	void fire(const sf::Vector2f& playerPosition, float angle, sf::Texture& projectileTexture);
	void draw(sf::RenderWindow& window);
	void update(float angle, float dt);
	void age(float dt);
	sf::Vector2f projectilePosition();

public:
	std::vector<Projectile> projectiles;
	float time = 0;
};

