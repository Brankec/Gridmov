#include <SFML\Graphics.hpp>


#pragma once
class button
{
public:
	button(int PosX, int PosY, sf::Vector2f size, std::string imageName);

public:
	void image();
	void ifMouseCollideADD(sf::Window& window, sf::Mouse& mouse, sf::Event & event, std::string& commands, std::string whichCommand, bool& execute);
	void ifMouseCollideERASE(sf::Window& window, sf::Mouse& mouse, sf::Event & event, std::string& commands, bool& execute);
	void ifMouseCollideEXECUTE(sf::Window& window, sf::Mouse& mouse, sf::Event & event, bool& execute);

public:
	sf::RectangleShape buttonRec;
	sf::Texture buttonTexture;
	std::string imageName;
};

