//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_WORLD_H
#define MEATBOY_SAID_YANDARBIEV_WORLD_H

#include "../Utility/Vector.h"
#include "AbstractFactory.h"
#include "memory"
#include "../Utility/Camera.h"
#include "../Utility/States.h"
#include "iostream"
#include "string"
#include "vector"
#include <algorithm>
#include "Score.h"
#include "../Utility/tinyxml2.h"
#include "string"

class World {

public:

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a World object
     * Parameters:
     *           u: The size of the window
     *           sharedPtr: concretefactory pointer
     *           */
    World(Utility::Vector2u u, std::shared_ptr<AbstractFactory> sharedPtr);

    /**
    * Update
    * //////////////////////////////////////
    *Updates every model and every view inside the world
     */
    void Update();


    /**
    * Get state
    * //////////////////////////////////////
    * This function returns the last keyboard input of the player
     */
    std::shared_ptr<Utility::States> GetState() { return states; }

    /**
    * Spawner
    * //////////////////////////////////////
    * This function is called at the start of the game when the world is made.
    * It makes all the bg tiles of the first screen in the game.
     * Parameters:
     *          lvlnumber: current level number
    */
    void Spawner(int lvlnumber);

    /**
    * Get player
    * //////////////////////////////////////
    * This function returns the playermodel pointer
     */
    std::shared_ptr<PlayerModel> GetPlayer() { return player; }

    /**
    * Get score
    * //////////////////////////////////////
    * This function returns the score pointer
     */
    std::shared_ptr<Score> GetScore(){return score;}

    /**
    * Get game ended
    * //////////////////////////////////////
    * This function returns the boolean gameEnded, which tells us if the game has ended or not
     */
    bool getGameEnded() const{
        return gameEnded;
    }

    /**
    * Get level number
    * //////////////////////////////////////
    * This function returns the current level number
     */
    int getLvlNumber() const{
        return lvlNumber;
    }

    /**
    * Set level number
    * //////////////////////////////////////
    * This function sets the current level number
     * Parameters:
     *          lvl: current level number being set
     */
    void setLvlNumber(int lvl){
        lvlNumber = lvl;
    }

private:

    //The size of the window of the game and world
    Utility::Vector2u m_windowSize = Utility::Vector2u(0, 0);

    //Pointer to the abstract factory
    std::shared_ptr<AbstractFactory> concreteFactory;

    //Size of the world in the x-axis
    Utility::Vector2f XWorldSize = Utility::Vector2f(0, 20);

    //Size of the world in the y-axis
    Utility::Vector2f YWorldSize = Utility::Vector2f(0, 60);

    //Pointer to player model
    std::shared_ptr<PlayerModel> player = nullptr;

    //Vector with all the platform models
    std::vector<std::shared_ptr<WallModel>> walls;

    //Vector with all the bg tile models
    std::shared_ptr<GoalModel> goal = nullptr;

    //Pointer to the camera
    std::shared_ptr<Utility::Camera> camera;

    //Original camera pos
    float originalcameray;

    //Float containing the previous y position of the camera
    float previouscameray = 0;

    //Float containing the current y position of the camera
    float currentcameray;

    //Pointer to the states class
    std::shared_ptr<Utility::States> states = nullptr;

    //Pointer to the score class with the current score of the player
    std::shared_ptr<Score> score = std::make_shared<Score>();

    //boolean if true then the player collided with ceiling, else false
    bool ceilingcollision = true;

    //boolean if true then the player collided with wall while jumping/falling, else false
    bool walljump = true;

    //boolean if true then the player has no collision with any object, else false
    bool nocollision = true;

    //Current level number
    int lvlNumber = 0;

    //boolean if true then the game has ended, else false
    bool gameEnded = false;
};


#endif //MEATBOY_SAID_YANDARBIEV_WORLD_H
