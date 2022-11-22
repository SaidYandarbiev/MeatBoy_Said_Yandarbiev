//
// Created by said2 on 10-11-2022.
//

#include "Stopwatch.h"
Utility::Stopwatch* Utility::Stopwatch::getInstance()
{
    static Stopwatch instance;

    return &instance;
}