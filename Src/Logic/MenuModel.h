//
// Created by said2 on 13-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_MENUMODEL_H
#define MEATBOY_SAID_YANDARBIEV_MENUMODEL_H

#include "EntityModel.h"

class MenuModel :public EntityModel {
public:
    MenuModel(){}

    void Update(int lvlnumber)override;
    void Update(Utility::Vector2f vector2F, std::shared_ptr<Utility::Camera> camera)override{}

private:
    int lvlnumber_ = 1;
};


#endif //MEATBOY_SAID_YANDARBIEV_MENUMODEL_H
