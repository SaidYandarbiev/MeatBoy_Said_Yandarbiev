//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_WINDOW_H
#define MEATBOY_SAID_YANDARBIEV_WINDOW_H


#include "SFML/Graphics.hpp"
#include "string"
using namespace std;

namespace Utility {
    class Window {
    public:

        /**
        * Constructor
        * //////////////////////////////////////
        *The constructor creates a window object with the function setup
        */
        Window() { Setup("Window", sf::Vector2u(640, 480)); }

        /**
        * Constructor
        * //////////////////////////////////////
        *The constructor creates a window object with the function setup
         *      Parameters:
         *              l_title: Title of the window
         *              l_size: Size of the window
         */
        Window(const string &l_title, const sf::Vector2u &l_size) { Setup(l_title, l_size); };

        /**
        * Destructor
        * //////////////////////////////////////
        *Deletes the current object
         */
        ~Window() { Destroy(); };

        /**
        * BeginDraw
        * //////////////////////////////////////
        *Function that clears everything on the window
         */
        void BeginDraw() { m_window.clear(sf::Color::Black); };

        /**
        * EndDraw
        * //////////////////////////////////////
        *Function that displays everything that was just drawn
         */
        void EndDraw() { m_window.display(); };

        /**
        * Update
        * //////////////////////////////////////
        *Function that updates the window
         */
        void Update() {
            sf::Event event{};
            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    m_isDone = true;
                } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
                    ToggleFullscreen();
                }
            }
        };

        bool IsDone() const { return m_isDone; };

        void SetIsDone() { m_isDone = !m_isDone; }

        void ToggleFullscreen() {
            m_isFullscreen = !m_isFullscreen;
            Destroy();
            Create();
        };

        /**
        * Draw
        * //////////////////////////////////////
        *Function that draws an object on the window
         */
        void Draw(sf::Drawable &l_drawable) { m_window.draw(l_drawable); };

        //The renderwindow object
        sf::RenderWindow m_window;

    private:

        /**
        * Setup
        * //////////////////////////////////////
        *This function creates the window object using the function Create
         * Parameter:
         *          l_title: window title
         *          l_size: window size
        */
        void Setup(const std::string &l_title, const sf::Vector2u &l_size) {
            m_windowTitle = l_title;
            m_windowSize = l_size;
            m_isFullscreen = false;
            m_isDone = false;
            Create();
        };

        void Destroy() { m_window.close(); };

        /**
        * Create
        * //////////////////////////////////////
        *This function creates the window object using a sf::Renderwindow object
         */
        void Create() {
            auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
            m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
        };

        //Size of the window
        sf::Vector2u m_windowSize;

        //Title of the window
        string m_windowTitle;

        bool m_isDone;
        bool m_isFullscreen;
    };

}


#endif //MEATBOY_SAID_YANDARBIEV_WINDOW_H
