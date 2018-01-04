#include "soundtrack.h"



soundtrack::soundtrack()
{
}

void soundtrack::all_alone()
{
	loadMusic("All_alone");
	setLoop(true);
	setVolume(10);
	play(true);
}

void soundtrack::loadMusic(std::string audioName)
{
	if (soundBuffer.loadFromFile("audio/background/" + audioName + ".ogg"))
		sound.setBuffer(soundBuffer);
}

void soundtrack::setLoop(bool set)
{
	sound.setLoop(set);
}

void soundtrack::setVolume(int set)
{
	sound.setVolume(set);
}

void soundtrack::play(bool set)
{
	if (set)
		sound.play();
}
