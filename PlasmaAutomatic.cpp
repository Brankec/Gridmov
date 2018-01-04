#include "PlasmaAutomatic.h"

PlasmaAutomatic::PlasmaAutomatic()
{
}

void PlasmaAutomatic::openFire(const sf::Vector2f& playerPosition, float angle)
{
	//if (amountFired < amountShots)
	//{
		fire(playerPosition, angle, projectileSpeed, projectileTexture);
		//amountFired++;
	//}
}

void PlasmaAutomatic::drawProjectile(sf::RenderWindow& window)
{
	//if (amountFired < amountShots)
	//{
		draw(window);
	//}
}

void PlasmaAutomatic::updateProjectile(float angle, float dt)
{
	update(angle, dt);
}








void PlasmaAutomatic::Tier1()
{
	setTextureWeapon("cannonT1");
	setTextueProjectile("energyBall");
	setAudio("Tier1_cannon");
	//setPosWeapon(playerPosition);
	setDamage(2);
	setSizeWeapon(0);
	setRateOfFire(1);
	setProjectileSpeed(1000);
	setAmountShotsFired(5);
}





void PlasmaAutomatic::setOriginCenter()
{
	//weaponRec.setOrigin() use it later
}

void PlasmaAutomatic::setTextureWeapon(std::string imageName)
{
	//weaponTexture.loadFromFile("images/weapons/PlasmaCannonT1.png")  for later
}

void PlasmaAutomatic::setTextueProjectile(std::string imageName)
{
	projectileTexture.loadFromFile("images/weapons/" + imageName + ".png");
}

void PlasmaAutomatic::setAudio(std::string audioName)
{
	if (weaponSound.loadFromFile("audio/weapons/" + audioName + ".wav"));
	sound.setBuffer(weaponSound);
}

void PlasmaAutomatic::setPosWeapon(sf::Vector2f& playerPos) //it will be kept in the middle of the player for now
{
	weaponRec.setPosition(playerPos);
}

void PlasmaAutomatic::setDamage(int n)
{
	damage = 2;
}

void PlasmaAutomatic::setSizeWeapon(int n)
{
	int powOfn = pow(2, n);
	weaponRec.setSize(sf::Vector2f((float)powOfn, (float)powOfn));
}

void PlasmaAutomatic::setRateOfFire(float time)
{
	timeBetweenShots = time;
}

void PlasmaAutomatic::setProjectileSpeed(float n)
{
	projectileSpeed = n;
}

void PlasmaAutomatic::setAmountShotsFired(int n)
{
	amountShots = n;
}
