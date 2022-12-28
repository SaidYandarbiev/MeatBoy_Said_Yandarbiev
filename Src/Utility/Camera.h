//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_CAMERA_H
#define MEATBOY_SAID_YANDARBIEV_CAMERA_H


#include "Vector.h"
#include "vector"
#include "iostream"

namespace Utility{
//Class representing the camera of the game
    class Camera
    {
    public:

        /**
        * Constructor
        * //////////////////////////////////////
        *The constructor creates a camera object
        */
        explicit Camera(Vector2u windowsize, std::string fixed_or_not);

        /**
        * Update player
        * //////////////////////////////////////
        *Function that updates the position of the player
        */
        void UpdatePlayer(Vector2f position1, bool jumping);

        /**
        * Position in pixels
        * //////////////////////////////////////
        *Function that returns the position in pixels of the given position
         */
        Vector2f PositionInPixels(Vector2f position2) const;

        /**
        * Get position
        * //////////////////////////////////////
        *Function that returns the position of the camera
        */
        float GetPosition() const;

        /**
        * Player died
        * //////////////////////////////////////
        *This function sets the position of the camera to the startposition
        */
        void playerDied(){
            OorsprongPunt = OriginalPunt;
        }

    private:
        //The size of the renderwindow
        Utility::Vector2u RenderWindow = Vector2u(600, 900);

        //Position of the camera
        Utility::Vector2f position = Vector2f(0, 0);

        //X size of the camera
        Utility::Vector2f CameraSizeX = Vector2f(0, 31);

        //Y size of the camera
        Utility::Vector2f CameraSizeY = Vector2f(0, 46);

        //Gives the source point
        Utility::Vector2f OorsprongPunt = Vector2f(0, 0);

        Utility::Vector2f OriginalPunt = Vector2f(0,0);

        //If gameended boolean == true, then the game has ended
        bool gameended = false;

        //String that tells us if the camera is fixed or not
        std::string f_o_n = "";
    };

}



#endif //MEATBOY_SAID_YANDARBIEV_CAMERA_H
