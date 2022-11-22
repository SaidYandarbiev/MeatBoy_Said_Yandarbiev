//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_SUBJECT_H
#define MEATBOY_SAID_YANDARBIEV_SUBJECT_H

#include <memory>
#include "../Utility/Vector.h"
#include <string>
#include <vector>
#include "../Utility/Camera.h"
#include "../Utility/Direction.h"

class Observer;

class Subject {
public:
    Subject()= default;

    void Attach(std::shared_ptr<Observer> observer);

//    virtual void Detach(std::shared_ptr<Observer>observer) = 0;
protected:
    std::vector<std::shared_ptr<Observer>> observers;
};


#endif //MEATBOY_SAID_YANDARBIEV_SUBJECT_H
