//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_STATE_H
#define MEATBOY_SAID_YANDARBIEV_STATE_H

#include <memory>
#include <iostream>
#include <utility>


class StateManager;

class State {
protected:
    std::shared_ptr<StateManager> stateManager_;

public:

    void set_statemanager(std::shared_ptr<StateManager> stateManager){
        stateManager_ = std::move(stateManager);
    }

    virtual bool Handle1() = 0;
    virtual bool Handle2() = 0;
    virtual int Handle3() = 0;
    virtual int Handle4() = 0;
    virtual bool Handle5() = 0;
    virtual int getLvlNumber(){
        return 0;
    }
};


#endif //MEATBOY_SAID_YANDARBIEV_STATE_H
