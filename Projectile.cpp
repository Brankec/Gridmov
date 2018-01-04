#include "Projectile.h"


Projectile::Projectile(const sf::Vector2f& position, float yaw, float projectileSpeed, sf::Texture& texture)
{
	bulletRec.setSize({ 50, 50 });
	bulletRec.setOrigin(bulletRec.getGlobalBounds().width / 2, bulletRec.getGlobalBounds().height / 2);

	bulletRec.setTexture(&texture);

	bulletRec.setPosition(position);

	float x = sin(yaw) * projectileSpeed;
	float y = cos(yaw) * projectileSpeed;
	bulletVelocity = { x, y };

}


void Projectile::update(float angle, float dt)
{
	bulletRec.move(bulletVelocity * dt);
}

void Projectile::drawBullet(sf::RenderWindow& window)
{
	window.draw(bulletRec);
}

std::string Projectile::pos()
{
	return std::to_string(bulletRec.getPosition().y);
}


