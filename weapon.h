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

	void fire(const sf::Vector2f& playerPosition, float angle, float projectileSpeed, sf::Texture& projectileTexture);
	void draw(sf::RenderWindow& window, float angle, float dt);

private:
	std::vector<Projectile> projectiles;
};

