#include "Bullet.h"

ofEvent<int> Bullet::bulletDead = ofEvent<int>();

Bullet::Bullet()
{
	position.x = 0;
	position.y = 0;
	
	direction = ofPoint(0, 0);

	rotation = 0;
    
    //setSize(2);
    //setSpeed(10);
    //lifeTime=10;
    
    
}

Bullet::~Bullet(void)
{

}

bool Bullet::setup()
{

    return false;
}

bool Bullet::setup(ofPoint shipPosition, ofPoint shipDirection, float size_, float speed_, float lifeTime_, int playerid_)
{
    position.x = shipPosition.x;
    position.y = shipPosition.y;
    
    direction.x = shipDirection.x;
    direction.y = shipDirection.y;
    
    setSize(size_);
    setSpeed(speed_);
    lifeTime=lifeTime_;
    playerid=playerid_;
    return true;
}

void Bullet::update(float deltaTime)
{
    if(lifeTime>0)
    {
        setPosition(getPosition()+getDirection()*getSpeed());
        marginsWrap();
        lifeTime-=1;
    }
    else{
        int value=1;
        ofNotifyEvent(bulletDead, value, this);
    }
}

void Bullet::draw(bool debug)
{	
	// TODO
	// Draw bullet
    ofLine(getPosition(), getPosition()+(getDirection()*getSize()));
}

