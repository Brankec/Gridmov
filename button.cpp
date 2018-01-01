#include "button.h"



button::button(int PosX, int PosY, sf::Vector2f size, std::string imageName)
{
	this->imageName = imageName;
	image();
	buttonRec.setSize(size);
	buttonRec.setPosition(PosX, PosY);
}

void button::image()
{
	if (buttonTexture.loadFromFile("images/" + imageName + ".png"))
		buttonRec.setTexture(&buttonTexture);
}






//for adding commands
void button::ifMouseCollideADD(sf::Window& window, sf::Mouse& mouse, sf::Event & event, std::string& commands, std::string whichCommand, bool& execute)
{
	if (mouse.getPosition(window).x > buttonRec.getGlobalBounds().left &&
		mouse.getPosition(window).x < (buttonRec.getGlobalBounds().left + buttonRec.getGlobalBounds().width) &&
		mouse.getPosition(window).y > buttonRec.getGlobalBounds().top &&
		mouse.getPosition(window).y < (buttonRec.getGlobalBounds().top + buttonRec.getGlobalBounds().height))
	{
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && commands.size() < 27 && execute == false)
		{
			commands += whichCommand;
		}

	}
}
//erasing last command added
void button::ifMouseCollideERASE(sf::Window& window, sf::Mouse& mouse, sf::Event & event, std::string& commands, bool& execute)
{
	if (mouse.getPosition(window).x > buttonRec.getGlobalBounds().left &&
		mouse.getPosition(window).x < (buttonRec.getGlobalBounds().left + buttonRec.getGlobalBounds().width) &&
		mouse.getPosition(window).y > buttonRec.getGlobalBounds().top &&
		mouse.getPosition(window).y < (buttonRec.getGlobalBounds().top + buttonRec.getGlobalBounds().height))
	{
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && commands.size() > 0 && execute == false)
		{
			commands.resize(commands.size() - 1);
		}

	}
}
//setting executing the command sequence
void button::ifMouseCollideEXECUTE(sf::Window& window, sf::Mouse& mouse, sf::Event & event, bool& execute)
{
	if (mouse.getPosition(window).x > buttonRec.getGlobalBounds().left &&
		mouse.getPosition(window).x < (buttonRec.getGlobalBounds().left + buttonRec.getGlobalBounds().width) &&
		mouse.getPosition(window).y > buttonRec.getGlobalBounds().top &&
		mouse.getPosition(window).y < (buttonRec.getGlobalBounds().top + buttonRec.getGlobalBounds().height))
	{
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			execute = true;
		}

	}
}


