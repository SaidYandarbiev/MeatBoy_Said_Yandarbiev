//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_LEVELSTATE_H
#define MEATBOY_SAID_YANDARBIEV_LEVELSTATE_H

#include "State.h"
#include "../Logic/World.h"

class LevelState : public State{
public:

    LevelState(int lvlnumber, std::shared_ptr<World> &world){
        lvlnumber_ = lvlnumber;
        world_ = world;
        world_->Spawner(lvlnumber_);
    }

    bool Handle1() override{
        std::cout << "Transitioned to MenuState" << std::endl;
        return true;
    }

    bool Handle2() override{
        std::cout << "Already in LevelState" << std::endl;
        return false;
    }
    int Handle3() override{
    }

    int Handle4() override{
    }

    bool Handle5()override{
        return false;
    }

private:
    int lvlnumber_;
    std::shared_ptr<World> world_;
};


#endif //MEATBOY_SAID_YANDARBIEV_LEVELSTATE_H
