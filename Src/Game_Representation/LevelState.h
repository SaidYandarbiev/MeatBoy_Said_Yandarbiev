//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_LEVELSTATE_H
#define MEATBOY_SAID_YANDARBIEV_LEVELSTATE_H

#include "State.h"
#include "../Logic/World.h"

class LevelState : public State{
public:

    /**
     * Constructor
     * ///////////////////////////////////
     * This constructor creates a LevelState
     * Parameters:
     *            lvlnumber: number of the current level
     *            world: pointer to the current world
     */
    LevelState(int lvlnumber, std::shared_ptr<World> &world){
        lvlnumber_ = lvlnumber;
        world_ = world;
        world_->Spawner(lvlnumber_);
    }

    /**
     * Escape function
     * ///////////////////////////////////
     * This function is called when the escape button is pressed. If the current object is a levelstate object
     * it returns true otherwise false
     */
    bool Handle1() override{
        std::cout << "Transitioned to MenuState" << std::endl;
        return true;
    }

    /**
     * Enter function
     * ///////////////////////////////////
     * This function is called when the enter button is pressed. If the current object is a levelstate object
     * it returns false otherwise true
     */
    bool Handle2() override{
        std::cout << "Already in LevelState" << std::endl;
        return false;
    }

    int Handle3() override{
            return 0;
    }

    int Handle4() override{
            return 0;
    }

    /**
     * Statecheck function
     * ///////////////////////////////////
     * This function is called to check wich state the game is in. If the current object is a levelstate object
     * it returns false otherwise true
     */
    bool Handle5()override{
        return false;
    }

    int maxNumber() override{
        return 0;
    }

private:
    //current levelnumber
    int lvlnumber_;

    //pointer to the current world
    std::shared_ptr<World> world_;
};


#endif //MEATBOY_SAID_YANDARBIEV_LEVELSTATE_H
