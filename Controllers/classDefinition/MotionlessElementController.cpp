#include "../classDeclaration/MotionlessElementController.h"

//
// Created by wolverine on 12/2/24.
/**
 * 
 * @param dirty_dishes_storage
 * @param washing_machine
 */


void MotionlessElementController::releaseTable(int tableId) {
    
}

void MotionlessElementController::createAllTable(int numberTable, int capacityTable) {
    for (int i=0; i<numberTable; i++){
        //tables.emplace_back(Table(i, 0, capacityTable, 0, {}, 0)); //à revoir pour la disposition
    }   
    std::cout << numberTable << "Tables creates with capacity of " << capacityTable << " each." << std::endl;
}


std::vector<Table*> MotionlessElementController::getAvailableTables(int requiredCapacity) {
    std::vector<Table*> availableTables;
    for(auto& table: tables){
        if(table.getCapacity()>= requiredCapacity && !table.isOccupied()) {
            availableTables.push_back(&table);
        }
    }
    return availableTables;
}


void MotionlessElementController::createKitchenElements() {
    std::cout << "Creation of the equipment" << std::endl;
    washing_machine_.initialize();
    dirty_dishes_storage_.initialize();
}

bool MotionlessElementController::isKitchenEquipmentActive() {
    return washing_machine_.isActive() && dirty_dishes_storage_.isOperational();
}

void MotionlessElementController::activateKitchenEquipment() {
    washing_machine_.activate();
    dirty_dishes_storage_.activate();
    std::cout << "Équipements de cuisine activés." << std::endl;
}

void MotionlessElementController::deactivateKitchenEquipement() {
    washing_machine_.deactivate();
    dirty_dishes_storage_.deactivate();
    std::cout << "Équipements de cuisine désactivés." << std::endl;
}