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
#include "MenuModel.h"
#include "../Game_Representation/MenuView.h"

class AbstractFactory {
public:
    AbstractFactory() = default;

    virtual std::shared_ptr<WallModel> CreateWallModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) = 0;

    virtual std::shared_ptr<PlayerModel> CreatePlayerModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) = 0;

    virtual std::shared_ptr<GoalModel> CreateGoalModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) = 0;

    virtual std::shared_ptr<WallView> CreateWallView(Utility::Vector2f vector2I) = 0;

    virtual std::shared_ptr<PlayerView> CreatePlayerView(Utility::Vector2f vector2I) = 0;

    virtual std::shared_ptr<GoalView> CreateGoalView(Utility::Vector2f vector2I) = 0;

    void clear(){
        player.reset();
        walls = {};
        goal.reset();
    }

    std::shared_ptr<Observer> getPlayer(){
        return player;
    }

    std::vector<std::shared_ptr<Observer>> getWalls(){
        return walls;
    }

    std::shared_ptr<Observer> getGoal(){
        return goal;
    }

    std::shared_ptr<MenuView> getMenu(){
        return menuview;
    }

protected:

    std::shared_ptr<Observer> player = nullptr;
    std::vector<std::shared_ptr<Observer>> walls = {};
    std::shared_ptr<Observer> goal = nullptr;
    std::shared_ptr<MenuView> menuview = nullptr;

};


#endif //MEATBOY_SAID_YANDARBIEV_ABSTRACTFACTORY_H
