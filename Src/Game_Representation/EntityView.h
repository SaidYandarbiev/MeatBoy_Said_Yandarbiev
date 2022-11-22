//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_ENTITYVIEW_H
#define MEATBOY_SAID_YANDARBIEV_ENTITYVIEW_H


#include <SFML/Graphics/Sprite.hpp>
#include "../Logic/Observer.h"

class EntityView : public Observer{
public:
    EntityView(){}

    virtual void notify(Utility::Vector2f vector2F,Direction, bool wall) = 0;
    virtual void notify(int lvlnumber) = 0;

protected:

};


#endif //MEATBOY_SAID_YANDARBIEV_ENTITYVIEW_H
