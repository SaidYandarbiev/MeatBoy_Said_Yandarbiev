//
// Created by said2 on 10-11-2022.
//

#include "GoalModel.h"
#include "../Game_Representation/GoalView.h"

void GoalModel::Update(std::shared_ptr<Utility::Camera> camera) {
    Utility::Vector2f pixels = camera->PositionInPixels(pos);
    for(int i = 0; i < observers.size(); i++){
        observers[i]->notify(pixels, Direction::Right, false);
    }
}
