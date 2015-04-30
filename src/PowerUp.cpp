#include "PowerUp.h"

PowerUp::PowerUp()
{
    position.x = 0;
    position.y = 0;
    
    direction = ofPoint(0, 0);
    
    rotation = 0;
}

PowerUp::~PowerUp()
{

}
bool PowerUp::setup()
{
    setSize(20);
    setPosition(ofPoint(ofRandom(size, ofGetWidth()-size), ofRandom(size, ofGetHeight()-size)));

    
   	return true;
}
bool PowerUp::setup(int Type)
{    
    type = Type;
    
    // We finally call our entity base setup
    return setup();
}

void PowerUp::update(float elapsedTime)
{
    // Update position by integrating position with actual speed and
    // multiplied by the last frame time
    counter +=0.1;
}

void PowerUp::draw(bool debug)
{
    ofPushMatrix();
        glTranslatef(position.x, position.y, 0);
        glRotatef(rotation / PI * 180, 0,0,1);
        
        if(debug)
        {
            ofPushStyle();
            ofNoFill();
            ofCircle(0, 0,size);
            ofPopStyle();
        }
        switch (type)
        {
            case SPEEDUP:
                ofPushStyle();
                    ofSetColor(0,255,0,120+cos(counter)*20);
                    ofCircle(0,0,size);
                ofPopStyle();
              
                break;
            case SLOWDOWN:
                ofPushStyle();
                    ofSetColor(255,140,0,120+cos(counter)*20);
                    ofCircle(0,0,size);
                ofPopStyle();
                break;
            case PROTECT:
                ofPushStyle();
                    ofSetColor(0,0,255,120+cos(counter)*20);
                    ofCircle(0,0,size);
                ofPopStyle();
                break;
                
            default:
                break;
        }
        
    ofPopMatrix();
}
/*void PowerUp::activate( SpaceShip* player)
{
    switch (type)
    {
        case SPEEDUP:
            speedup(player);
            break;
        case SLOWDOWN:
            slowdown(player);
            break;
        case PROTECT:
            protect(player);
            break;
        default:
            break;
    }
}

void PowerUp::speedup(SpaceShip* player)
{
    player->setSpeed(player->getSpeed()+1);
}

void PowerUp::slowdown(SpaceShip* player)
{
    player->setSpeed(player->getSpeed()-0.5);
}

void PowerUp::protect(SpaceShip* player)
{
    
}
*/


