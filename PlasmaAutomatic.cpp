#include "PlasmaAutomatic.h"

PlasmaAutomatic::PlasmaAutomatic()
{
}

void PlasmaAutomatic::openFire(const sf::Vector2f& playerPosition, float angle, float dt, bool& isFiring)
{
	if (amountFired <= 0)   //multiple shots per instructions
	{
		amountFired = 5;
		timeBetweenShots = 0;
	}
	timeBetweenShots -= dt;
	if (timeBetweenShots <= 0 && amountFired > 0) {
		fire(playerPosition, angle, projectileTexture);
		amountFired--;
		timeBetweenShots = 0.15;
	}
	if(amountFired <= 0)
	isFiring = true;

}

void PlasmaAutomatic::drawProjectile(sf::RenderWindow& window)
{
		draw(window);
}

void PlasmaAutomatic::updateProjectile(float angle, float dt)
{
	update(angle, dt);
	age(dt);
}

sf::Vector2f PlasmaAutomatic::getProjectilePosition()
{
	return projectilePosition();
}










void PlasmaAutomatic::Tier1()
{
	setTextureWeapon("cannonT1");
	setTextueProjectile("AutomaticAmmo");
	setAudio("Tier1_automatic");
	//setPosWeapon(playerPosition);
	setDamage(2);
	setSizeWeapon(0);
	//setRateOfFire(0.2);
	setProjectileSpeed(2000);
	setAmountShotsFired(5);
	setProjectileSize({ 50,50 });
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

void PlasmaAutomatic::setProjectileSize(sf::Vector2f size)
{
	projectileSize = size;
}
