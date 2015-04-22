#pragma once
#include "ofMain.h"

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
	
		virtual bool setup();
		virtual void update(float deltaTime);
		virtual void draw(bool debug);

		void addThrust(float thrust);

		void keyPressed(ofKeyEventArgs & args);
		void keyReleased(ofKeyEventArgs & args);

		ofEvent<ofSpaceShipFireEventArgs> spaceShipFires;

	private:
		// SpaceShip's behaviour control variables
		bool thrust, isFiring;
};