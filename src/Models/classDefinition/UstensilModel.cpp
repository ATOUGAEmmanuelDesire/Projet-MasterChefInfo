#include "../classDeclaration/UstensilModel.h"
//
// Created by wolverine on 12/2/24.
//
int UstensilModel::getWashTime() const {
    return washTime;
}



void UstensilModel::toogleIsClean() {
    this-> isClean = !isClean;
}

