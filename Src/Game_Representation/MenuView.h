//
// Created by said2 on 13-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_MENUVIEW_H
#define MEATBOY_SAID_YANDARBIEV_MENUVIEW_H

#include "EntityView.h"

class MenuView : public EntityView {
public:

     /**
     * Constructor
     * ///////////////////////////////////
     * This constructor creates a MenuView object with a given position
     * Parameters:
     *            vector2F: Position of the created MenuView
     */
    MenuView(int lvlnumber){
        currlvl = lvlnumber;
        file_ = "Sprites/menul" + std::to_string(currlvl) + ".png";
    }

    void notify(Utility::Vector2f vector2F, Direction,bool wall) override{}

    /**
     * Notify current object
     * ////////////////////////////////////
     * This funmction is called to notify the Menuview that a change in the game occurred
     * Relevant Parameters:
     *             lvlnumber: current levelnumber
     */
    void notify(int lvlnumber)override{
        currlvl = lvlnumber;
        file_ = "Sprites/menul" + std::to_string(lvlnumber) + ".png";
    }

    /**
     * Get current level
     * ////////////////////////////////////
     * This function returns the current level number
     */
    int currLvl(){
        return currlvl;
    }

private:

    //Current level number
    int currlvl = 1;
};


#endif //MEATBOY_SAID_YANDARBIEV_MENUVIEW_H
