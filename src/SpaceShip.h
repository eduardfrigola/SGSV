#pragma once
#include "ofMain.h"
#include "Bullet.h"

#include "Entity.h"

// Possible SpaceShip implementation

// Structure to save initial bullet data, so whenever user shoots
// we can send a message with this structure for knowing bullet's
// initial position and direction
struct ofSpaceShipFireEventArgs
{
	ofPoint spaceShipPosition;
	ofPoint spaceShitDirection;
};

class SpaceShip : public Entity
{	
	public:
		SpaceShip();
		~SpaceShip();
	
		bool setup(int aidi);
        virtual bool setup();
		virtual void update(float deltaTime);
		virtual void draw(bool debug);

		void addThrust(float thrust);
    
        void updateSpeed(int acelerate);
    
        void changeRotation(int direction);
    
        void updateSpeeds(float speed_now);

		void keyPressed(ofKeyEventArgs & args);
		void keyReleased(ofKeyEventArgs & args);
    
        void spaceShipReset(int dead);
    
        Bullet* fireBullet();
    
		ofEvent<ofSpaceShipFireEventArgs> spaceShipFires;

        int deadtime;
    
	private:
		// SpaceShip's behaviour control variables
		bool thrust, isFiring;
        int isRotating, gasState, id_num;
        float rotationSpeed, acceleration, maxVelocity;
        ofPoint speedVector;
        float counter;

};