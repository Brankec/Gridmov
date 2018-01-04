#include "weapon.h"
#include "Projectile.h"

#pragma once
class PlasmaAutomatic : public weapon
{
public:
	PlasmaAutomatic();

public:
	void openFire(const sf::Vector2f& playerPosition, float angle);
	//void update(sf::Vector2f& velocity);
	void drawProjectile(sf::RenderWindow& window);
	void updateProjectile(float angle, float dt);

public:
	//setup
	void Tier1();

	float timer = 0;//for delay in player class at PLAYER SHOOT CANNON case

private:
	void setOriginCenter();
	void setTextureWeapon(std::string imageName);
	void setTextueProjectile(std::string imageName);
	void setAudio(std::string audioName);
	void setPosWeapon(sf::Vector2f& playerPos);
	void setDamage(int n);
	void setSizeWeapon(int n);
	void setRateOfFire(float time);
	void setProjectileSpeed(float n);
	void setAmountShotsFired(int n);

private:
	sf::Clock m_projectileTimer;

	sf::Texture projectileTexture;

	int amountFired = 0;
};

