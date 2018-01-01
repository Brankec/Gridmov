#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Player.h"
#include "button.h"
#include "text.h"
#include "Map.h"
#include "decoration.h"

void draw(sf::RenderWindow& window);
void isMouseColliding(sf::Window& window, sf::Mouse& mouse, sf::Event& event);
float passedTime = 0;

decoration background("space", 0, 0, 0.5, 0.5),
           hud_background("menu"),
	       monitor("monitor"),
	       plate("plate");

Player player(440, 383, sf::Vector2f(50, 50), "spaceship");//(1-2) Position, (3) size, (4) name of the image

button button1(30, 790, sf::Vector2f(70, 70), "arrowUp"), //(1-2) Position, (3) size, (4) name of the image
       button2(130, 790, sf::Vector2f(70, 70), "arrowLeft"),
	   button3(230, 790, sf::Vector2f(70, 70), "arrowRight"),
	   executeButton(1090, 770, sf::Vector2f(100, 100), "execute"), //execute is 10 pixels lower because it's bigger than erase button
	   eraseButton(1100, 680, sf::Vector2f(70, 70), "erase");

text instructionText; //text that will be used for displaying our instructions

Map test("Map1", 6);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine,_In_ int       nCmdShow) //for removing the console window
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Gridmov", sf::Style::Titlebar | sf::Style::Close);
	sf::Mouse mouse;

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	//menu
	hud_background.sprite.setScale(1.2, 1);
	hud_background.sprite.setPosition(0, 630);
	monitor.sprite.setScale(1.4, 1);
	monitor.sprite.setPosition((window.getSize().x/2 - monitor.sprite.getGlobalBounds().width/2), 665);
	
	//line seperating menu and background
	plate.sprite.setScale(1.2, 0.8);
	plate.sprite.setPosition(0, 610);

	sf::Clock deltaClock;
	sf::Time dt;

	//tilemap();


	while (window.isOpen())
	{
		dt = deltaClock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//adding instructions if the button was clicked
			isMouseColliding(window, mouse, event);

		}

		passedTime += dt.asSeconds();
		//passedTime is used to slow down the execution
		if (player.execute && passedTime > 0.5f)
		{
			passedTime = 0;
			player.execution();
		}
		//writing our instructions to a text display
		instructionText.Text.setString(player.commands);
		draw(window);
	}
	return 0;
}

//instructions for movements
void isMouseColliding(sf::Window& window, sf::Mouse& mouse, sf::Event& event)
{
	button1.ifMouseCollideADD(window, mouse, event, player.commands, "w", player.execute);

	button2.ifMouseCollideADD(window, mouse, event, player.commands, "l", player.execute);

	button3.ifMouseCollideADD(window, mouse, event, player.commands, "r", player.execute);

	//erase last instruction
	eraseButton.ifMouseCollideERASE(window, mouse, event, player.commands, player.execute);
	//execute the instructions
	executeButton.ifMouseCollideEXECUTE(window, mouse, event, player.execute);

}

//drawing
void draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(background.sprite);
	test.setTilePositions(window);
	window.draw(hud_background.sprite);
	window.draw(monitor.sprite);
	window.draw(plate.sprite);
	window.draw(instructionText.Text);

	window.draw(button1.buttonRec);
	window.draw(button2.buttonRec);
	window.draw(button3.buttonRec);
	window.draw(executeButton.buttonRec);
	window.draw(eraseButton.buttonRec);
	window.draw(player.playerRec);
	window.display();
}