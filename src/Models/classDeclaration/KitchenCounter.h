//
// Created by wolverine on 12/2/24.
//

#ifndef KITCHENCOUNTER_H
#define KITCHENCOUNTER_H
#include "Order.h"
using namespace std;

/**
 * @class KitchenCounter
 *
 * @brief the place where we put dishes when they are ready
 */
class KitchenCounter {
public:
    /**
     * @brief constructor of kitchen counter
     *
     * @param ready_order_list
     * @param ready_order_number
     * @param max_ready_order
     */
    KitchenCounter(const vector<Order> &ready_order_list, int ready_order_number, int max_ready_order)
        : ReadyOrderList(ready_order_list),
          ReadyOrderNumber(ready_order_number),
          MaxReadyOrder(max_ready_order) {
    }

    /**
     * @breif increments the number of other ready on the counter
     *
     * @param orders
     */
    void appendReadyOrder(vector<Order> orders);

    /**
     * @brief  remove a ready order (the server should call this method)
     */
    void removeReadyOrder();


private:
    vector<Order>  ReadyOrderList;
    int ReadyOrderNumber;
    int MaxReadyOrder;
};
#endif //KITCHENCOUNTER_H
