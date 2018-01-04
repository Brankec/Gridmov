#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <SFML\Graphics.hpp>

class Projectile
{
    public:
		Projectile(const sf::Vector2f& position, float projectileSpeed, float yaw, sf::Texture& texture);

    public:
        void update(float angle, float dt);
		void drawBullet(sf::RenderWindow& window);
		std::string pos();

		sf::Vector2f bulletVelocity;
		sf::RectangleShape bulletRec;
	    sf::Texture bulletTexture;
};

#endif // BULLET_H_INCLUDED
