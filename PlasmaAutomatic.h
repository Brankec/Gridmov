#include "weapon.h"
#include "Projectile.h"

#pragma once
class PlasmaAutomatic : public weapon
{
public:
	PlasmaAutomatic();

public:
	void openFire(const sf::Vector2f& playerPosition, float angle, float dt, bool& isFiring);
	//void update(sf::Vector2f& velocity);
	void drawProjectile(sf::RenderWindow& window);
	void updateProjectile(float angle, float dt);
	sf::Vector2f getProjectilePosition();

public:
	//setup
	void Tier1();

	

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
	void setProjectileSize(sf::Vector2f size);

private:
	sf::Clock m_projectileTimer;

	sf::Texture projectileTexture;

	int amountFired = 0;
};

