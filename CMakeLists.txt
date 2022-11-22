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
        Src/Game_Representation/EntityView.cpp
        Src/Game_Representation/EntityView.h
        Src/Game_Representation/PlayerView.cpp
        Src/Game_Representation/PlayerView.h
        Src/Game_Representation/WallView.cpp
        Src/Game_Representation/WallView.h
        Src/Game_Representation/GoalView.cpp
        Src/Game_Representation/GoalView.h
        Src/Game_Representation/StateManager.cpp
        Src/Game_Representation/StateManager.h
        Src/Game_Representation/State.cpp
        Src/Game_Representation/State.h
        Src/Game_Representation/MenuState.cpp
        Src/Game_Representation/MenuState.h
        Src/Game_Representation/LevelState.cpp
        Src/Game_Representation/LevelState.h
        Src/Game_Representation/ConcreteFactory.cpp
        Src/Game_Representation/ConcreteFactory.h
        Src/Game_Representation/Game.cpp
        Src/Game_Representation/Game.h)

FILE(GLOB Logic
        Src/Logic/Observer.cpp
        Src/Logic/Observer.h
        Src/Logic/Score.cpp
        Src/Logic/Score.h
        Src/Logic/Subject.cpp
        Src/Logic/Subject.h
        Src/Logic/EntityModel.cpp
        Src/Logic/EntityModel.h
        Src/Logic/PlayerModel.cpp
        Src/Logic/PlayerModel.h
        Src/Logic/WallModel.cpp
        Src/Logic/WallModel.h
        Src/Logic/GoalModel.cpp
        Src/Logic/GoalModel.h
        Src/Logic/Stopwatch.cpp
        Src/Logic/Stopwatch.h
        Src/Logic/World.cpp
        Src/Logic/World.h
        Src/Logic/AbstractFactory.cpp
        Src/Logic/AbstractFactory.h)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(MeatBoy_Said_Yandarbiev
        ${Game_Representation} main.cpp Src/Utility/Camera.cpp Src/Utility/Camera.h Src/Utility/Window.cpp Src/Utility/Window.h Src/Utility/Vector.cpp Src/Utility/Vector.h Src/Game_Representation/MenuView.cpp Src/Game_Representation/MenuView.h Src/Utility/States.cpp Src/Utility/States.h Src/Utility/tinyxml2.cpp Src/Utility/tinyxml2.h Src/Utility/Direction.cpp Src/Utility/Direction.h)
add_library(Logic_lib STATIC ${Logic} Src/Logic/MenuModel.cpp Src/Logic/MenuModel.h)

target_link_libraries(MeatBoy_Said_Yandarbiev
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
        Logic_lib)