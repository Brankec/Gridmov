#include <SFML\Audio.hpp>

#pragma once
class soundtrack
{
public:
	soundtrack();

public:
	void all_alone();

public:
	void loadMusic(std::string audioName);
	void setLoop(bool set); //true or false
	void setVolume(int set); //range from 0-100
	void play(bool set);

private:
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

};

