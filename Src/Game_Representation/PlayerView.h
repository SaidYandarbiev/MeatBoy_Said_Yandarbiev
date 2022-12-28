//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_PLAYERVIEW_H
#define MEATBOY_SAID_YANDARBIEV_PLAYERVIEW_H


#include "EntityView.h"

class PlayerView : public EntityView {
public:

     /**
     * Constructor
     * ///////////////////////////////////
     * This constructor creates a PlayerView object with a given position
     * Parameters:
     *            vector2F: Position of the created PlayerView
     */
    PlayerView(Utility::Vector2f vector2F){
        pos_ = vector2F;
        file_ = "Sprites/meatboyleft.png";
    }

    /**
     * Notify current object
     * ////////////////////////////////////
     * This function is called after the update of the Wallmodel, which the current WallView is connected to
     * Parameters:
     *             vector2F: Current position of the wall in pixels
     *             wall: boolean, if true the player is sliding on a wall, false if not
     */
    void notify(Utility::Vector2f vector2F, Direction direction, bool wall) override{
        pos_ = vector2F;
        if(direction == Direction::Right){
            if(wall) {
                file_ = "Sprites/meatboyleftwall.png";
            }
            else{
                file_ = "Sprites/meatboyright.png";
            }
        }

        else if(direction == Direction::Left){
            if(wall) {
                file_ = "Sprites/meatboyrightwall.png";
            }
            else{
                file_ = "Sprites/meatboyleft.png";
            }
        }
    }
    void notify(int lvlnumber)override{}

};


#endif //MEATBOY_SAID_YANDARBIEV_PLAYERVIEW_H
