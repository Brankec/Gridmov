#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>
#include "Player.h"
#include "button.h"
#include "text.h"
#include "Map.h"
#include "decoration.h"

#include "soundtrack.h"

#include "TextureResources.h" //use this in main just to initialize it and deallocate

void draw(sf::RenderWindow& window, float dt);
void isMouseColliding(sf::Window& window, sf::Mouse& mouse, sf::Event& event);
void init(sf::Window& window);
float passedTime = 0;

decoration background("space.png", 0, 0, 1.f, 1.f), //(1) texture name, (2-3) position, (4-5) scale
           hud_background("menu.png", 0, 630, 1.2f, 1.f),
	       monitor("monitor.png"),
	       plate("plate.png");

Player player(7, 7, 6, "spaceship");//(1-2) Position, (3) size, (4) name of the image

button button1(30, 790, sf::Vector2f(70, 70), "arrowUp"), //(1-2) Position, (3) size, (4) name of the image
       button2(130, 790, sf::Vector2f(70, 70), "arrowLeft"),
	   button3(230, 790, sf::Vector2f(70, 70), "arrowRight"),
	   button4(30, 690, sf::Vector2f(70, 70), "missile"),
	   button5(130, 690, sf::Vector2f(70, 70), "automaticWeapon"),
	   executeButton(1090, 770, sf::Vector2f(100, 100), "execute"),
	   eraseButton(1100, 680, sf::Vector2f(70, 70), "erase");

text instructionText; //text that will be used for displaying our instructions

Map test("Map1", 6), goal("Map2", 6);

sf::View view;

soundtrack sound;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine,_In_ int       nCmdShow) //for removing the console window
{
	sound.all_alone(); //choice of music


	sf::RenderWindow window(sf::VideoMode(1200, 900), "Gridmov", sf::Style::Titlebar | sf::Style::Close);
	sf::Mouse mouse;

	window.setFramerateLimit(120);

	init(window);

	sf::Clock deltaClock;
	sf::Time dt;
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
			if (event.type == sf::Event::MouseWheelMoved)
			{
				if(event.mouseWheel.delta < 0)
					view.zoom(1.1f);
				else if (event.mouseWheel.delta > 0)
					view.zoom(0.95f);
			}
		}
		//LoadTextures();
		if (player.execute)
			player.execution(dt.asSeconds());
		//writing our instructions to a text display
		instructionText.Text.setString(player.commands);
		draw(window, dt.asSeconds());
	}
	return 0;
}

//instructions for movements
void isMouseColliding(sf::Window& window, sf::Mouse& mouse, sf::Event& event)
{
	button1.ifMouseCollideADD(window, mouse, event, player.commands, "w", player.execute);

	button2.ifMouseCollideADD(window, mouse, event, player.commands, "l", player.execute);

	button3.ifMouseCollideADD(window, mouse, event, player.commands, "r", player.execute);

	button4.ifMouseCollideADD(window, mouse, event, player.commands, "C", player.execute);
	button5.ifMouseCollideADD(window, mouse, event, player.commands, "A", player.execute);

	//erase last instruction
	eraseButton.ifMouseCollideERASE(window, mouse, event, player.commands, player.execute);
	//execute the instructions
	executeButton.ifMouseCollideEXECUTE(window, mouse, event, player.execute);
}

//drawing
void draw(sf::RenderWindow& window, float dt)
{
	window.clear();
	//player zone
	window.setView(view);
	window.draw(background.sprite);
	test.setTilePositions(window);
	goal.setTilePositions(window);
	//artillery
	player.drawProjectile(window, player.angle, dt);

	window.draw(player.playerRec);

	window.setView(window.getDefaultView());
	//hud zone
	window.draw(hud_background.sprite);
	window.draw(monitor.sprite);

	player.drawHealth(window);

	window.draw(plate.sprite);
	window.draw(instructionText.Text);
	window.draw(button1.buttonRec);
	window.draw(button2.buttonRec);
	window.draw(button3.buttonRec);
	window.draw(button4.buttonRec);
	window.draw(button5.buttonRec);
	window.draw(executeButton.buttonRec);
	window.draw(eraseButton.buttonRec);
	window.display();
}

void init(sf::Window& window)
{
	//menu
	monitor.sprite.setScale(1.4f, 1.f);
	monitor.sprite.setPosition((window.getSize().x / 2 - monitor.sprite.getGlobalBounds().width / 2), 665);

	//line seperating menu and background
	plate.sprite.setScale(1.2f, 0.8f);
	plate.sprite.setPosition(0, 610);
}