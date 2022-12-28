//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_ENTITYMODEL_H
#define MEATBOY_SAID_YANDARBIEV_ENTITYMODEL_H


#include "Subject.h"
#include "../Utility/States.h"


class EntityModel : public Subject{
public:

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a EntityModel object
    */
    EntityModel(){}

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Parameter:
     *          camera: The camera of the game
     */
    virtual void Update(std::shared_ptr<Utility::Camera> camera) = 0;

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Parameter:
     *          lvlnumber: Current level number
     */
    virtual void Update(int lvlnumber) = 0;

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Relevant Parameters:
     *          states: Current state of the game
     *          camera: The camera of the game
     */
    virtual void Update(std::shared_ptr<Utility::States> states, Utility::Vector2u, float y , std::shared_ptr<Utility::Camera> camera) {};

    /**
     * CheckCollision
     * ////////////////////////////////////
     * This function is called to check the collision of the player with another object
     * Parameters:
     *          xplatform: x position of the other object
     *          yplatform: y position of the other object
     *          xplayer: x position of the player
     *          yplayer: y position of the player
     *          playerwidth: width of the player
     *          platformwidth: width of the other object
     *          height: height of the player
     *          playerheight: height of the other object
     *
     */
    bool CheckCollision(float xplatform, float yplatform, float xplayer, float yplayer, double playerwidth,
                                      double platformwidth, double height, double playerheight)
    {

        if ((xplatform <= xplayer + playerwidth) && (xplayer <= (xplatform + platformwidth)) &&
            (yplatform < yplayer + playerheight) && (yplayer < (yplatform + height))) {
            return true;
        }

        return false;
    }

    /**
     * Get x
     * ////////////////////////////////////
     * This function returns the x position of the current object
     */
    float getx() const{
        return pos.x;
    }

    /**
     * Get y
     * ////////////////////////////////////
     * This function returns the y position of the current object
     */
    float gety() const{
        return pos.y;
    }

    /**
     * Player position reset
     * ////////////////////////////////////
     * This function gets called when the player goes under the camera (playery < cameray).
     * This function resets the player position to the startposition of the player
     */
    void playerDied(){
        pos = OriginalPos;
    }

protected:

    //Position of the current object
    Utility::Vector2f pos = Utility::Vector2f(0,0);

    //Originalposition of the current object
    Utility::Vector2f OriginalPos = Utility::Vector2f(0,0);
};


#endif //MEATBOY_SAID_YANDARBIEV_ENTITYMODEL_H
