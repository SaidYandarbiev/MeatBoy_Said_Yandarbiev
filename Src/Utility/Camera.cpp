//
// Created by said2 on 10-11-2022.
//

#include "Camera.h"
Utility::Camera::Camera(Vector2u windowsize) { RenderWindow = windowsize; }

void Utility::Camera::UpdatePlayer(Vector2f position1, bool jumping)
{
    position.x = position1.x - OorsprongPunt.x;
    position.y = position1.y - OorsprongPunt.y;
    if (position.y < 0){
        gameended = true;
    }

    if (position.y > CameraSizeY.y / 2 && jumping) {
        OorsprongPunt.y = OorsprongPunt.y + (position.y - CameraSizeY.y / 2);
    }
}

std::vector<float> Utility::Camera::UpdateBonus(double width, double height, double bonuswidth,
                                                double bonusheight) const
{
    float playergamesizex = (RenderWindow.x / CameraSizeX.y) * width;
    float playergamesizey = (RenderWindow.y /CameraSizeY.y) * height;

    float factorx = playergamesizex /bonuswidth;
    float factory = playergamesizey / bonusheight;

    return {factorx,factory};
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