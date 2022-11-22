//
// Created by said2 on 10-11-2022.
//

//#include "SFML/Graphics.hpp"
//
//int main(int argc, char ** argv){
//    sf::RenderWindow renderWindow(sf::VideoMode(600, 600), "Demo Game");
//
//
//    sf::Event event;
//    sf::Texture texture;
//    sf::IntRect rect(0,0,0,0);
//    texture.loadFromFile("Sprites/foresttiles01.png",rect);
//    texture.loadFromFile("Sprites/retromeatboyfinal.png",rect);
//
////    Meatboy left
////    sf::Sprite sprite(texture,sf::IntRect(116,40,38,35));
//
//    sf::Sprite sprite(texture,sf::IntRect(116,40,38,35));
//    sprite.setPosition(300,200);
//
//
//    while (renderWindow.isOpen()){
//        while (renderWindow.pollEvent(event)){
//            if (event.type == sf::Event::EventType::Closed)
//                renderWindow.close();
//        }
//
//        renderWindow.clear();
//        renderWindow.draw(sprite);
//        renderWindow.display();
//    }
//}

#include "Src/Game_Representation/Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
    // Program entry point.
    Game game("Meatboy", sf::Vector2u(600, 900)); // Creating our game object.

    while (!game.GetWindow()->IsDone()) {
        sf::Event event{};

        while (game.GetWindow()->m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.GetWindow()->SetIsDone();
            }
        }

        // Game loop.
        if (game.GetWindow()->m_window.isOpen()) {

            Utility::Stopwatch::getInstance()->tick();

            Utility::Stopwatch::getInstance()->FrameBalancing();

            game.HandleInput(event);

            game.Update();

            game.Render();
        }

        // Sleep for 0.2 seconds
    }
    return 0;
}