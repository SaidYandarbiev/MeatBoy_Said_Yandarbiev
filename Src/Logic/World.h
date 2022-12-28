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
    World(Utility::Vector2u u, std::shared_ptr<AbstractFactory> sharedPtr);

    //Updates every model and every view inside the world
    void Update();

    //Returns the pointer to the state class
    std::shared_ptr<Utility::States> GetState() { return states; }

    //This function is called at the start of the game when the world is made
    //It makes all the bg tiles of the first screen in the game
    void Spawner(int lvlnumber);

    //Returns the player model
    std::shared_ptr<PlayerModel> GetPlayer() { return player; }

    void Reset();

    //Returns the score pointer
    std::shared_ptr<Score> GetScore(){return score;}

    void clear(){
        player = nullptr;
        goal = nullptr;
        walls.clear();
        previouscameray = 0;
    }

    bool getGameEnded() const{
        return gameEnded;
    }

    int getLvlNumber() const{
        return lvlNumber;
    }

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

    bool ceilingcollision = true;
    bool walljump = true;
    bool nocollision = true;

    int lvlNumber = 0;

    bool gameEnded = false;
};


#endif //MEATBOY_SAID_YANDARBIEV_WORLD_H
