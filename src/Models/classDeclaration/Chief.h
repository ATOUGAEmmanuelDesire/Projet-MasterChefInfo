//
// Created by wolverine on 12/2/24.
//

#ifndef CHUEF_H
#define CHUEF_H
#include "CardModel.h"
#include "Order.h"
using namespace std;

/**
 * @class Chief
 *
 * @brief the actuel class to manage the chief
 */
class Chief {
public:
    /**
     * @brief the constructor of the class Chief
     *
     * @param actual_card
     * @param order_list
     * @param organised_order_list
     * @param invalid_order_list
     */
    Chief(const CardModel &actual_card, const vector<Order> &order_list, const vector<Order> &organised_order_list,
          const vector<Order> &invalid_order_list)
        : actualCard(actual_card),
          orderList(order_list),
          organisedOrderList(organised_order_list),
          invalidOrderList(invalid_order_list) {
    }

    /**
     * @brief the function to change the actual card
     *
     * @param card the actual card use by clients
     */
    void setCurrentCard(CardModel card); // maybe this should have a return statement

    /**
     *
     * @return organiseListOrders
     */
    Order organiseOrders();

    /**
     *
     * @return orderList (maybe)
     */
    Order checkOrderlist();

    /**
     * @brief to distribute task to others
     */
    void DistributeTask();

private:
    CardModel actualCard;
    vector<Order> orderList;
    vector<Order> organisedOrderList;
    vector<Order> invalidOrderList;

};
#endif //CHUEF_H
