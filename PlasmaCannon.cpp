#include "PlasmaCannon.h"

PlasmaCannon::PlasmaCannon()
{
}

void PlasmaCannon::openFire(const sf::Vector2f& playerPosition, float angle, float dt, bool& isFiring)
{
	if (amountFired <= 0)
	{
		amountFired = 2;
		timeBetweenShots = 0;
	}
	timeBetweenShots -= dt;
	if (timeBetweenShots <= 0 && amountFired > 0) {
		fire(playerPosition, angle, projectileTexture);
		amountFired--;
		timeBetweenShots = 1;
	}
	if (amountFired <= 0)
		isFiring = true;

}

void PlasmaCannon::drawProjectile(sf::RenderWindow& window)
{
	draw(window);
}

void PlasmaCannon::updateProjectile(float angle, float dt)
{
	update(angle, dt);
}








void PlasmaCannon::Tier1()
{
	setTextureWeapon("cannonT1");
	setTextueProjectile("energyBall");
	setAudio("Tier1_cannon");
	//setPosWeapon(playerPosition);
	setDamage(2);
	setSizeWeapon(0);
	setRateOfFire(1);
	setProjectileSpeed(1000);
	setProjectileSize({ 70, 70 });
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
	projectileTexture.loadFromFile("images/weapons/" + imageName + ".png");
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

void PlasmaCannon::setRateOfFire(float time)
{ 
	timeBetweenShots = time;
}

void PlasmaCannon::setProjectileSpeed(float n)
{
	projectileSpeed = n;
}

void PlasmaCannon::setProjectileSize(sf::Vector2f size)
{
	projectileSize = size;
}
