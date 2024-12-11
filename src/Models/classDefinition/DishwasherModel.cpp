#include "../classDeclaration/DishwasherModel.h"
//
// Created by wolverine on 12/2/24.
//
void DishwasherModel::releaseDishes() {
    // TODO: add few instructions to manage it
}

int DishwasherModel::getCutleryNumber() {
    return cutleryNumber;
}
void DishwasherModel::setCutleryNumber(int cutleryNumber) {
    this->cutleryNumber = cutleryNumber;
}
int DishwasherModel::getGlassesNumber() {
    return glassesNumber;
}
void DishwasherModel::setGlassesNumber(int glasses_number) {
    this->glassesNumber = glasses_number;
}
int DishwasherModel::getPlatesNumber() {
    return platesNumber;
}

void DishwasherModel::setPlatesNumber(int plates_number) {
    this->platesNumber = plates_number;
}