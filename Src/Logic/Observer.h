//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_OBSERVER_H
#define MEATBOY_SAID_YANDARBIEV_OBSERVER_H

#include <string>
#include <utility>
#include "../Utility/Vector.h"
#include "memory"
#include "../Utility/Direction.h"

class Subject;

class Observer {
public:
    Observer(){}

    void Attach(std::shared_ptr<Subject> subject){
        subject_ = subject;
    }

    virtual void notify(Utility::Vector2f vector2F, Direction, bool wall) = 0;
    virtual void notify(int lvlnumber) = 0;

    std::string getFile(){
        return file_;
    }

    Utility::Vector2f getPosition(){
        return pos_;
    }

private:
    std::shared_ptr<Subject> subject_;
protected:
    Utility::Vector2f pos_ = Utility::Vector2f(0,0);
    std::string file_ = "";
};


#endif //MEATBOY_SAID_YANDARBIEV_OBSERVER_H
