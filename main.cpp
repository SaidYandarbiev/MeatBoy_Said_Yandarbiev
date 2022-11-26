//
// Created by said2 on 10-11-2022.
//


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