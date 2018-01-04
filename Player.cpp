#include "Player.h"

Player::Player(int PosX, int PosY, int n, std::string imageName) : 
	execute(0), rotation(0)
{
	cannon.Tier1(); //weapon tier choice ////////////////////////////////////////
	automatic.Tier1();

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
	if (playerTexture.loadFromFile("images/spaceships/" + imageName + ".png"))
		playerRec.setTexture(&playerTexture);

	if (healthTexture.loadFromFile("images/healthbar.png"))
	healthbar.setTexture(&healthTexture);
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
		PLAYER_SHOOT_CANNON = 4,
		PLAYER_SHOOT_AUTOMATIC = 5
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
			case 'C':
				command = PLAYER_SHOOT_CANNON;
				break;
			case 'A':
				command = PLAYER_SHOOT_AUTOMATIC;
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

		static bool isFiringCannon = false;
		 cannon.timer += dt;
		if (command == PLAYER_SHOOT_CANNON)
		{
			if (!isFiringCannon)
			{
				isFiringCannon = true;
				cannon.openFire(playerRec.getPosition(), angle);
			}

			if (cannon.timer > cannon.timeBetweenShots && isFiringCannon)       //ADD DELAY HERE
			{
				cannon.timer = 0;
				isFiringCannon = false;
				ImExecuting = false;
				counter = 0;
				command = 0;
			}
		}

		static bool isFiringAutomatic = false;
		//automatic.timer += dt;
		if (command == PLAYER_SHOOT_AUTOMATIC)
		{
			if (!isFiringAutomatic)
			{
				isFiringAutomatic = true;
				automatic.openFire(playerRec.getPosition(), angle);
			}

			if (cannon.timer > cannon.timeBetweenShots && isFiringAutomatic)       //ADD DELAY HERE
			{
				cannon.timer = 0;
				isFiringAutomatic = false;
				ImExecuting = false;
				counter = 0;
				command = 0;
			}
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
	healthbar.setSize(sf::Vector2f(health, 20));  //HEALTH DISPLAY
	window.draw(healthbar);
}

void Player::hurt(int n)
{
	if(health >= 0)
	health -= n;
}

void Player::heal(int n)
{
	if (health <= 4)
		health += n;
}

void Player::healthbarPositionnit()
{
	healthbar.setPosition(sf::Vector2f(440, 695));
}

void Player::drawProjectile(sf::RenderWindow& window, float angle, float dt)
{
	cannon.drawProjectile(window, angle, dt);
	automatic.drawProjectile(window, angle, dt);
}

void Player::preloadTexture()
{
	artilleryTexture.loadFromFile("images/bullet.png");
}


