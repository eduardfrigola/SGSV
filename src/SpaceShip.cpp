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
    setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
    setDirection(ofPoint(0, 1));
    setSize(70);
    
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
    ofPushMatrix();
        glTranslatef(position.x, position.y, 0);
        glRotatef(rotation / PI * 180, 0,0,1);
        if(debug)
        {
            ofPushStyle();
            ofNoFill();
            ofCircle(0, 0, size);
            ofPopStyle();
        }
        
        //ofScale(size/60,size/60,0);
        //glTranslatef(-50, -50, 0);
        ofLine(sin(PI/4)*size, cos(PI/4)*size, 0, -size);
        ofLine(sin(-PI/4)*size, cos(-PI/4)*size, 0, -size);
        ofLine(sin(PI/4)*size/1.2, cos(PI/4)*size/1.8, sin(-PI/4)*size/1.2, cos(-PI/4)*size/1.8);
    ofPopMatrix();
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