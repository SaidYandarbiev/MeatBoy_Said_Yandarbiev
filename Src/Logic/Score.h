//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_SCORE_H
#define MEATBOY_SAID_YANDARBIEV_SCORE_H

#include "Observer.h"

class Score : public Observer {
public:
    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a Score object
     */
    Score(){}

    /**
     * Notify current object
     * ////////////////////////////////////
     * This function is called after the update of the Subject, which the current Observer is connected to
     * Relevant Parameters:
     *             vector2F: Current position of the wall in pixels
     */
    void notify(Utility::Vector2f vector2F, Direction, bool wall) override{}

    /**
     * Notify current object
     * ////////////////////////////////////
     * This function is called after the update of the Subject, which the current Observer is connected to
     * Relevant Parameters:
     *             lvlnumber: number of the current lvl
     */
    void notify(int lvlnumber)override{
        if(curr_score > 0) {
            curr_score -= 1;
        }
    };

    /**
     * Get score
     * ////////////////////////////////////
     * This function returns the current score of the player
     */
    int getScore(){
        return curr_score;
    }

    /**
     * Reset score
     * ////////////////////////////////////
     * This function resets the score to the startscore, called when first entering a level or when a player dies
     */
    void resetScore(){
        curr_score = 1000;
    }

private:

    //Current score of the player
    int curr_score = 1000;
};


#endif //MEATBOY_SAID_YANDARBIEV_SCORE_H
