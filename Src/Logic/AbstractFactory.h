//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_ABSTRACTFACTORY_H
#define MEATBOY_SAID_YANDARBIEV_ABSTRACTFACTORY_H

#include "WallModel.h"
#include "PlayerModel.h"
#include "GoalModel.h"
#include "Score.h"
#include <memory>
#include "../Utility/Vector.h"
#include "vector"
#include "../Utility/Camera.h"
#include "../Game_Representation/MenuView.h"

//Interface class of concrete factory
class AbstractFactory {
public:
    /**
    * Constructor
    * //////////////////////////////////////
    *The default constructor creates a Abstractfactory object and is used to create models and views
     */
    AbstractFactory() = default;

    /**
     *
     * WallModel Creator
     * ///////////////////////
     * This function creates a Wallmodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the wallmodel that needs to be created
     *          camera: The camera of the game
     */
    virtual std::shared_ptr<WallModel> CreateWallModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) = 0;

    /**
     *
     * PlayerModel Creator
     * ///////////////////////
     * This function creates a Playermodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the Playermodel that needs to be created
     *          camera: The camera of the game
     */
    virtual std::shared_ptr<PlayerModel> CreatePlayerModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) = 0;

    /**
     *
     * GoalModel Creator
     * ///////////////////////
     * This function creates a Goalmodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the Goalmodel that needs to be created
     *          camera: The camera of the game
     */
    virtual std::shared_ptr<GoalModel> CreateGoalModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) = 0;

    /**
     *
     * WallView Creator
     * ///////////////////////
     * This function creates a Wallview with the given parameters.
     * Parameters:
     *          vector2I: Position of the wallview that needs to be created
     */
    virtual std::shared_ptr<WallView> CreateWallView(Utility::Vector2f vector2I) = 0;

    /**
     *
     * PlayerView Creator
     * ///////////////////////
     * This function creates a Playerview with the given parameters.
     * Parameters:
     *          vector2I: Position of the playerview that needs to be created
     */
    virtual std::shared_ptr<PlayerView> CreatePlayerView(Utility::Vector2f vector2I) = 0;

    /**
     *
     * GoalView Creator
     * ///////////////////////
     * This function creates a Goalmodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the goalview that needs to be created
     */
    virtual std::shared_ptr<GoalView> CreateGoalView(Utility::Vector2f vector2I) = 0;

    /**
     *
     * Getplayer
     * ///////////////////////
     * This function returns the player pointer.
     */
    std::shared_ptr<Observer> getPlayer(){
        return player;
    }

    /**
     *
     * getWalls
     * ///////////////////////
     * This function returns a vector with all the walls.
     */
    std::vector<std::shared_ptr<Observer>> getWalls(){
        return walls;
    }

    /**
     *
     * GetGoal
     * ///////////////////////
     * This function returns the goal pointer
     */
    std::shared_ptr<Observer> getGoal(){
        return goal;
    }


protected:

    //Player pointer
    std::shared_ptr<Observer> player = nullptr;

    //Vector with all thewalls
    std::vector<std::shared_ptr<Observer>> walls = {};

    //Goal pointer
    std::shared_ptr<Observer> goal = nullptr;

    //Menu pointer
    std::shared_ptr<MenuView> menuview = nullptr;

};


#endif //MEATBOY_SAID_YANDARBIEV_ABSTRACTFACTORY_H
