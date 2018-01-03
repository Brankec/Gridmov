#ifndef TEXTURERESOURCES_H
#define TEXTURERESOURCES_H
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
static std::unordered_map<std::string, sf::Texture> gTextures;
//Call before main loop
static void LoadTextures() {
	gTextures["bullet"].loadFromFile("images/bullet.png");
	gTextures["player"].loadFromFile("images/ship.png");
}

//Call after main loop
static void ReleaseTextures() {
	gTextures.clear();
}

#endif 