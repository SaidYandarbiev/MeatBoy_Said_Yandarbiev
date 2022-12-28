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

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a Subject object
    */
    Subject()= default;

    /**
    * Attach
    * //////////////////////////////////////
    * This function attaches a observer to the current subject object
     */
    void Attach(std::shared_ptr<Observer> observer);

protected:

    //Vector of all the observers attached to the current subject
    std::vector<std::shared_ptr<Observer>> observers;
};


#endif //MEATBOY_SAID_YANDARBIEV_SUBJECT_H
