//
// Created by wolverine on 12/2/24.
//

#ifndef MOTIONLESSELEMENTCONTROLLER_H
#define MOTIONLESSELEMENTCONTROLLER_H
#include <vector>
#include "../../Models/classDeclaration/Table.h"
#include "../../Models/classDeclaration/DirtyDishesStorage.h"
#include "../../Models/classDeclaration/WashingMachine.h"
using namespace std;

/**
 * @class MotionlessElementController
 */
class MotionlessElementController {

private:
    std::vector<Table> tables;
    DirtyDishesStorage dirty_dishes_storage_;
    WashingMachine washing_machine_;

public:
    /**
     * @brief
     *
     * @param dirty_dishes_storage
     * @param washing_machine
     */
    MotionlessElementController(const DirtyDishesStorage &dirty_dishes_storage, const WashingMachine &washing_machine)
        : dirty_dishes_storage_(dirty_dishes_storage),
          washing_machine_(washing_machine) {
    }

    //Gestion des éléments de cuisine
    void createAllTable(int numberTable, int capacityTable);
    std::vector<Table*> getAvailableTables(int requiredCapacity);
    void releaseTable(int tableId);

    //Gestion des équipements de cuisine
    
    //void initializeElement();
    void createKitchenElements();
    bool isKitchenEquipmentActive();
    void activateKitchenEquipment();
    void deactivateKitchenEquipement();


};
#endif //MOTIONLESSELEMENTCONTROLLER_H
