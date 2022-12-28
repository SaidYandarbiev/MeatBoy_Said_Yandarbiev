//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_STOPWATCH_H
#define MEATBOY_SAID_YANDARBIEV_STOPWATCH_H

#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>

namespace Utility{
    class Stopwatch
    {
    public:
        /**
        * Constructor
        * //////////////////////////////////////
        *The constructor creates a Stopwatch object
        */
        static Stopwatch* getInstance();

        /**
        * Reset
        * //////////////////////////////////////
        * This function resets the start time to the time now
         */
        void Reset() { start_time = std::chrono::steady_clock::now(); }

        /**
        * Tick
        * //////////////////////////////////////
        * This function is called every tick and it updates the deltatime to
        */
        void tick() { delta_time = std::chrono::steady_clock::now() - start_time; }

        /**
        * Get delta time
        * //////////////////////////////////////
        * This function returns the delta time
         */
        float getDeltaTime() const { return delta_time.count(); }


        void FrameBalancing()
        {
            if (delta_time.count() < 1000.0 / 60.0) {
                std::chrono::duration<double, std::milli> delta_ms(1000.0 / 60 - delta_time.count());
                auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
                std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
            }
            tick();
            Reset();
        }

    private:

        Stopwatch() { Reset(); }

        ~Stopwatch() {}

        //Stopwatch instance
        static Stopwatch* instance;

        //Delta time
        std::chrono::duration<float, std::milli> delta_time = std::chrono::steady_clock::now()-std::chrono::steady_clock::now();

        //Start time of the stopwatch
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    };
}

#endif //MEATBOY_SAID_YANDARBIEV_STOPWATCH_H
