//
// Created by said2 on 10-11-2022.
//

#include "Camera.h"
Utility::Camera::Camera(Vector2u windowsize, std::string fixed_or_not) {
    RenderWindow = windowsize;
    f_o_n = fixed_or_not;
}

void Utility::Camera::UpdatePlayer(Vector2f position1, bool jumping)
{
    position.x = position1.x - OorsprongPunt.x;
    position.y = position1.y - OorsprongPunt.y;
    if (position.y < 0){
        gameended = true;
    }

    if (position.y > CameraSizeY.y / 2 && jumping && f_o_n == "moving") {
        OorsprongPunt.y = OorsprongPunt.y + (position.y - CameraSizeY.y / 2);
     }

    if(f_o_n == "automove"){
        OorsprongPunt.y += 0.02;
    }
}

Utility::Vector2f Utility::Camera::PositionInPixels(Vector2f position2) const
{

    position2.x = position2.x - OorsprongPunt.x;
    position2.y = position2.y - OorsprongPunt.y;

    position2.x *= (RenderWindow.x / CameraSizeX.y);
    position2.y *= (RenderWindow.y / CameraSizeY.y);
    position2.y = RenderWindow.y - position2.y + 5;


    return position2;
}
Utility::Vector2f Utility::Camera::GetCameraSizeX() { return CameraSizeX; }

Utility::Vector2f Utility::Camera::GetCameraSizeY() { return CameraSizeY; }

float Utility::Camera::GetRenderWindowSizeX() const { return RenderWindow.x; }

float Utility::Camera::GetRenderWindowSizeY() const { return RenderWindow.y; }

float Utility::Camera::GetPosition() const { return OorsprongPunt.y; }

bool Utility::Camera::getGameEnded() const { return gameended;}