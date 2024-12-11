//
// Created by wolverine on 12/2/24.
//

#ifndef COOK_H
#define COOK_H
#include <queue>
#include "Order.h"
using namespace std;

/**
 * @class Cook
 *
 * @brief this class is for the person in charge of cooking the dishes
 */
class Cook {
    queue<Order> rcipe_queue_;
public:
    void cookRecipe(vector<Order> orders);
};
#endif //COOK_H
