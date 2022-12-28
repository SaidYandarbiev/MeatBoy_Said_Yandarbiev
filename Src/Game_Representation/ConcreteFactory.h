//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_CONCRETEFACTORY_H
#define MEATBOY_SAID_YANDARBIEV_CONCRETEFACTORY_H

#include "../Logic/AbstractFactory.h"
#include "../Utility/Vector.h"
#include "../Logic/WallModel.h"
#include "../Logic/GoalModel.h"
#include "../Logic/PlayerModel.h"
#include "../Game_Representation/PlayerView.h"
#include "../Game_Representation/GoalView.h"
#include "../Game_Representation/WallView.h"


class ConcreteFactory : public AbstractFactory{
public:

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a Concretefactory object and is used to create models and views
     */
    explicit ConcreteFactory();

    /**
     *
     * WallModel Creator
     * ///////////////////////
     * This function creates a Wallmodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the wallmodel that needs to be created
     *          camera: The camera of the game
     */
    std::shared_ptr<WallModel> CreateWallModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera)override;


    /**
     *
     * PlayerModel Creator
     * ///////////////////////
     * This function creates a Playermodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the Playermodel that needs to be created
     *          camera: The camera of the game
     */
    std::shared_ptr<PlayerModel> CreatePlayerModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) override;


    /**
     *
     * GoalModel Creator
     * ///////////////////////
     * This function creates a Goalmodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the Goalmodel that needs to be created
     *          camera: The camera of the game
     */
    std::shared_ptr<GoalModel> CreateGoalModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) override;


    /**
     *
     * WallView Creator
     * ///////////////////////
     * This function creates a Wallview with the given parameters.
     * Parameters:
     *          vector2I: Position of the wallview that needs to be created
     */
    std::shared_ptr<WallView> CreateWallView(Utility::Vector2f vector2I)override;


    /**
     *
     * PlayerView Creator
     * ///////////////////////
     * This function creates a Playerview with the given parameters.
     * Parameters:
     *          vector2I: Position of the playerview that needs to be created
     */
    std::shared_ptr<PlayerView> CreatePlayerView(Utility::Vector2f vector2I) override;


    /**
     *
     * GoalView Creator
     * ///////////////////////
     * This function creates a Goalmodel with the given parameters.
     * Parameters:
     *          vector2I: Position of the goalview that needs to be created
     */
    std::shared_ptr<GoalView> CreateGoalView(Utility::Vector2f vector2I) override;


};


#endif //MEATBOY_SAID_YANDARBIEV_CONCRETEFACTORY_H
