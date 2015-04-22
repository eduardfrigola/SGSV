#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	position.x = 0;
	position.y = 0;
	
	direction = ofPoint(0, 0);

	rotation = 0;

	ofEvent<ofSpaceShipFireEventArgs> spaceShipFires = ofEvent<ofSpaceShipFireEventArgs>();
}

SpaceShip::~SpaceShip()
{
	
}

bool SpaceShip::setup()
{
	// TODO
	// Initialize spaceships:
	// - initial positions
	// - initial directions
	// - maybe subscribe to keyboard or mouse events
	// [...]

	// ADVISE
	// Default setup return could be true, you should control that if smth
	// does not setup properly, then setup could return false and control it
	return true;
}


void SpaceShip::update(float elapsedTime)
{
	// Example on how to accelerate SpaceShip
	if(thrust){
		addThrust(5);
	} 
	else 
	{
		addThrust(-2);
	}

	// How firing could be handled with events
	if(isFiring)
	{
		ofSpaceShipFireEventArgs e = {position, ofPoint(cos(rotation), sin(rotation))};
		ofNotifyEvent(spaceShipFires, e, this);
	}
	
	// TODO
	// - add spaceship state update
	// - control spacehsip and window boundaries (i.e. marginSwap)
}

void SpaceShip::draw(bool debug)
{
	
	// TODO
	// Draw correctly the SpaceShip, in the Hands On PDF you can find an explanation
	// on how to manage translations & rotations and how you should send data to OpenGL

}

void SpaceShip::addThrust(float thrust)
{
	speed += thrust;

	// ADVICE
	// would be a good idea to clip the maximum speed
}

void SpaceShip::keyPressed(ofKeyEventArgs & args)
{
	switch(args.key){
		case OF_KEY_UP:
			thrust = true;
			break;
		case ' ':
			isFiring = true;
			break;
	}
}

void SpaceShip::keyReleased(ofKeyEventArgs & args)
{
	switch(args.key){
		case OF_KEY_UP:
			thrust = false;
			break;
		case ' ':
			isFiring = true;
			break;
	}
}