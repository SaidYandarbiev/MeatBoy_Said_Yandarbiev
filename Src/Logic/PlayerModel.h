//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_PLAYERMODEL_H
#define MEATBOY_SAID_YANDARBIEV_PLAYERMODEL_H

#include "EntityModel.h"


class PlayerView;
class PlayerModel :public EntityModel {

public:

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a PlayerModel object
    * Parameters:
    *             f: startposition of the player
    */
    PlayerModel(Utility::Vector2f f) {
        pos = f;
        OriginalPos = f;
    }

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Parameter:
     *          camera: The camera of the game
     */
    void Update(std::shared_ptr<Utility::Camera> camera) override {};

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Parameter:
     *          lvlnumber: Current level number
     */
    void Update(int lvlnumber) override {}

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Relevant Parameters:
     *          states: Current state of the game
     *          camera: The camera of the game
     */
    void Update(std::shared_ptr<Utility::States>, Utility::Vector2u, float y,
                std::shared_ptr<Utility::Camera> camera) override;

    /**
     * Set falling
     * ////////////////////////////////////
     * This function sets the variables fall on true or false based on if the player is falling or not
     * Parameters:
     *            fall: Boolean if true player is falling, if false player is not falling
     */
    void setFalling(bool fall) {
        falling = fall;
        ysnelheid = 0;
    }

    /**
     * Setwall
     * ////////////////////////////////////
     * This function checks if a player is sliding on a wall or not.
     * If a player is sliding on a wall it also sets its direction based on the wall the player is jumping to.
     * Parameters:
     *          dir: The direction the player is facing currently
     *          w: Boolean true if player is sliding on a wall, otherwise false
     */
    void setWall(std::string dir, bool w) {
        walljump = w;
        if (w) {
            if (dir == "left") {
                direction = Direction::Right;
            }

            if (dir == "right") {
                direction = Direction::Left;
            }
            xsnelheid = 0;
        }
    }

    /**
     * Get falling
     * ////////////////////////////////////
     * This function returns the boolean falling, which tells us if a player is falling or not
     */
    bool getFalling() {
        return falling;
    }

    /**
     * Get Jumping
     * ////////////////////////////////////
     * This function returns the boolean jumping, which tells us if a player is jumping or not
     */
    bool getJumping() {
        return jumping;
    }

    /**
     * Set x speed
     * ////////////////////////////////////
     * This function sets the horizontal speed of the player to the given parameter
     * Parameters
     *          xspeed: Horizontal speed of the player
     */
    void setxspeed(float xspeed) {
        xsnelheid = xspeed;
    }

    /**
     * Get Direction
     * ////////////////////////////////////
     * This function returns the direction the player is facing
     */
    Direction getDirection() {
        return direction;
    }

    /**
     * Get Died
     * ////////////////////////////////////
     * This function returns the boolean died, which tells us if a player has died or not
     */
    bool getDied(){
        return died;
    }

    /**
     * Set Died
     * ////////////////////////////////////
     * This function sets the boolean died to false
     */
    void setDied() {
        died = false;
    }

private:

    //Direction the player is facing
    Direction direction = Direction::Right;

    //This is the x acceleration of the player
    float xversnelling = 0;

    //This is the x speed of the player
    float xsnelheid = 0;

    //This is the y speed of the player (if the speed is positive he goes down, otherwise up)
    float ysnelheid = 0;

    //Weight of player
    float massa = 50;

    //Boolean that determines if a player is falling or not
    bool falling = true;

    //Boolean that determines if a player is jumping or not
    bool jumping = false;

    //Boolean that determines if the player has hit a wall or not
    bool hitwall = false;

    //Boolean that determines if the player is walljumping or not
    bool walljump = false;

    Utility::Vector2f forces = Utility::Vector2f(0, 9.81);

    //Boolean that determines if a player has died or not
    bool died = false;
};

#endif //MEATBOY_SAID_YANDARBIEV_PLAYERMODEL_H
