//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_GOALMODEL_H
#define MEATBOY_SAID_YANDARBIEV_GOALMODEL_H

#include "EntityModel.h"
class GoalView;
class GoalModel: public EntityModel{
public:

    GoalModel(Utility::Vector2f f) {
        pos = f;
    }

    void Update(Utility::Vector2f vector2F, std::shared_ptr<Utility::Camera> camera) override;
    void Update(int lvlnumber)override{}
    void Update(std::shared_ptr<Utility::States>, Utility::Vector2u, float y, std::shared_ptr<Utility::Camera> camera) override{};
};


#endif //MEATBOY_SAID_YANDARBIEV_GOALMODEL_H
