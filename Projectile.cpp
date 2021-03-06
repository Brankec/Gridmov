#include "Projectile.h"


Projectile::Projectile(const sf::Vector2f& position, float yaw, float projectileSpeed, sf::Vector2f projectileSize, sf::Texture& texture)
{
	projectileRec.setSize(projectileSize);
	projectileRec.setOrigin(projectileRec.getGlobalBounds().width / 2, projectileRec.getGlobalBounds().height / 2);

	projectileRec.setTexture(&texture);

	projectileRec.setPosition(position);

	float x = sin(yaw) * projectileSpeed;
	float y = cos(yaw) * projectileSpeed;
	projectileVelocity = { x, y };

}


void Projectile::update(float angle, float dt)
{
	projectileRec.move(projectileVelocity * dt);
	//time += dt;
}

void Projectile::drawBullet(sf::RenderWindow& window)
{
	window.draw(projectileRec);
}

sf::Vector2f Projectile::pos()
{
	return sf::Vector2f(projectileRec.getPosition()/64.f);
}

bool Projectile::isDed()
{
	if (age >= ageLimit)
		return true;
	else
		return false;
}


