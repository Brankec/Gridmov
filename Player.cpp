#include "Player.h"

Player::Player(int PosX, int PosY, sf::Vector2f size, std::string imageName)
{
	this->imageName = imageName;
	image();
	playerRec.setSize(size);
	playerRec.setPosition(PosX, PosY);
	setOriginCenter();
}

void Player::image()
{
	if (playerTexture.loadFromFile("images/" + imageName + ".png"))
		playerRec.setTexture(&playerTexture);
}

//by default, in sfml all "objects" start their position at the top left corner
void Player::setOriginCenter()
{
	playerRec.setOrigin(sf::Vector2f(playerRec.getSize().x / 2, playerRec.getSize().y / 2));
}

//We go thru the entire string here searching for instructions and then executing them in order
void Player::execution()
{
	instructions = commands.size();

	//N_inst starts at 0
	if (N_inst < commands.size())
	{
		if (commands[N_inst] == 'w')
			forward++;

		if (commands[N_inst] == 'l')
		{
			direction++;
			if (direction > 3) { direction = 0; }
			angle -= 90;
		}

		if (commands[N_inst] == 'r')
		{
			direction--;
			if (direction < 0) { direction = 3; }
			angle += 90;
		}
		switch (direction)
		{
		case 0:
			playerRec.setRotation(angle);
			playerRec.move(0, -movDistance * forward);

			forward = 0;
			break;
		case 1:
			playerRec.setRotation(angle);
			playerRec.move(-movDistance * forward, 0);

			forward = 0;
			break;
		case 2:
			playerRec.setRotation(angle);
			playerRec.move(0, movDistance * forward);

			forward = 0;
			break;
		case 3:
			playerRec.setRotation(angle);
			playerRec.move(movDistance * forward, 0);

			forward = 0;
			break;
		}
		//next instruction
		N_inst++;
	}
	else
	{
		execute = false;
		commands.clear();
		N_inst = 0;
	}
}

void Player::Triangular_move()
{
	velocityAVG = distance / time;
	velocityMAX = 2 * velocityAVG;
	velocityMIN = velocityAVG / 2;

	timeHALF = time / 2;

	acceleration = velocityMAX / timeHALF;
	deceleration = velocityMIN / timeHALF;

	distanceACCELERATION = (1 / 2) * 1.5 * 133.3;
	distanceDECELERATION = 1 / 2 * timeHALF * velocityMIN;

	playerRec.move(0, -distanceACCELERATION);
}


