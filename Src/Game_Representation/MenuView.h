//
// Created by said2 on 13-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_MENUVIEW_H
#define MEATBOY_SAID_YANDARBIEV_MENUVIEW_H

#include "EntityView.h"

class MenuView : public EntityView {
public:
    MenuView(){}
    void notify(Utility::Vector2f vector2F, Direction,bool wall) override{}
    void notify(int lvlnumber)override{

    }
};


#endif //MEATBOY_SAID_YANDARBIEV_MENUVIEW_H
