#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "../CellBoard.h"
#include "../UI.h"

class Controller
{
public:
    Controller(CellBoard& cellBoard, UI& ui);
    void update(float deltaTime);

    void increaseSimulationSpeed();
    void decreaseSimulationSpeed();

    void toggleSimulationPause();

private:
    CellBoard& cellBoard;
    float accumulator = 0.0f;
    bool pauseSimulation = false;
    float updateInterval = 0.5f;
    UI ui;
};

#endif