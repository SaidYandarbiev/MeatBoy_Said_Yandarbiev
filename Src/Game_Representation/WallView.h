//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_WALLVIEW_H
#define MEATBOY_SAID_YANDARBIEV_WALLVIEW_H


#include "EntityView.h"

class WallView : public EntityView{
public:
    WallView(Utility::Vector2f vector2F){
        pos_ = vector2F;
        file_ = "Sprites/grass.png";
    }

    void notify(Utility::Vector2f vector2F,Direction, bool wall) override{
        pos_ = vector2F;
    }

    void notify(int lvlnumber)override{}
};


#endif //MEATBOY_SAID_YANDARBIEV_WALLVIEW_H
