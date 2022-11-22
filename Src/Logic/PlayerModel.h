//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_PLAYERMODEL_H
#define MEATBOY_SAID_YANDARBIEV_PLAYERMODEL_H

#include "EntityModel.h"


class PlayerView;
class PlayerModel :public EntityModel{

public:
    PlayerModel(Utility::Vector2f f) {
        pos = f;
    }

    void Update(Utility::Vector2f vector2F,std::shared_ptr<Utility::Camera> camera)override;
    void Update(int lvlnumber)override{}
    void Update(std::shared_ptr<Utility::States>, Utility::Vector2u, float y, std::shared_ptr<Utility::Camera> camera) override;

    void setFalling(bool fall){
        falling = fall;
        ysnelheid = 0;
    }

    void setWall(std::string dir, bool w){
        walljump = w;
        if(w) {
            if (dir == "left") {
                direction = Direction::Right;
            }

            if (dir == "right") {
                direction = Direction::Left;
            }
            xsnelheid = 0;
        }
    }

    bool getFalling(){
        return falling;
    }

    bool getJumping(){
        return jumping;
    }

    void setxspeed(float xspeed){
        xsnelheid = xspeed;
    }

    Direction getDirection(){
        return direction;
    }

private:
    Direction direction = Direction::Right;
    bool movingleft = false;
    bool movingright = false;

    //This is the x acceleration of the player
    float xversnelling = 0;

    //This is the x speed of the player
    float xsnelheid = 0;

    //This is the y speed of the player (if the speed is positive he goes down, otherwise up)
    float ysnelheid = 0;

    float massa = 50;

    bool falling = true;

    bool jumping = false;

    bool hitwall = false;

    bool walljump = false;

    Utility::Vector2f forces = Utility::Vector2f(0, 9.81);};


#endif //MEATBOY_SAID_YANDARBIEV_PLAYERMODEL_H
