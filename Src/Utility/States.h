//
// Created by said2 on 15-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_STATES_H
#define MEATBOY_SAID_YANDARBIEV_STATES_H


namespace Utility{

//Struct that gives the state a player is in
    struct States
    {
        //If Clickedleft == true then there was a left arrow press on the keyboard
        bool ClickedLeft = false;
        //If Clickedright == true then there was a right arrow press on the keyboard
        bool ClickedRight = false;

        bool ClickedUp = false;

    };

}


#endif //MEATBOY_SAID_YANDARBIEV_STATES_H
