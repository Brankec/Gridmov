#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <SFML\Graphics.hpp>

class Bullet
{
    public:
		Bullet(const sf::Vector2f& position, float yaw, const sf::Texture& texture);

    public:
        void update(float angle, float dt);
		void drawBullet(sf::RenderWindow& window);

		sf::Vector2f velocity;
		sf::RectangleShape bulletRec;
	    sf::Texture texture;
};

#endif // BULLET_H_INCLUDED
