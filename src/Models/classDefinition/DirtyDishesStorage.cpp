//
// Created by wolverine on 12/2/24.
//

#include "../classDeclaration/DirtyDishesStorage.h"
int DirtyDishesStorage::getdirtyCutleryNumber() const {
    return dirtyCutleryNumber;
}

int DirtyDishesStorage::getdirtyGlassesNumber() const {
    return dirtyGlassesNumber;
}

int DirtyDishesStorage::getdirtyPlatesNumber() const {
    return dirtyPlatesNumber;
}

void DirtyDishesStorage::setdirtyCutleryNumber(int cutleryNumber) {
    this->dirtyCutleryNumber = cutleryNumber;
}

void DirtyDishesStorage::setdirtyGlassesNumber(int glassesNumber) {
    this->dirtyGlassesNumber = glassesNumber;
}

void DirtyDishesStorage::setdirtyPlatesNumber(int platesNumber) {
    this->dirtyPlatesNumber = platesNumber;
}

void DirtyDishesStorage::sendToDishWasher(int platesNumber, int glassesNumber, int cutleryNumber) {
    // TODO: add few instructions to manage it
}