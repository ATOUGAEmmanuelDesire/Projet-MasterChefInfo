//
// Created by wolverine on 12/2/24.
//

#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include <iostream>
using namespace std;

/**
 * @class WashingMachine
 */
class WashingMachine {
public:
    /**
     * @brief
     *
     * @param towels_number
     * @param wash_towels
     */
    WashingMachine() 
        : towelsNumber(0), washTowels(0), active(false) {}

    WashingMachine(int towels_number, int wash_towels)
        : towelsNumber(towels_number),
          washTowels(wash_towels) {
    }

    int getTowelsNumber();
    void setTowelsNumber(int towels_number);

    void initialize() {
        active = false;
        std::cout << "Machine à laver initialisée." << std::endl;
    }

    // Vérifie si la machine est active
    bool isActive() const {
        return active;
    }

    // Active la machine
    void activate() {
        active = true;
        std::cout << "Machine à laver activée." << std::endl;
    }

    // Désactive la machine
    void deactivate() {
        active = false;
        std::cout << "Machine à laver désactivée." << std::endl;
    }

private:
    int towelsNumber;
    int washTowels;
    bool active;

};
#endif //WASHINGMACHINE_H
