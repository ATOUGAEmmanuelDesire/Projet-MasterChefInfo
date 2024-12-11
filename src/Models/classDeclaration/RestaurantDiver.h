//
// Created by wolverine on 12/2/24.
//

#ifndef RESTAURANTDIVER_H
#define RESTAURANTDIVER_H
#include "DirtyDishesStorage.h"
#include "DishwasherModel.h"
#include "WashingMachine.h"
using namespace std;

/**
 * @class RestaurantDiver
 */
class RestaurantDiver {
public:
    /**
     * @brief
     *
     * @param dirty_dishes_storage
     * @param washing_machine
     * @param dishwasher_model
     */
    RestaurantDiver(const DirtyDishesStorage &dirty_dishes_storage, const WashingMachine &washing_machine,
                    const DishwasherModel &dishwasher_model)
        : dirty_dishes_storage_(dirty_dishes_storage),
          washing_machine_(washing_machine),
          dishwasher_model_(dishwasher_model) {
    }

    void getDirtyDishes();
    void washDishes();
    void getWashedDishes();

private:
    DirtyDishesStorage dirty_dishes_storage_;
    WashingMachine washing_machine_;
    DishwasherModel dishwasher_model_;

};
#endif //RESTAURANTDIVER_H
