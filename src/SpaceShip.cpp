#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	position.x = 0;
	position.y = 0;
	
	direction = ofPoint(0, 0);

	rotation = 0;
    
    isRotating = 0;
    
    gasState = 0;
    
    setSpeed(1);
    
    rotationSpeed=5*speed;
    
    maxVelocity=10*speed;
    
    acceleration=0.4*speed;
    
    speedVector=ofPoint(0,0);

	ofEvent<ofSpaceShipFireEventArgs> spaceShipFires = ofEvent<ofSpaceShipFireEventArgs>();
}

SpaceShip::~SpaceShip()
{
	
}

bool SpaceShip::setup()
{
    setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
    setDirection(ofPoint(0, -1));
    setSize(25);
    
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
    
    addRotation(isRotating*rotationSpeed*elapsedTime);
    setDirection(ofPoint(sin(getRotation()), -cos(getRotation())).normalized());
    
    switch(gasState) {
        case 1:
            speedVector+=getDirection()*acceleration;
            if(speedVector.length()>maxVelocity)
            {
                speedVector=speedVector.normalized()*maxVelocity;
            }
            break;
        case -1:
            if(speedVector.length()>0)
            {
                speedVector-=speedVector.normalized()*0.4;
            }
            else{
                speedVector=ofPoint(0,0);
            }
            break;
        case 0:
            if(speedVector.length()>=0)
            {
                speedVector-=speedVector.normalized()*0.09;
            }
            else
            {
                speedVector=ofPoint(0,0);
            }
            break;
    }
    
    setPosition(getPosition()+speedVector);
    


    
	
	// TODO
	// - add spaceship state update
	// - control spacehsip and window boundaries (i.e. marginSwap)
    marginsWrap();
    
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
    
        ofLine(sin(0.8)*size, cos(0.8)*size, 0, -size);
        ofLine(sin(-0.8)*size, cos(-0.8)*size, 0, -size);
        ofLine(sin(0.8)*size/1.2, cos(0.8)*size/1.8, sin(-0.8)*size/1.2, cos(-0.8)*size/1.8);
    
        if (gasState == 1)
        {
            if (counter > 0.05)
            {
                ofLine(sin(0.8)*size/1.2-size/1.1, cos(0.8)*size/1.8, 0, +size);
                ofLine(sin(-0.8)*size/1.2+size/1.1, cos(-0.8)*size/1.8, 0, +size);
                counter = 0;
            }else
            {
                counter += ofGetLastFrameTime();
            }

        }

    
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

void SpaceShip::changeRotation(int direction)
{
    this->isRotating=direction;
}


void SpaceShip::updateSpeed(int accelerate)
{
    this->gasState=accelerate;
}

void SpaceShip::updateSpeeds(float speed_now)
{
    setSpeed(speed_now);
    rotationSpeed=5*speed;
    maxVelocity=10*speed;
    acceleration=0.4*speed;
}

void SpaceShip::keyPressed(ofKeyEventArgs & args)
{
	/*switch(args.key){
		case OF_KEY_UP:
			thrust = true;
			break;
		case ' ':
			isFiring = true;
			break;
	}*/
}

void SpaceShip::keyReleased(ofKeyEventArgs & args)
{
	/*switch(args.key){
		case OF_KEY_UP:
			thrust = false;
			break;
		case ' ':
			isFiring = true;
			break;
    }*/
}