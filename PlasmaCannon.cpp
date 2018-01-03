#include "PlasmaCannon.h"

PlasmaCannon::PlasmaCannon()
{
}

void PlasmaCannon::openFire(const sf::Vector2f& playerPosition, float angle, std::vector<Projectile>& projectiles)
{
	float m_yaw = (180.0f - angle) / 180.0f * 3.14159265358979;

	int speed = 5;

	//if (m_bulletTimer.getElapsedTime().asSeconds() > 0.05)
	//{
	//m_bulletTimer.restart();
	projectiles.emplace_back(playerPosition, m_yaw, bulletTexture);
	//}
}

void PlasmaCannon::update(sf::Vector2f& velocity)
{
	velocity *= 0.97f;
}

void PlasmaCannon::drawBullets(sf::RenderWindow& window, std::vector<Projectile>& projectiles, float angle, float dt)
{

	for (auto& projectile : projectiles)
	{
		projectile.update(angle, dt);
	}
	for (auto& projectile : projectiles)
	{
		window.setTitle("test");
		projectile.drawBullet(window);
	}
}








void PlasmaCannon::Tier1(sf::Vector2f& playerPosition)
{
	setTextureWeapon("cannonT1");
	setTextueProjectile("cannonT1_projectile");
	setAudio("Tier1_cannon");
	setPosWeapon(playerPosition);
	setDamage(2);
	setSizeWeapon(0);
}





void PlasmaCannon::setOriginCenter()
{
	//weaponRec.setOrigin() use it later
}

void PlasmaCannon::setTextureWeapon(std::string imageName)
{
	//weaponTexture.loadFromFile("images/weapons/PlasmaCannonT1.png")  for later
}

void PlasmaCannon::setTextueProjectile(std::string imageName)
{
	bulletTexture.loadFromFile("images/weapons/" + imageName + ".png");
}

void PlasmaCannon::setAudio(std::string audioName)
{
	if (weaponSound.loadFromFile("audio/weapons/" + audioName + ".wav"));
	sound.setBuffer(weaponSound);
}

void PlasmaCannon::setPosWeapon(sf::Vector2f& playerPos) //it will be kept in the middle of the player for now
{
	weaponRec.setPosition(playerPos);
}

void PlasmaCannon::setDamage(int n)
{
	damage = 2;
}

void PlasmaCannon::setSizeWeapon(int n)
{
	int powOfn = pow(2, n);
	weaponRec.setSize(sf::Vector2f((float)powOfn, (float)powOfn));
}