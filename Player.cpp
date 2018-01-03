#include "Player.h"

Player::Player(int PosX, int PosY, int n, std::string imageName) : 
	execute(0), rotation(0)
{
	//artillery images
	preloadTexture();

	this->powOfN = (int)pow(2, n);
	movDistance = powOfN;
	this->imageName = imageName;
	image();
	playerRec.setSize(sf::Vector2f((float)powOfN, (float)powOfN * 2));
	playerRec.setPosition((float)powOfN * (float)PosX, (float)powOfN * (float)PosY);
	setOriginCenter();
	healthbarPositionnit();
}

void Player::image() 
{
	if (playerTexture.loadFromFile("images/" + imageName + ".png"))
		playerRec.setTexture(&playerTexture);

	if (healthTexture.loadFromFile("images/healthbar.png"))
		for (int i = 0; i < health; i++)
		healthbar[i].setTexture(healthTexture);
}

//by default, in sfml, all "objects" start their position at the top left corner
void Player::setOriginCenter()
{
	playerRec.setOrigin(sf::Vector2f(playerRec.getSize().x / 2, playerRec.getSize().y / 2));
}


//We go thru the entire string here searching for instructions and then executing them in order
void Player::execution(float dt)
{
	instructions = commands.length();

	static bool ImExecuting = false;

	enum
	{
		PLAYER_FORWARD = 1,
		PLAYER_LEFT = 2,
		PLAYER_RIGHT = 3,
		PLAYER_SHOOT = 4
	};
	static int command = 0;
	if (N_inst <= instructions)
	{

		if (!ImExecuting)
		{
			switch (commands[N_inst])
			{
			case 'w':
				command = PLAYER_FORWARD;
				break;
			case 'l':
				command = PLAYER_LEFT;
				break;
			case 'r':
				command = PLAYER_RIGHT;
				break;
			case 's':
				command = PLAYER_SHOOT;
				break;
			default:
				command = 0;
				break;
			}
			N_inst++;
			ImExecuting = true; 
		}

		float desiredangle; 

		if (command == PLAYER_LEFT)
		{
			desiredangle = angle - 90;
			if (rotation > desiredangle)
				rotation -= 1;
			else
			{
				ImExecuting = false;
				rotation = angle = desiredangle;
				command = 0;
			}
		}

		if (command == PLAYER_RIGHT)
		{
			desiredangle = angle + 90;
			if (rotation < desiredangle)
				rotation += 1;
			else
			{
				ImExecuting = false;
				rotation = angle = desiredangle;
				command = 0;
			}
		}
		
		static int counter = 0;
		if (command == PLAYER_FORWARD)
		{
			if (counter <= powOfN)
			{
				playerRec.move({ (float)sin(angle*3.141592653 / 180), -(float)cos(angle*3.141592653 / 180) });
				counter++;
			}
			else
			{
				ImExecuting = false;
				counter = 0;
				command = 0;
			}
		}

		if (command == PLAYER_SHOOT)
		{
			//guns(projectiles);
			cannon.openFire(playerRec.getPosition(), angle, projectiles);
			ImExecuting = false;
			counter = 0;
			command = 0;
		}
		
		playerRec.setRotation(rotation);
	}
	else
	{
		ImExecuting = false;
		execute = false; 
		N_inst = 0;
		commands.clear();
	}
}
float Player::lerp(float v0, float v1, float t) {
	return v0 + t * (v1 - v0);
}
 
void Player::drawHealth(sf::RenderWindow& window)
{
	switch(health)
	{
	case 5:
		window.draw(healthbar[0]);
		window.draw(healthbar[1]);
		window.draw(healthbar[2]);
		window.draw(healthbar[3]);
		window.draw(healthbar[4]);
		break;
	case 4:
		window.draw(healthbar[0]);
		window.draw(healthbar[1]);
		window.draw(healthbar[2]);
		window.draw(healthbar[3]);
		break;
	case 3:
		window.draw(healthbar[0]);
		window.draw(healthbar[1]);
		window.draw(healthbar[2]);
		break;
	case 2:
		window.draw(healthbar[0]);
		window.draw(healthbar[1]);
		break;
	case 1:
		window.draw(healthbar[0]);
		break;
	}
}

void Player::hurt(int n)
{
	if(health >= 0)
	health--;
}

void Player::heal(int n)
{
	if (health <= 4)
		health++;
}

void Player::healthbarPositionnit()
{
	healthbar[0].setPosition(sf::Vector2f(440, 695));
	for(int i = 1; i < health; i++)
		healthbar[i].setPosition(sf::Vector2f(440.f + 25.f * (float)i, 695.f));
}
//creating a bullet
void Player::guns(std::vector<Projectile>& bullets)
{
	float m_yaw = (180.0f - angle) / 180.0f * 3.14159265358979;

	int speed = 5;

	//if (m_bulletTimer.getElapsedTime().asSeconds() > 0.05)
	//{
		//m_bulletTimer.restart();
		bullets.emplace_back(playerRec.getPosition(), m_yaw, artilleryTexture);
	//}
}

void Player::onUpdate(sf::Vector2f& velocity)
{
	velocity *= 0.97f;
}

void Player::drawBullets(sf::RenderWindow& window, float angle, float dt)
{
	/*
	for (auto& projectile : projectiles)
	{
		projectile.update(angle, dt);
	}
	for (auto& projectile : projectiles)
	{
		window.setTitle(projectile.pos());
		projectile.drawBullet(window);
	}
	*/
	cannon.drawBullets(window, angle, dt);
}

void Player::preloadTexture()
{
	artilleryTexture.loadFromFile("images/bullet.png");
}


