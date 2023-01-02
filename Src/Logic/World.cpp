//
// Created by said2 on 10-11-2022.
//

#include "World.h"


World::World(Utility::Vector2u u, std::shared_ptr<AbstractFactory> sharedPtr) {
    concreteFactory = sharedPtr;
    m_windowSize = u;
    states = std::make_unique<Utility::States>();
}

void World::Update() {

    nocollision = true;
    ceilingcollision = true;
    walljump = true;
    player->Update(states, m_windowSize, XWorldSize.GetY(),camera);

    //This ifstatement checks if a player is walljumping or not when a player is falling or jumping
    if((player->getFalling() || player->getJumping())){
        for (int i = 0; i < walls.size(); i++) {
            if (player->CheckCollision(walls[i]->getx(), walls[i]->gety(), player->getx(), player->gety(), 1.5, 0, 1,1) && player->getDirection() == Direction::Right
            && !player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),1.2,1.2,1.2,1)) {
                player->setWall("left", walljump);
            }
        }

        for (int i = 0; i < walls.size(); i++) {
            if (player->CheckCollision(walls[i]->getx(), walls[i]->gety(), player->getx(), player->gety(),0,1.5,1,1) && player->getDirection() == Direction::Left
                && !player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),1.3,1.3,1.3,1)) {
                player->setWall("right", walljump);
            }
        }
    }


    for(int i = 0; i < walls.size(); i++){
            //This ifstatement checks if a player has collision with the ground after falling
        if(player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),1.5,1.3,1.3,0) && !player->getJumping()){
            player->setFalling(false);
            nocollision = false;
            ceilingcollision = false;
            walljump = false;
            player->setWall("",walljump);
        }
    }

    //This if statement checks if a player has collision with a ceiling or not
    if(ceilingcollision && !player->getFalling()){
        bool hit = false;
        for(int i = 0; i < walls.size(); i++){
            if(player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),1.3,1.3,1.3,1)){
                player->setFalling(true);
                walljump = false;
                nocollision = false;
                player->setWall("",walljump);
                hit = true;
                break;
            }
        }
        if(!hit){
            ceilingcollision = false;
        }
    }
    //This ifstatement checks if a player
    if(!ceilingcollision && !player->getFalling() && !player->getJumping()) {
        for (int i = 0; i < walls.size(); i++) {
            if (player->CheckCollision(walls[i]->getx(), walls[i]->gety(), player->getx(), player->gety(), 1.2, 0, 0,1) && player->getDirection() == Direction::Right) {
                player->setxspeed(-0.1);
                walljump = false;
            }
        }

        for (int i = 0; i < walls.size(); i++) {
            if (player->CheckCollision(walls[i]->getx(), walls[i]->gety(), player->getx(), player->gety(),0,1.2,0,1) && player->getDirection() == Direction::Left) {
                player->setxspeed(0.1);
                walljump = false;
            }
        }
    }

    //This ifstatement checks if the player is walljumping or not
    if(!ceilingcollision &&(player->getFalling() || player->getJumping()) && walljump){
        for (int i = 0; i < walls.size(); i++) {
            if (player->CheckCollision(walls[i]->getx(), walls[i]->gety(), player->getx(), player->gety(), 1.5, 0, 1,1) && player->getDirection() == Direction::Right) {
                player->setWall("left", walljump);
            }
        }

        for (int i = 0; i < walls.size(); i++) {
            if (player->CheckCollision(walls[i]->getx(), walls[i]->gety(), player->getx(), player->gety(),0,1.5,1,1) && player->getDirection() == Direction::Left) {
                player->setWall("right", walljump);
            }
        }
    }

    //This ifstatement checks if the player has had collision with the goal or not
    if(player->CheckCollision(goal->getx(), goal->gety(), player->getx(), player->gety(),0,1.5,1,1) || player->CheckCollision(goal->getx(), goal->gety(), player->getx(), player->gety(), 1.5, 0, 1,1) ){
        gameEnded = true;
    }


    //The player enters this ifstatement if he has not collision with any entity
    if(nocollision){
        if(!player->getFalling() && !player->getJumping()) {
            player->setFalling(true);
            player->setWall("", false);
        }
    }
    for(int i = 0; i < walls.size(); i++){
        if(player->getDied()){
            walls[i]->playerDied();
        }
        walls[i]->Update(camera);
    }
    goal->playerDied();
    goal->Update(camera);
    score->notify(lvlNumber);
    if(player->getDied()) {
        score->resetScore();
    }
    player->setDied();
}

void World::Spawner(int lvlnumber) {
    if(lvlNumber == 0) {
        lvlNumber = lvlnumber;
    }

    tinyxml2::XMLDocument doc;
    std::string file = "Levels/Level" + std::to_string(lvlNumber) + ".xml" ;
    doc.LoadFile(file.c_str());
    auto view = doc.FirstChildElement()->FirstChildElement()->GetText();
    auto row = doc.FirstChildElement("world")->FirstChildElement("row1");
    camera = std::make_shared<Utility::Camera>(m_windowSize,view);
    int r = 1;
    while (row){
        int c = 0;
        auto col = row->FirstChildElement("col1");
        while(col){
            std::string a = col->GetText();
            if (a == "block") {
                Utility::Vector2f vector2F = Utility::Vector2f(c, r);
                walls.push_back(concreteFactory->CreateWallModel(vector2F, camera));
            } else if (a == "player") {
                Utility::Vector2f vector2F = Utility::Vector2f(c, r);
                player = concreteFactory->CreatePlayerModel(vector2F, camera);
            } else if (a == "nothing") {

            } else if (a == "goal") {
                Utility::Vector2f vector2F = Utility::Vector2f(c, r);
                goal = concreteFactory->CreateGoalModel(vector2F, camera);
            }
            col = col->NextSiblingElement();
            c += 1;
        }
        row = row->NextSiblingElement();
        r += 1;
    }
}



