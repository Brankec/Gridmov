#include "text.h"



text::text()
{
	loadFont();
	textPositionSpace();
}

void text::loadFont()
{
	font.loadFromFile("images/AGENCYR.TTF");
	Text.setFont(font);
	Text.setFillColor(sf::Color(255, 165, 0));
}
//this is a fixed position for our text
void text::textPositionSpace()
{
	Text.setPosition(400, 815);
}

