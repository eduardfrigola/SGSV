#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Set framerate to 60 FPS
    ofSetFrameRate(60);
    
    // Load Asteroids from XML
    loadAsteroids();
    
    // Create Asteroids
    generateAsteroids(4);
    
    // TODO
    // Setup the following elements:
    // - players
    // - listeners? (depends on how you handle messages between entities)
    generatePlayers(1);
    
    
    // General logic
    ofBackground(0); // Set background to black
    
    // Debug
    debug = false;
}

//--------------------------------------------------------------
void ofApp::update()
{
    // We get the time that last frame lasted, and use it to update asteroids logic
    // so their behaviour is independent to the framerate
    float elapsedTime = ofGetLastFrameTime();
    
    for(int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i]->update(elapsedTime);
    }
    
    for(int i = 0; i < players.size(); i++)
    {
        players[i]->update(elapsedTime);
    }
    
    // TODO
    // Implement calls for logic:
    // - players
    // - bullets
    // - collisions
    // - game conditions
    // [...]
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for(int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i]->draw(debug);
    }
    
    // TODO
    // Draw all game entities (bullets? players? effects?)
    for(int i = 0; i < players.size(); i++)
    {
        players[i]->draw(debug);
    }
    
    if(debug)
    {
        ofPushStyle();
        ofSetColor(255);
        ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
        ofPopStyle();
    }
}

//-------------------------------------------------------------
void ofApp::loadAsteroids()
{
    // Load the file where asteroids definitions are saved
    if(XML.loadFile("asteroids.xml"))
    {
        cout << "Load Asteroids definition xml" << endl;
    }
    else
    {
        cout << "unable to load asteroids.xml check data/ folder" << endl;
    }
    
    // Check if there is the main xml tag defined or not (as an entry point)
    int areAsteroids = XML.getNumTags("asteroids");
    if(areAsteroids > 0)
    {
        cout << "Found asteroids defined" << endl;
        XML.pushTag("asteroids");
        
        // Parse all the asteroid definitions
        int numAsteroids = XML.getNumTags("asteroid");
        if(numAsteroids > 0)
        {
            cout << "There are " << numAsteroids << " asteroids defined" << endl;
            
            for(int i = 0; i < numAsteroids; i++)
            {
                XML.pushTag("asteroid", i);
                vector<ofPoint> tempDefinition;
                
                int numPoints = XML.getNumTags("point");
                cout << " defined by " << numPoints << " points" << endl;
                
                // Create a vector for each asteroid definition with the points that define its shape
                for(int i = 0; i < numPoints; i++)
                {
                    cout << "  " << XML.getAttribute("point", "x", 0, i) << "x" << XML.getAttribute("point", "y", 0, i) << endl;
                    
                    tempDefinition.push_back(ofPoint(XML.getAttribute("point", "x", 0, i), XML.getAttribute("point", "y", 0, i)));
                }
                
                asteroidsDefinitions.push_back(tempDefinition);
                XML.popTag();
            }
        }
        XML.popTag();
    }
}

//-------------------------------------------------------------
void ofApp::generateAsteroids(int numAsteroids)
{
    float randSize = 0.0f;
    
    for ( int i = 0; i < numAsteroids; i++ )
    {
        // Logic to generate the Asteroids in different sizes
        // these are right now 120, 80, 40 and 20 (minimum)
        int randValue = ofRandom(0, 3);
        if(randValue == 2){
            randSize = 120;
        }
        else
        {
            if(randValue == 1)
            {
                randSize = 80;
            }
            else
            {
                randSize = 40;
            }
        }
        
        int asteroidShape = ofRandom(asteroidsDefinitions.size());
        
        Asteroid* temp = new Asteroid();
        temp->setup(asteroidsDefinitions.at(asteroidShape), randSize, ofRandom(100, 250), ofRandom(-PI, PI),
                    ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight())),
                    ofPoint(ofRandom(-1, 1), ofRandom(-1, 1)).normalize());
        asteroids.push_back(temp);
    }
}

//-----------------------------------------------------------
void ofApp::splitAsteroid(int which)
{
    int asteroidShape = 0;
    
    if(asteroids[which]->getSize() > 20)
    {
        for(int i = 0; i < (asteroids[which]->getSize()/40)+1; i++)
        {
            asteroidShape = ofRandom(asteroidsDefinitions.size());
            
            Asteroid* newAsteroid = new Asteroid();
            newAsteroid->setup(asteroidsDefinitions.at(asteroidShape), asteroids[which]->getSize()/2, asteroids[which]->getSpeed(), asteroids[which]->getRotation(), asteroids[which]->getPosition(), ofPoint(-(ofRandom(-1, 1)), ofRandom(-1, 1)));
            asteroids.push_back(newAsteroid);
        }
    }
    
    asteroids.erase(asteroids.begin() + which);
    
    if(asteroids.size() == 0)
    {
        generateAsteroids(ofRandom(4,6));
    }
}

//-------------------------------------------------------------
void ofApp::generatePlayers(int numPlayers)
{
    for ( int i = 0; i < numPlayers; i++ )
    {
        SpaceShip* temp = new SpaceShip();
        temp->setup();
        players.push_back(temp);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch(key)
    {
            // If pressed Dm change debug mode
        case 'd':
        case 'D':
            debug = !debug;
            break;
        case OF_KEY_UP:
            players[0]->updateSpeed(1);
            break;
        case OF_KEY_DOWN:
            players[0]->updateSpeed(-1);
            break;
    }
    switch (key) {
        case OF_KEY_LEFT:
            players[0]->changeRotation(-1);
            cout<<"left"<<endl;
            break;
        case OF_KEY_RIGHT:
            players[0]->changeRotation(1);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    switch(key)
    {
        case OF_KEY_UP:
            players[0]->updateSpeed(0);
            break;
        case OF_KEY_DOWN:
            players[0]->updateSpeed(0);
            break;
    }
    switch (key) {
        case OF_KEY_LEFT:
            players[0]->changeRotation(0);
            break;
        case OF_KEY_RIGHT:
            players[0]->changeRotation(0);
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    for(int i = 0; i < asteroids.size(); i++) 
    {
        if(asteroids[i]->getCollision(ofPoint(x, y))) 
        {
            cout << "Mouse hit Asteroid " << i << endl;
            splitAsteroid(i);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 
    
}
