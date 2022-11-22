//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_PLAYERVIEW_H
#define MEATBOY_SAID_YANDARBIEV_PLAYERVIEW_H


#include "EntityView.h"

class PlayerView : public EntityView {
public:

    PlayerView(Utility::Vector2f vector2F){
        pos_ = vector2F;
        file_ = "Sprites/meatboyleft.png";
    }

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
