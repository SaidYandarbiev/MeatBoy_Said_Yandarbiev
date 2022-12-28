//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_ENTITYVIEW_H
#define MEATBOY_SAID_YANDARBIEV_ENTITYVIEW_H


#include <SFML/Graphics/Sprite.hpp>
#include "../Logic/Observer.h"

class EntityView : public Observer{
public:

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a EntityView object
     */
    EntityView(){}

    /**
     * Notify current object
     * ////////////////////////////////////
     * This funmction is called after the update of the EntityModel, which the current EntityView is connected to
     * Relevant Parameters:
     *             vector2F: Current position of the wall in pixels
     */
    virtual void notify(Utility::Vector2f vector2F,Direction, bool wall) = 0;
    /**
     * Notify current object
     * ////////////////////////////////////
     * This funmction is called after the update of the EntityModel, which the current EntityView is connected to
     * Relevant Parameters:
     *             lvlnumber: number of the current lvl
     */
    virtual void notify(int lvlnumber) = 0;

protected:

};


#endif //MEATBOY_SAID_YANDARBIEV_ENTITYVIEW_H
