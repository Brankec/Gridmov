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
};

