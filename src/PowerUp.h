#pragma once
#include "ofMain.h"

#include "Entity.h"
#include "SpaceShip.h"

class PowerUp : public Entity
{
public:
    PowerUp();
    ~PowerUp();
    
    bool setup(int Type);
    virtual bool setup();
    virtual void update(float deltaTime);
    virtual void draw(bool debug);
    /*virtual void activate(SpaceShip* player);
    virtual void speedup(SpaceShip* player);
    virtual void slowdown(SpaceShip* player);
    virtual void protect(SpaceShip* player);*/
    int type;

    
private:

    float counter;
};