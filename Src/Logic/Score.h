//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_SCORE_H
#define MEATBOY_SAID_YANDARBIEV_SCORE_H

#include "Observer.h"

class Score : public Observer {
public:
    Score(){}

    void notify(Utility::Vector2f vector2F, Direction, bool wall) override{}
    void notify(int lvlnumber)override{
        if(curr_score > 0) {
            curr_score -= 1;
        }
    };

    int getScore(){
        return curr_score;
    }

    void resetScore(){
        curr_score = 1000;
    }

private:
    int curr_score = 1000;
};


#endif //MEATBOY_SAID_YANDARBIEV_SCORE_H
