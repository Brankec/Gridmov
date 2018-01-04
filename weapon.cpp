#include "weapon.h"

weapon::weapon()
{
}

void weapon::fire(const sf::Vector2f& playerPosition, float angle, float projectileSpeed, sf::Texture& projectileTexture)
{
	sound.setVolume(30);
	sound.play();
	float m_yaw = (180.0f - angle) / 180.0f * 3.14159265358979;

	int speed = 5;

	projectiles.emplace_back(playerPosition, m_yaw, projectileSpeed, projectileTexture);
}

void weapon::draw(sf::RenderWindow& window, float angle, float dt)
{
	for (auto& projectile : projectiles)
	{
		projectile.update(angle, dt);//update its position

		projectile.drawBullet(window);
	}
}
