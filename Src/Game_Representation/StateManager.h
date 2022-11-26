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
    std::shared_ptr<State> state_;

public:

    StateManager(){
        state_ = std::move(std::make_shared<MenuState>(MenuState()));
        state_->set_statemanager(std::make_shared<StateManager>(*this));
    }

    void TransitionTo(std::shared_ptr<State> state){
        state_ = std::move(state);
        state_->set_statemanager(std::make_shared<StateManager>(*this));
    }

    void Request1(){
        //if clicked escape
        if(state_->Handle1()){
            state_ = std::move(std::make_shared<MenuState>(MenuState()));
            state_->set_statemanager(std::make_shared<StateManager>(*this));
        }
    }

    void Request2(std::shared_ptr<World> world){
        //if clicked enter
        if(state_->Handle2()){
            state_ = std::move(std::make_shared<LevelState>(LevelState(state_->getLvlNumber(),world)));
            state_->set_statemanager(std::make_shared<StateManager>(*this));
        }
    }

    int Request3(){
        //D
        return state_->Handle3();
    }

    int Request4(){
        //A
        return state_->Handle4();
    }

    bool Request5(){
        //Statecheck
        return state_->Handle5();
    }

    void Next(std::shared_ptr<World> world){
        state_ = nullptr;
        state_ = std::move(std::make_shared<LevelState>(LevelState(world->getLvlNumber(),world)));
        state_->set_statemanager(std::make_shared<StateManager>(*this));
    }
};


#endif //MEATBOY_SAID_YANDARBIEV_STATEMANAGER_H
