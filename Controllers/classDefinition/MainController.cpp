#include <iostream>
#include "../classDeclaration/MainController.h"

MainController::MainController()
    : dbController("restaurantmanagement", "root", "", "localhost"),
    motionlessController(DirtyDishesStorage(), WashingMachine()),
    socketController(8080) {}

void MainController::initializeRestaurant() {
    /*


    motionlessController.initializeElements(plates, glasses, cutlery, towels, washTowels);
    */
    motionlessController.createAllTable(10, 4);
    motionlessController.createKitchenElements();
    emit dataUpdate();
    std::cout << "Restaurant initialized successfully." << std::endl;
}

void MainController::connectToDB() {
    if (dbController.DBconnect()) {
        emit dataUpdate();
        std::cout << "Connected to the database." << std::endl;
    } else {
        emit errorOccurred("Error connecting to the database.");
        //std::cerr << "Failed to connect to the database." << std::endl;
    }
}

void MainController::disconnectToDB() {
    dbController.DBdisconnect();
    std::cout << "Disconnected from the database." << std::endl;
}

void MainController::makeRequest() {
    socketController.IncomingRequests();
    emit dataUpdate();
    std::cout << "Handled incoming requests." << std::endl;
}