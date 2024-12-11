//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/ClientModel.h"

void ClientModel::makeChoice(vector<Recipe> &recipes) {
    // TODO add instruction for randomly choose the dishes of the client
}

void ClientModel::toogleHasOrdered() {
    this->hasOdered = !this->hasOdered;
}

void ClientModel::toogleHasOrderedMainCourse() {
    this->hasOrderedMainCourse = !this->hasOrderedMainCourse;
}

void ClientModel::toogleHasOrderedDessert() {
    this->hasOrderedDessert = !this->hasOrderedDessert;
}

void ClientModel::toogleHasOrderedEntree() {
    this->hasOrderedEntree = !this->hasOrderedEntree;
}


// void ClientModel::eat(vector<Order> &order) {
//     /* TODO: add a methods eat for the client
//      * Manage the time by the type of dishes
//     */
// }

