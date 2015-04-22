#pragma once

#include "ofMain.h"

#include "ofxXmlSettings.h"

#include "Asteroid.h"
#include "Bullet.h"
#include "SpaceShip.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
private:
    void loadAsteroids();
    
    void generateAsteroids(int numAsteroids);
    void splitAsteroid(int asteroidID);
    
    void generatePlayers(int numPlayers);
    
    void normalizeOfPoint(ofPoint& point);
    
    // TODO
    // Add methods that are responsible of:
    // - check collisions (e.g. between bullets&asteroids, and between players&asteroids)
    // - method that creates bullets (if you want ofApp to manage them)
    // [...]
    
    ofxXmlSettings XML;
    
    vector<vector<ofPoint> > asteroidsDefinitions;
    
    vector<Asteroid*> asteroids;
    // TODO
    // Add variables that manage players and maybe bullets
    
    vector<SpaceShip*> players;
    
    bool debug;
		
};
