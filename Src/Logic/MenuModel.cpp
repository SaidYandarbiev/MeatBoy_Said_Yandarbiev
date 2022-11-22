//
// Created by said2 on 13-11-2022.
//

#include "MenuModel.h"
#include "../Game_Representation/MenuView.h"

void MenuModel::Update(int lvlnumber) {
    lvlnumber_ = lvlnumber;
    for(int i = 0; i < observers.size(); i++){
        observers[i]->notify(lvlnumber_);
    }
}
