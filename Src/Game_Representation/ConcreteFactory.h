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

    explicit ConcreteFactory(Utility::Vector2f f);

    std::shared_ptr<WallModel> CreateWallModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera)override;

    std::shared_ptr<PlayerModel> CreatePlayerModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) override;

    std::shared_ptr<GoalModel> CreateGoalModel(Utility::Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) override;

    std::shared_ptr<WallView> CreateWallView(Utility::Vector2f vector2I)override;

    std::shared_ptr<PlayerView> CreatePlayerView(Utility::Vector2f vector2I) override;

    std::shared_ptr<GoalView> CreateGoalView(Utility::Vector2f vector2I) override;


};


#endif //MEATBOY_SAID_YANDARBIEV_CONCRETEFACTORY_H
