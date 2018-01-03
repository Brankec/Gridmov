#include "Bullet.h"


Bullet::Bullet(const sf::Vector2f& position, float yaw, const sf::Texture& texture) //called in player class
{
	bulletRec.setSize({50, 50});
	bulletRec.setOrigin(bulletRec.getGlobalBounds().width / 2, bulletRec.getGlobalBounds().height / 2);

	bulletRec.setTexture(&texture);

	bulletRec.setPosition(position);

    float x = sin(yaw) * 200;
    float y = cos(yaw) * 200;
    velocity = {x, y};

}

void Bullet::update(float angle, float dt)
{
	bulletRec.move(velocity * dt);
}

void Bullet::drawBullet(sf::RenderWindow& window)
{
	window.draw(bulletRec);
}


