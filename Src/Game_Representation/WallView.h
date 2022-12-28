//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_WALLVIEW_H
#define MEATBOY_SAID_YANDARBIEV_WALLVIEW_H


#include "EntityView.h"

class WallView : public EntityView{
public:

    /**
     * Constructor
     * ///////////////////////////////////
     * This constructor creates a WallView with a given position
     * Parameters:
     *            vector2F: Position of the created Wallview
     */
    WallView(Utility::Vector2f vector2F){
        pos_ = vector2F;
        file_ = "Sprites/grass.png";
    }
    /**
     * Notify current object
     * ////////////////////////////////////
     * This function is called after the update of the Wallmodel, which the current WallView is connected to
     * Relevant Parameters:
     *             vector2F: Current position of the wall in pixels
     */
    void notify(Utility::Vector2f vector2F,Direction, bool wall) override{
        pos_ = vector2F;
    }

    void notify(int lvlnumber)override{}
};


#endif //MEATBOY_SAID_YANDARBIEV_WALLVIEW_H
