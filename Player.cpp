#include "Player.h"

Player::Player( int PosX, int PosY, int n, std::string imageName) : 
	execute(0), rotation(0)
{
	cannon.Tier1(); //weapon tier choice ////////////////////////////////////////
	automatic.Tier1();

	this->powOfN = (int)pow(2, n);
	movDistance = powOfN;
	this->imageName = imageName;
	image();
	sound();

	playerRec.setSize(sf::Vector2f((float)powOfN * 1.5, (float)powOfN * 2));
	playerRec.setPosition((float)powOfN * (float)PosX, (float)powOfN * (float)PosY);
	setOriginCenter();
	healthbarPositionnit();
}

void Player::sound()
{
	if (out_of_fuel_buffer.loadFromFile("audio/status/out_of_fuel.wav"))
		out_of_fuel_sound.setBuffer(out_of_fuel_buffer);
	    out_of_fuel_sound.setVolume(20);
}

void Player::image() 
{
	if (out_of_fuel_texture.loadFromFile("images/status/out_of_fuel_warning.png"))
	{
		out_of_fuel_icon.setTexture(&out_of_fuel_texture);
		out_of_fuel_icon.setSize({ 50, 50 });
		out_of_fuel_icon.setPosition(sf::Vector2f(440, 755)); //fix this later(put it in the right place)
	}
	if (playerTexture.loadFromFile("images/spaceships/" + imageName + ".png"))
		playerRec.setTexture(&playerTexture);

	if (healthTexture.loadFromFile("images/healthbar.png"))
	{
		healthbar.setTexture(&healthTexture);
		fuelbar.setTexture(&healthTexture);
	}
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
			{
				rotation -= 1;
			}
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
			{
			rotation += 1;
			//rotation = lerp(rotation, angle, dt * 5);
			}

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
			if (counter <= powOfN && fuel > 0)
			{
				playerRec.move({ (float)sin(angle*3.141592653 / 180)*2, -(float)cos(angle*3.141592653 / 180)*2 });
				drainFuel(0.01);
				counter++;
			}
			else
			{
				if (fuel <= 0)
				{
					NoFuel(true);
					fuelEmptyWarning = true;
				}
				else
				{
					NoFuel(false);
					fuelEmptyWarning = false;
				}

				ImExecuting = false;
				counter = 0;
				command = 0;
			}
		}

		static bool isFiringCannon = false;
		if (command == PLAYER_SHOOT_CANNON)
		{
			if (!isFiringCannon)
			{
				cannon.openFire(playerRec.getPosition(), angle, dt, isFiringCannon);
			}

			if (isFiringCannon)       
			{
				isFiringCannon = false;
				ImExecuting = false;
				counter = 0;
				command = 0;
			}
		}

		static bool isFiringAutomatic = false;
		if (command == PLAYER_SHOOT_AUTOMATIC)
		{
			if (!isFiringAutomatic)
			{
				automatic.openFire(playerRec.getPosition(), angle, dt, isFiringAutomatic); //1) player position for determing the source of the ammo, 2) angle for the bullet source angle, 3) for delay between shots, 4) for determing setting to true once we fired all bullets
			}

			if (isFiringAutomatic)
			{
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
		execute = false;
		ImExecuting = false;
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

void Player::drawFuel(sf::RenderWindow & window, float dt)
{
	fuelbar.setSize(sf::Vector2f(15, fuel));  //FUEL DISPLAY
	window.draw(fuelbar);

	if (fuelEmptyWarning)
	{
		drawWarningFuel(window, dt);
	}
}

void Player::hurt(float n)
{
	if(health >= 0)
	health -= n;
}

void Player::heal(float n)
{
	if (health <= 125) //its hardcoded for now
		health += n;
}

void Player::replenishFuel(float n)
{
	if (fuel <= 60)
		fuel += n;
}

void Player::drainFuel(float n)
{
	if (fuel > 0)
		fuel -= n;
}

void Player::NoFuel(bool set)
{
	if (set)
	{
		out_of_fuel_sound.play();
		out_of_fuel_sound.setLoop(set);
	}
	else
	{
		out_of_fuel_sound.stop();
		out_of_fuel_sound.setLoop(set);
	}
}

void Player::drawWarningFuel(sf::RenderWindow& window, float dt)
{
	timer -= dt;
	if (timer > 0)
	{
		window.draw(out_of_fuel_icon);
	}
	else if(timer > -1.2)
	{
		//
	}
	else
	{
		timer = 1.2;
	}
}

void Player::healthbarPositionnit()
{
	healthbar.setPosition(sf::Vector2f(440, 695));
	fuelbar.setPosition(sf::Vector2f(427, 816));
	fuelbar.setRotation(-180); //so that it drains from top to bottom
}

void Player::drawProjectile(sf::RenderWindow& window)
{
	cannon.drawProjectile(window);
	automatic.drawProjectile(window);
}

void Player::update(float angle, float dt)
{
	cannon.update(angle, dt);
	automatic.update(angle, dt);
}

void Player::preloadTexture()
{
	artilleryTexture.loadFromFile("images/bullet.png");
}


