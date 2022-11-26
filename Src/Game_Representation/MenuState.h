//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_MENUSTATE_H
#define MEATBOY_SAID_YANDARBIEV_MENUSTATE_H

#include "State.h"

class MenuState : public State{
public:
    MenuState(){}

    bool Handle1() override{
        std::cout << "Already in MenuState" << std::endl;
        return false;
    }

    bool Handle2() override{
        std::cout << "Transitioned to LevelState" << std::endl;
        return true;
    }

    int Handle3() override{
        if(lvlnumber < 3){
            lvlnumber += 1;
        }
        return lvlnumber;
    }

    int Handle4() override{
        if(lvlnumber > 1){
            lvlnumber -= 1;
        }
        return lvlnumber;

    }

    bool Handle5() override{
        return true;
    }

    int getLvlNumber() override {
        return lvlnumber;
    }

private:
    int lvlnumber = 1;
};


#endif //MEATBOY_SAID_YANDARBIEV_MENUSTATE_H
