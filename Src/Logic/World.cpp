//
// Created by said2 on 10-11-2022.
//

#include "World.h"


World::World(Utility::Vector2u u, std::shared_ptr<AbstractFactory> sharedPtr) {
    concreteFactory = sharedPtr;
    m_windowSize = u;
    camera = std::make_shared<Utility::Camera>(m_windowSize);
    states = std::make_unique<Utility::States>();
}

void World::Update() {

    nocollision = true;
    ceilingcollision = true;
    walljump = true;
    player->Update(states, m_windowSize, XWorldSize.GetY(),camera);

    if((player->getFalling() || player->getJumping()) && walljump){
        for (int i = 0; i < walls.size(); i++) {
            if (player->CheckCollision(walls[i]->getx(), walls[i]->gety(), player->getx(), player->gety(), 1.5, 0, 1,1) && player->getDirection() == Direction::Right
            && !player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),1.3,1.3,1.3,1)) {
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
        if(player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),1.3,1.3,1.3,0) && !player->getJumping()){
            player->setFalling(false);
            nocollision = false;
            ceilingcollision = false;
            walljump = false;
            player->setWall("",walljump);
        }
    }

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

    if(player->CheckCollision(goal->getx(), goal->gety(), player->getx(), player->gety(),0,1.5,1,1) || player->CheckCollision(goal->getx(), goal->gety(), player->getx(), player->gety(), 1.5, 0, 1,1) ){
        gameEnded = true;
    }



//    if(walljump){
//        for(int i = 0; i < walls.size(); i++){
//            if(player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),0,1,-1,0.8)){
//                nocollision = false;
//                player->setWall("right",walljump);
//            }
//
//            if(player->CheckCollision(walls[i]->getx(),walls[i]->gety(),player->getx(),player->gety(),1,0,0.3,0.8)){
//                nocollision = false;
//                player->setWall("left",walljump);
//            }
//        }
//
//    }

    if(nocollision){
        if(!player->getFalling() && !player->getJumping()) {
            player->setFalling(true);
            player->setWall("", false);
        }
    }
}

void World::Spawner(int lvlnumber) {
    lvlnumber = lvlnumber;
    tinyxml2::XMLDocument doc;
    std::string file = "Levels/Level" + std::to_string(lvlnumber) + ".xml" ;
    doc.LoadFile(file.c_str());

    for(int i = 1; i < 47; i++){
        for(int j = 0; j < 31; j++){
            std::string r = "row" + std::to_string(i);
            std::string c = "col" + std::to_string(j+1);
            std::string a = doc.FirstChildElement("world")->FirstChildElement(r.c_str())->FirstChildElement(c.c_str())->GetText();
            if(a == "block"){
                Utility::Vector2f vector2F = Utility::Vector2f(j,i);
                walls.push_back(concreteFactory->CreateWallModel(vector2F,camera));
            }

            else if(a == "player"){
                Utility::Vector2f vector2F = Utility::Vector2f(j,i);
                player = concreteFactory->CreatePlayerModel(vector2F,camera);
            }

            else if(a == "nothing"){

            }

            else if(a == "goal"){
                Utility::Vector2f vector2F = Utility::Vector2f(j,i);
                goal = concreteFactory->CreateGoalModel(vector2F,camera);
            }

        }
    }

}

void World::Reset() {

}


