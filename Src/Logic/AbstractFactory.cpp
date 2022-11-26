//
// Created by said2 on 10-11-2022.
//

#include "AbstractFactory.h"

std::shared_ptr<WallModel> AbstractFactory::CreateWallModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) {
    return nullptr;
}

std::shared_ptr<PlayerModel> AbstractFactory::CreatePlayerModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) {
    return nullptr;
}

std::shared_ptr<GoalModel> AbstractFactory::CreateGoalModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) {
    return nullptr;
}

std::shared_ptr<WallView> AbstractFactory::CreateWallView(Utility::Vector2f vector2I) {
    return nullptr;
}

std::shared_ptr<PlayerView> AbstractFactory::CreatePlayerView(Utility::Vector2f vector2I) {
    return nullptr;
}

std::shared_ptr<GoalView> AbstractFactory::CreateGoalView(Utility::Vector2f vector2I) {
    return nullptr;
}


