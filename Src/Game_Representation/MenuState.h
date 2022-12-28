//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_MENUSTATE_H
#define MEATBOY_SAID_YANDARBIEV_MENUSTATE_H

#include "State.h"
#include "../Utility/tinyxml2.h"

class MenuState : public State{
public:
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

    bool Handle1() override{
        std::cout << "Already in MenuState" << std::endl;
        return false;
    }

    bool Handle2() override{
        std::cout << "Transitioned to LevelState" << std::endl;
        return true;
    }

    int Handle3() override{
        if(lvlnumber < maxnumber){
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

    int maxNumber() override{
        return maxnumber;
    }

private:
    int lvlnumber = 1;
    int maxnumber = 0;
};


#endif //MEATBOY_SAID_YANDARBIEV_MENUSTATE_H
