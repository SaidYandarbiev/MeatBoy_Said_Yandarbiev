//
// Created by said2 on 10-11-2022.
//

#ifndef MEATBOY_SAID_YANDARBIEV_GOALMODEL_H
#define MEATBOY_SAID_YANDARBIEV_GOALMODEL_H

#include "EntityModel.h"
class GoalView;
class GoalModel: public EntityModel{
public:

    /**
    * Constructor
    * //////////////////////////////////////
    *The constructor creates a GoalModel object
     * Parameters:
     *            f: startposition of the created object
    */
     GoalModel(Utility::Vector2f f) {
        pos = f;
        OriginalPos = f;
    }

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Parameter:
     *          camera: The camera of the game
     */
    void Update(std::shared_ptr<Utility::Camera> camera) override;

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Parameter:
     *          lvlnumber: Current level number
     */
    void Update(int lvlnumber)override{}

    /**
     * Update
     * ////////////////////////////////////
     * This function is called every tick to Update the variables of the current object
     * Relevant Parameters:
     *          states: Current state of the game
     *          camera: The camera of the game
     */
    void Update(std::shared_ptr<Utility::States>, Utility::Vector2u, float y, std::shared_ptr<Utility::Camera> camera) override{};

};


#endif //MEATBOY_SAID_YANDARBIEV_GOALMODEL_H
