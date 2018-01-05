#include "weapon.h"

weapon::weapon()
{
}

void weapon::fire(const sf::Vector2f& playerPosition, float angle, sf::Texture& projectileTexture)
{
	sound.setVolume(30);
	sound.play();
	float m_yaw = (180.0f - angle) / 180.0f * 3.14159265358979;

	int speed = 5;

	projectiles.emplace_back(playerPosition, m_yaw, projectileSpeed, projectileSize, projectileTexture);
}

void weapon::draw(sf::RenderWindow& window)
{
	for (auto& projectile : projectiles)
	{
		projectile.drawBullet(window);
	}
}

void weapon::update(float angle, float dt)
{
	for (auto& projectile : projectiles)
	{
		projectile.update(angle, dt);//update its position
	}
	age(dt);
}

void weapon::age(float dt)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].age += dt;
		if (projectiles[i].isDed())
		{
			projectiles.erase(projectiles.begin() + i);
		}
	}
}

sf::Vector2f weapon::projectilePosition()
{
	for (auto& projectile : projectiles)
	{
		return projectile.pos();
	}
}
