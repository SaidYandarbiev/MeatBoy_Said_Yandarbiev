project(MeatBoy_Said_Yandarbiev)
cmake_minimum_required(VERSION 3.10.2)


###################### SFML ######################
if(APPLE)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1-MAC/include")
    set( SFML_LIBRARY_DIR "libs/SFML-2.5.1-MAC/build/lib")

elseif (UNIX)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/include/")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/cmake/SFML/")
    set(SFML_SHARE "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/share/")

elseif(WIN32)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/include/")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/lib/cmake/SFML")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/lib/")
    file(GLOB SFML_DLL "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/bin/*.dll")
    file(COPY ${SFML_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

endif()

link_directories(SFML_LIBRARY_DIR )
include_directories(SFML_INCLUDE_DIR)

FILE(GLOB Game_Representation
        main.cpp
        Game_Representation/EntityView.cpp
        Game_Representation/EntityView.h
        Game_Representation/PlayerView.cpp
        Game_Representation/PlayerView.h
        Game_Representation/WallView.cpp
        Game_Representation/WallView.h
        Game_Representation/GoalView.cpp
        Game_Representation/GoalView.h
        Game_Representation/StateManager.cpp
        Game_Representation/StateManager.h
        Game_Representation/State.cpp
        Game_Representation/State.h
        Game_Representation/MenuState.cpp
        Game_Representation/MenuState.h
        Game_Representation/LevelState.cpp
        Game_Representation/LevelState.h
        Game_Representation/ConcreteFactory.cpp
        Game_Representation/ConcreteFactory.h
        Game_Representation/Game.cpp
        Game_Representation/Game.h)

FILE(GLOB Logic
        Logic/Observer.cpp
        Logic/Observer.h
        Logic/Score.cpp
        Logic/Score.h
        Logic/Subject.cpp
        Logic/Subject.h
        Logic/EntityModel.cpp
        Logic/EntityModel.h
        Logic/PlayerModel.cpp
        Logic/PlayerModel.h
        Logic/WallModel.cpp
        Logic/WallModel.h
        Logic/GoalModel.cpp
        Logic/GoalModel.h
        Logic/Stopwatch.cpp
        Logic/Stopwatch.h
        Logic/World.cpp
        Logic/World.h
        Logic/AbstractFactory.cpp
        Logic/AbstractFactory.h)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(MeatBoy_Said_Yandarbiev
        ${Game_Representation} main.cpp Utility/Camera.cpp Utility/Camera.h)
add_library(Logic_lib STATIC ${Logic})

target_link_libraries(MeatBoy_Said_Yandarbiev
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
        Logic_lib)