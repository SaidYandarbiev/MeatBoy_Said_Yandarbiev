//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_ENTITYMODEL_H
#define MEATBOY_SAID_YANDARBIEV_ENTITYMODEL_H


#include "Subject.h"
#include "../Utility/States.h"


class EntityModel : public Subject{
public:
    EntityModel(){}
    virtual void Update(Utility::Vector2f vector2F, std::shared_ptr<Utility::Camera> camera) = 0;
    virtual void Update(int lvlnumber) = 0;
    virtual void Update(std::shared_ptr<Utility::States>, Utility::Vector2u, float y, std::shared_ptr<Utility::Camera> camera) {};

    bool CheckCollision(float xplatform, float yplatform, float xplayer, float yplayer, double playerwidth,
                                      double platformwidth, double height, double playerheight)
    {

        if ((xplatform <= xplayer + playerwidth) && (xplayer <= (xplatform + platformwidth)) &&
            (yplatform < yplayer + playerheight) && (yplayer < (yplatform + height))) {
            return true;
        }

        return false;
    }

    float getx() const{
        return pos.x;
    }

    float gety() const{
        return pos.y;
    }
protected:
    Utility::Vector2f pos = Utility::Vector2f(0,0);
};


#endif //MEATBOY_SAID_YANDARBIEV_ENTITYMODEL_H
