//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_STATEMANAGER_H
#define MEATBOY_SAID_YANDARBIEV_STATEMANAGER_H

#include <utility>

#include "MenuState.h"
#include "LevelState.h"

class StateManager {
private:
    //current state of the game
    std::shared_ptr<State> state_;

public:

    /**
     * Constructor
     * ///////////////////////////////////
     * Constructor that creates a StateManager object.
     * It also initializes the State object with a MenuState object
     */
    StateManager(){
        state_ = std::move(std::make_shared<MenuState>(MenuState()));
        state_->set_statemanager(std::make_shared<StateManager>(*this));
    }

    /**
     * Escape request
     * ///////////////////////////////////
     * This function is called when a Escape input is done on the keyboard.
     * This function calls the "Handle1" function from its State
     */
    void Request1(){
        //if clicked escape
        if(state_->Handle1()){
            state_ = std::move(std::make_shared<MenuState>(MenuState()));
            state_->set_statemanager(std::make_shared<StateManager>(*this));
        }
    }

    /**
     * Enter request
     * ///////////////////////////////////
     * This function is called when a Enter input is done on the keyboard.
     * This function calls the "Handle2" function from its State
     */
    void Request2(std::shared_ptr<World> world){
        //if clicked enter
        if(state_->Handle2()){
            state_ = std::move(std::make_shared<LevelState>(LevelState(state_->getLvlNumber(),world)));
            state_->set_statemanager(std::make_shared<StateManager>(*this));
        }
    }

    /**
     * D request
     * ///////////////////////////////////
     * This function is called when the "D" key is pressed.
     * This function calls the "Handle3" function from its State
     */
    int Request3(){
        //D
        return state_->Handle3();
    }

    /**
     * D request
     * ///////////////////////////////////
     * This function is called when the "A" key is pressed.
     * This function calls the "Handle4" function from its State
     */
    int Request4(){
        //A
        return state_->Handle4();
    }

    /**
     * StateCheck
     * ///////////////////////////////////
     * This function is called when the Game wants to check in what state it is in.
     * This function calls the function "Handle5" of its current state.
     */
    bool Request5(){
        //Statecheck
        return state_->Handle5();
    }

    /**
     * Max amount of levels
     * ///////////////////////////////////
     * This function is called when the Game wants to check how many levels it has
     * This function is called when transitioning to the menustate.
     */
    int maxNumber(){
        return state_->maxNumber();
    }

    /**
     * Next level
     * ///////////////////////////////////
     * This function is called when transitioning from 1 level to the next level.
     * It replaces the current levelstate with a new levelstate of the next level.
     * */
    void Next(std::shared_ptr<World> world){
        state_ = nullptr;
        state_ = std::move(std::make_shared<LevelState>(LevelState(world->getLvlNumber(),world)));
        state_->set_statemanager(std::make_shared<StateManager>(*this));
    }
};


#endif //MEATBOY_SAID_YANDARBIEV_STATEMANAGER_H
