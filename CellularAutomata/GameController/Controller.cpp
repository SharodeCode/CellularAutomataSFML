#include "Controller.h"
#include "../CellBoard.h"
#include "../UI.h"

Controller::Controller(CellBoard& cellBoard, UI& ui) : cellBoard(cellBoard), ui(ui) {}

void Controller::update(float deltaTime) {

    // Handle game logic based on input
    if (!pauseSimulation) {
        accumulator += deltaTime;

        if (accumulator >= updateInterval) {
            cellBoard.updateGrid();
            accumulator = 0.0f;
        }
    }
}

void Controller::increaseSimulationSpeed() {
    updateInterval -= 0.2;
}


void Controller::decreaseSimulationSpeed() {
    updateInterval += 0.2;
}

void Controller::toggleSimulationPause() {
    pauseSimulation = !pauseSimulation;
}