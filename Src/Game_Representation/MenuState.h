//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_MENUSTATE_H
#define MEATBOY_SAID_YANDARBIEV_MENUSTATE_H

#include "State.h"
#include "../Utility/tinyxml2.h"

class MenuState : public State{
public:

     /**
     * Constructor
     * ///////////////////////////////////
     * This constructor creates a Menustate
     * Parameters:
     */
    MenuState(){
        int lvl = 1;
        bool error = false;
        while(!error){
            tinyxml2::XMLDocument doc;
            std::string file = "Levels/Level" + std::to_string(lvl) + ".xml" ;
            doc.LoadFile(file.c_str());
            if(doc.Error()){
               error = true;
               maxnumber = lvl - 1;
            }

            else{
                lvl += 1;
            }
        }
    }

    /**
     * Escape function
     * ///////////////////////////////////
     * This function is called when the escape button is pressed. If the current object is a levelstate object
     * it returns true otherwise false
     */
    bool Handle1() override{
        std::cout << "Already in MenuState" << std::endl;
        return false;
    }

    /**
     * Enter function
     * ///////////////////////////////////
     * This function is called when the enter button is pressed. If the current object is a levelstate object
     * it returns false otherwise true
     */
    bool Handle2() override{
        std::cout << "Transitioned to LevelState" << std::endl;
        return true;
    }

    /**
     * Levelselect screen +
     * ///////////////////////////////////
     * This function is called when the "D" key is pressed when in Menustate.
     * If our current level is 1 and the "D" key is pressed this function will then make it so that our current level is 2
     *
     */
    int Handle3() override{
        if(lvlnumber < maxnumber){
            lvlnumber += 1;
        }
        return lvlnumber;
    }

    /**
     * Levelselect screen +
     * ///////////////////////////////////
     * This function is called when the "A" key is pressed when in Menustate.
     * If our current level is 2 and the "A" key is pressed this function will then make it so that our current level is 1
     *
     */
    int Handle4() override{
        if(lvlnumber > 1){
            lvlnumber -= 1;
        }
        return lvlnumber;

    }

    /** Statecheck function
     * ///////////////////////////////////
     * This function is called to chech wich state the game is in. If the current object is a levelstate object
     * it returns false otherwise true
     */
    bool Handle5() override{
        return true;
    }

    /** Levelnumber check
     * ///////////////////////////////////
     * If the state of the game is currently in menustate, it calls this function to determine what levelnumber we currently are on
     */
    int getLvlNumber() override {
        return lvlnumber;
    }

    /** Amount of levels check
     * ///////////////////////////////////
     * If the state of the game is currently in menustate, this function returns the total amount of levels in the map "Levels"
     */
    int maxNumber() override{
        return maxnumber;
    }

private:
    //Current levelnumber
    int lvlnumber = 1;

    //Total amount of levels
    int maxnumber = 0;
};


#endif //MEATBOY_SAID_YANDARBIEV_MENUSTATE_H
