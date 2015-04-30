#pragma once
#include "ofMain.h"

#include "Entity.h"

class Bullet : public Entity
{
	public:
		Bullet();
		~Bullet();
	
        virtual bool setup();
		bool setup(ofPoint spaceShipPosition, ofPoint spaceShipDirection, float size_, float speed_, float lifeTime_, int playerid_);
		virtual void update(float deltaTime);
		virtual void draw(bool debug);
    
        static ofEvent<int> bulletDead;
        int playerid;
    
	private:
		// Possible bullet's life control variables
		float fireDistance;
		float lifeTime;
    
};