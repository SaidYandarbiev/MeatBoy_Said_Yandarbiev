//
// Created by said2 on 10-11-2022.
//

#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory() {

}

std::shared_ptr<WallModel> ConcreteFactory::CreateWallModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) {
    std::shared_ptr<WallModel> wallModel = std::make_shared<WallModel>(WallModel(vector2I));
    Utility::Vector2f pixels = camera->PositionInPixels(vector2I);
    std::shared_ptr<WallView> wallView = CreateWallView(pixels);
    wallModel->Attach(wallView);
    return wallModel;
}

std::shared_ptr<PlayerModel> ConcreteFactory::CreatePlayerModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) {
    std::shared_ptr<PlayerModel> playerModel = std::make_shared<PlayerModel>(PlayerModel(vector2I));
    Utility::Vector2f pixels = camera->PositionInPixels(vector2I);
    std::shared_ptr<PlayerView> playerView = CreatePlayerView(pixels);
    playerModel->Attach(playerView);

    return playerModel;
}

std::shared_ptr<GoalModel> ConcreteFactory::CreateGoalModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) {
    std::shared_ptr<GoalModel> goalModel = std::make_shared<GoalModel>(GoalModel(vector2I));
    Utility::Vector2f pixels = camera->PositionInPixels(vector2I);
    std::shared_ptr<GoalView> goalView = CreateGoalView(pixels);
    goalModel->Attach(goalView);
    return goalModel;
}


std::shared_ptr<WallView> ConcreteFactory::CreateWallView(Utility::Vector2f vector2I) {
    std::shared_ptr<WallView> wallView = std::make_shared<WallView>(WallView(vector2I));
    walls.push_back(wallView);
    return wallView;
}

std::shared_ptr<PlayerView> ConcreteFactory::CreatePlayerView(Utility::Vector2f vector2I) {
    std::shared_ptr<PlayerView> playerView = std::make_shared<PlayerView>(PlayerView(vector2I));
    player = playerView;
    return playerView;

}

std::shared_ptr<GoalView> ConcreteFactory::CreateGoalView(Utility::Vector2f vector2I) {
    std::shared_ptr<GoalView> goalView = std::make_shared<GoalView>(GoalView(vector2I));
    goal = goalView;
    return goalView;
}








