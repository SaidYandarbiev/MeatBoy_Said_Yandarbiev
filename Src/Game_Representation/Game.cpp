//
// Created by said2 on 10-11-2022.
//

#include "Game.h"

Game::Game(string title, sf::Vector2u vector2U)
{
    windowsize.x = vector2U.x;
    windowsize.y = vector2U.y;
    m_window = new Utility::Window(title, vector2U);
    stateManager_ = make_shared<StateManager>(StateManager());

    sf::Color color(0,0,0);
    font.loadFromFile("Sprites/OpenSans-Bold.ttf");
    score.setFont(font);
    score.setFillColor(color);
    score.setPosition(25,25);

}



void Game::Update()
{
    if(m_world){
        m_world->Update();
        if(m_world->getGameEnded()){
            concreteFactory = nullptr;
            m_world = nullptr;
            stateManager_->Request1();
        }
    }
    Utility::Stopwatch::getInstance()->FrameBalancing();
}

void Game::HandleInput(sf::Event event)
{

    if(event.key.code == sf::Keyboard::Escape){
        if(!stateManager_->Request5()){
            concreteFactory = nullptr;
            m_world = nullptr;
            stateManager_->Request1();
        }
    }

    else if(event.key.code == sf::Keyboard::Enter){
        if(stateManager_->Request5()){
            menuView = nullptr;
            concreteFactory = std::move(make_shared<ConcreteFactory>(ConcreteFactory(Utility::Vector2f(windowsize.x,windowsize.y))));
            m_world = m_world =std::move(make_shared<World>(windowsize, concreteFactory));
            stateManager_->Request2(m_world);
        }
    }
    if(stateManager_->Request5()) {

        if (event.key.code == sf::Keyboard::D) {
            stateManager_->Request3();
        } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
            stateManager_->Request4();
        }
    }

    else{
        m_world->GetState()->ClickedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        m_world->GetState()->ClickedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        m_world->GetState()->ClickedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    }
//
//    //First we update the clickedright and clickedleft with the key presses on our keyboard
//    m_world->GetState()->ClickedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
//    m_world->GetState()->ClickedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
//
//    //Then we check if our up key has been pressed
//    bool KeyUpDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
//
//    //If our up key has been pressed and our previouskey was not the upkey (so false) then we can let the player shoot
//    //And set previousKeyState on true (because our previous pressed key was up)
//    if(KeyUpDown && !previousKeyState){
//        m_world->GetState()->Shooting = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
//        previousKeyState = true;
//    }
//    //If we dont press the up key then our previousKeyState is false (because the up key was not the key pressed previously)
//    if(!KeyUpDown){
//        previousKeyState = false;
//    }

}

void Game::Render()
{

    if (stateManager_->Request5()){
        //Enter Menustate
        tinyxml2::XMLDocument doc;
        doc.LoadFile("Levels/Level1.xml");
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Texture texture1;
        texture.loadFromFile("Sprites/grass.png");
        texture1.loadFromFile("Sprites/dirt.png");
        m_window->BeginDraw();
        for(int i = 1; i < 46; i++){
            for(int j = 1; j < 31; j++){
                string r = "row" + to_string(i);
                string c = "col" + to_string(j);
                string b = "block";
                string a = doc.FirstChildElement("world")->FirstChildElement(r.c_str())->FirstChildElement(c.c_str())->GetText();
                if(a == b){
                    if(i%2 == 0 && j%2 ==0){
                        sprite.setTexture(texture);
                    }
                    else{
                        sprite.setTexture(texture1);
                    }
                }

                sprite.setPosition(585 - 20*j,885 - 20*i);
                m_window->Draw(sprite);
            }
        }

        m_window->EndDraw();
    }

    else{
//        //Enter levelstate
        sf::Sprite sprite = sf::Sprite();
        sf::Texture texture;
        std::vector<shared_ptr<Observer>> walls = concreteFactory->getWalls();
        shared_ptr<Observer> player = concreteFactory->getPlayer();
        shared_ptr<Observer> goal = concreteFactory->getGoal();
        m_window->BeginDraw();


        if(goal){
            texture.loadFromFile(goal->getFile());
            sprite.setTexture(texture);
            sprite.setPosition(goal->getPosition().x,goal->getPosition().y);
            m_window->Draw(sprite);
        }
        texture.loadFromFile("Sprites/grass.png");
        sprite.setTexture(texture);
        for(int i = 0; i < walls.size(); i++){

            sprite.setPosition(walls[i]->getPosition().x,walls[i]->getPosition().y);
            m_window->Draw(sprite);
        }

        if(player){
            texture.loadFromFile(player->getFile());
            sprite.setTexture(texture);
            sprite.setPosition(player->getPosition().x,concreteFactory->getPlayer()->getPosition().y);
            m_window->Draw(sprite);
        }
        score.setFont(font);
        int s = m_world->GetScore()->getScore();
        score.setString(to_string(s));
        m_window->Draw(score);

        m_window->EndDraw();
    }
    Utility::Stopwatch::getInstance()->Reset();
}