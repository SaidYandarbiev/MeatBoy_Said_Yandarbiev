//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_GAME_H
#define MEATBOY_SAID_YANDARBIEV_GAME_H



#include "../Utility/Window.h"
#include "string"
#include "StateManager.h"
#include "../Utility/Vector.h"
#include "../Utility//Camera.h"
#include "../Logic/EntityModel.h"
#include "../Logic/Stopwatch.h"
#include "../Logic/World.h"
#include "ConcreteFactory.h"



class Game
{
public:

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a Game object
     * Parameters:
     *              title: Title of the window
     *              vector2U: Windowsize
    */
    Game(std::string title, sf::Vector2u vector2U);

    /**
    * Destructor
    * //////////////////////////////////////
    *The destructor deletes the existing game object
    */
    ~Game();

    //This functions handles the keyboard inputs
    /**
    * HandleInput
    * //////////////////////////////////////
    *This function is used to check if there is any keyboard input and handles them
    * Parameters:
    *           Event: sfml object used to indicate an event for example a keyboard input
    */
    void HandleInput(sf::Event event);

    /**
    * Update
    * //////////////////////////////////////
    *This function updates the objects of game every tick
    */
    void Update();

    /**
    * Render
    * //////////////////////////////////////
    *This function draws every drawable object every tick
    */
    void Render();
    ;

    /**
    * GetWindow
    * //////////////////////////////////////
    * This function returns the window
    */
    Utility::Window* GetWindow() const { return m_window; };


private:
    //The game window
    Utility::Window* m_window = nullptr;

    //The world of the game
    std::shared_ptr<World> m_world = nullptr;

    //Pointer to the abstract factory
    shared_ptr<AbstractFactory> concreteFactory = nullptr;

    std::shared_ptr<MenuView> menuView = nullptr;

    //Text that displays the score
    sf::Text score;

    //Font used for the score
    sf::Font font;

    //Statemanager
    shared_ptr<StateManager> stateManager_;

    int amount_of_lvl = 3;

    //Boolean that tells us if the previous key state was the up key button
    bool previousKeyState;

    //The size of the window
    Utility::Vector2u windowsize = Utility::Vector2u(0,0);
};



#endif //MEATBOY_SAID_YANDARBIEV_GAME_H
