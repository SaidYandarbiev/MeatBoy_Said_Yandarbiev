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

    menuView = make_shared<MenuView>(MenuView(1));

    amount_of_lvl = stateManager_->maxNumber();

}

void Game::Update()
{
    if(m_world){
        m_world->Update();
        if(m_world->getGameEnded() && m_world->getLvlNumber() != amount_of_lvl){
            int lvl = m_world->getLvlNumber() + 1;
            concreteFactory = nullptr;
            m_world = nullptr;
            concreteFactory = std::move(make_shared<ConcreteFactory>(ConcreteFactory()));
            m_world = std::move(make_shared<World>(windowsize, concreteFactory));
            m_world->setLvlNumber(lvl);
            stateManager_->Next(m_world);
        }

        else if(m_world->getGameEnded() && m_world->getLvlNumber() == amount_of_lvl){
            concreteFactory = nullptr;
            m_world = nullptr;
            stateManager_->Request1();
            menuView = make_shared<MenuView>(MenuView(1));
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
            menuView = make_shared<MenuView>(MenuView(1));
        }
        amount_of_lvl = stateManager_->maxNumber();
    }

    else if(event.key.code == sf::Keyboard::Enter){
        if(stateManager_->Request5()){
            menuView = nullptr;
            concreteFactory = std::move(make_shared<ConcreteFactory>());
            m_world = m_world =std::move(make_shared<World>(windowsize, concreteFactory));
            stateManager_->Request2(m_world);
        }
    }
    if(stateManager_->Request5()) {

        if (event.key.code == sf::Keyboard::D) {
            menuView->notify(stateManager_->Request3());
        } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
            menuView->notify(stateManager_->Request4());
        }
    }

    else{
        m_world->GetState()->ClickedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        m_world->GetState()->ClickedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        m_world->GetState()->ClickedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    }

}

void Game::Render()
{

    if (stateManager_->Request5()){
        //Enter Menustate
        sf::Sprite sprite = sf::Sprite();
        sf::Texture texture;
        sf::Text lvl;

        lvl.setFont(font);
        lvl.setString(to_string(menuView->currLvl()));
        lvl.setPosition(300,300);

        sf::Text text;
        text.setFont(font);
        text.setString("Level select screen:");
        text.setPosition(175,200);

        m_window->BeginDraw();
        m_window->Draw(sprite);
        m_window->Draw(lvl);
        m_window->Draw(text);
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

        texture.loadFromFile("Sprites/forestbg.png");
        sprite.setScale(2,2);
        sprite.setTexture(texture);
        m_window->Draw(sprite);

        sprite.setScale(1,1);
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
Game::~Game() {}
