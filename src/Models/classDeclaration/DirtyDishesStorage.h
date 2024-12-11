//
// Created by wolverine on 12/2/24.
//

#ifndef DIRTYDISHESSTORAGE_H
#define DIRTYDISHESSTORAGE_H
#include <iosfwd>
using namespace std;
#include <iostream>

/**
 * @class DirtyDishesStorage
 */
class DirtyDishesStorage {
public:
    /**
     * @brief
     *
     * @param dirty_plates_number
     * @param dirty_glasses_number
     * @param dirty_cutlery_number
     */

    DirtyDishesStorage() 
        : dirtyPlatesNumber(0), dirtyGlassesNumber(0), dirtyCutleryNumber(0) {};

    DirtyDishesStorage(int dirty_plates_number, int dirty_glasses_number, int dirty_cutlery_number)
        : dirtyPlatesNumber(dirty_plates_number),
          dirtyGlassesNumber(dirty_glasses_number),
          dirtyCutleryNumber(dirty_cutlery_number) {
    }

    void sendToDishWasher(int platesNumber, int glassesNumber, int cutleryNumber);
    int getdirtyPlatesNumber() const;
    int getdirtyGlassesNumber() const;
    int getdirtyCutleryNumber() const;
    void setdirtyCutleryNumber(int cutleryNumber);
    void setdirtyGlassesNumber(int glassesNumber);
    void setdirtyPlatesNumber(int platesNumber);

        void initialize() {
        operetional = false;
        std::cout << "Machine à laver initialisée." << std::endl;
    }

    bool isOperational() const {
        return operetional;
    }

    void activate() {
        operetional = true;
        std::cout << "Machine à laver activée." << std::endl;
    }

    void deactivate() {
        operetional = false;
        std::cout << "Machine à laver désactivée." << std::endl;
    }

private:
    int dirtyPlatesNumber;
    int dirtyGlassesNumber;
    int dirtyCutleryNumber;
    bool operetional;

};
#endif //DIRTYDISHESSTORAGE_H
