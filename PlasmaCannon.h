#include "weapon.h"
#include "Projectile.h"

#pragma once
class PlasmaCannon : public weapon
{
public:
	PlasmaCannon();

public:
	void openFire(const sf::Vector2f& playerPosition, float angle, std::vector<Projectile>& projectiles);
	void update(sf::Vector2f& velocity);
	void drawBullets(sf::RenderWindow& window, std::vector<Projectile>& projectiles, float angle, float dt);

public:
	//setup
	void Tier1(sf::Vector2f& playerPosition);

private:
	void setOriginCenter();
	void setTextureWeapon(std::string imageName);
	void setTextueProjectile(std::string imageName);
	void setAudio(std::string audioName);
	void setPosWeapon(sf::Vector2f& playerPos);
	void setDamage(int n);
	void setSizeWeapon(int n);

private:
	sf::Clock m_bulletTimer;

	sf::Texture bulletTexture;
};

