#include "Bullet.h"

Bullet::Bullet()
{
	position.x = 0;
	position.y = 0;
	
	direction = ofPoint(0, 0);

	rotation = 0;
}

Bullet::~Bullet(void)
{

}

bool Bullet::setup()
{
	return false;
}

bool Bullet::setup(ofPoint shipPosition, ofPoint shipDirection, float size, float speed, float lifeTime)
{
	position.x = shipPosition.x;
	position.y = shipPosition.y;

	direction.x = -shipDirection.x;
	direction.y = -shipDirection.y;

	return true;
}

void Bullet::update(float deltaTime)
{
	// TODO
	// Bullet's logic
}

void Bullet::draw(bool debug)
{	
	// TODO
	// Draw bullet
}

