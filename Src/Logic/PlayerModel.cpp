//
// Created by said2 on 10-11-2022.
//

#include <math.h>
#include "PlayerModel.h"
#include "../Game_Representation/PlayerView.h"
#include "Stopwatch.h"

void PlayerModel::Update(Utility::Vector2f vector2F, std::shared_ptr<Utility::Camera> camera) {
    pos = vector2F;
    Utility::Vector2f pixels = camera->PositionInPixels(pos);
    for(int i = 0; i < observers.size(); i++){
        observers[i]->notify(pixels,direction, false);
    }
}

void PlayerModel::Update(std::shared_ptr<Utility::States> states, Utility::Vector2u, float y , std::shared_ptr<Utility::Camera> camera) {



    if(states->ClickedLeft){
        if((!walljump && !hitwall) || direction == Direction::Right) {
            forces.SetX(-2);
            direction = Direction::Left;
            walljump = false;
            hitwall = false;
        }

        else{
            forces.SetX(0);
        }
    }

    else if(states->ClickedRight){
        if((!walljump && !hitwall) || direction == Direction::Left) {
            forces.SetX(2);
            direction = Direction::Right;
            walljump = false;
            hitwall = false;
        }
        else{
            forces.SetX(0);
        }
    }

    else{
        forces.SetX(0);

    }

    if (states->ClickedUp && !falling && !jumping && !walljump){
        jumping = true;
        falling = false;
        ysnelheid = -6;
    }

    else if(states->ClickedUp && walljump){
        if(direction == Direction::Right){
            xsnelheid = -0.3;
            ysnelheid = -6;
            walljump = false;
            jumping = true;
            falling = false;
            direction = Direction::Left;
        }
        else if(direction == Direction::Left){
            xsnelheid = 0.3;
            ysnelheid = -6;
            walljump = false;
            jumping = true;
            falling = false;
            direction = Direction::Right;
        }
    }


    if (ysnelheid > 0) {
        falling = true;
        jumping = false;
    }

    //This calculates the y speed with the forces and the time and updates the y position
    if(falling || jumping){
        ysnelheid += (forces.GetY() / 2 * std::pow(Utility::Stopwatch::getInstance()->getDeltaTime() / 100, 2));
        pos.y -= ysnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 500);
    }

    //This calculates the x speed with the forces and the time and updates the x position
    xsnelheid *= 0.90;
    xversnelling = forces.GetX() / massa;
    xsnelheid = xsnelheid + (0.5 * xversnelling * (Utility::Stopwatch::getInstance()->getDeltaTime() / 30));
    pos.x += xsnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 10);

    camera->UpdatePlayer(pos, jumping);

    Utility::Vector2f pixels = camera->PositionInPixels(pos);

    for(int i = 0; i < observers.size(); i++){
        observers[i]->notify(pixels,direction, walljump);
    }
}
