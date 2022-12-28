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

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a Observer object
    */
    Observer(){}

    /**
    * Attach
    * //////////////////////////////////////
    *This function attaches a subject to the current observer object
     * Parameters:
     *            subject: SUbject object which the current object attaches to
    */
    void Attach(std::shared_ptr<Subject> subject){
        subject_ = subject;
    }

    /**
     * Notify current object
     * ////////////////////////////////////
     * This function is called after the update of the Subject, which the current Observer is connected to
     * Relevant Parameters:
     *             vector2F: Current position of the wall in pixels
     */
    virtual void notify(Utility::Vector2f vector2F, Direction, bool wall) = 0;

    /**
     * Notify current object
     * ////////////////////////////////////
     * This function is called after the update of the Subject, which the current Observer is connected to
     * Relevant Parameters:
     *             lvlnumber: number of the current lvl
     */
    virtual void notify(int lvlnumber) = 0;

    /**
     *  Get file
     * ////////////////////////////////////
     * This function returns the filename of the corresponding observer object
     */
    std::string getFile(){
        return file_;
    }

    /**
     * Get position
     * ////////////////////////////////////
     * This function returns the position of the current object
     */
    Utility::Vector2f getPosition(){
        return pos_;
    }

private:
    //Subject which the current observer object is attached to
    std::shared_ptr<Subject> subject_;
protected:

    //Position of the current observer object
    Utility::Vector2f pos_ = Utility::Vector2f(0,0);

    //Filename of the current observer object
    std::string file_ = "";
};


#endif //MEATBOY_SAID_YANDARBIEV_OBSERVER_H
