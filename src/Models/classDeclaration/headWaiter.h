//
// Created by wolverine on 12/2/24.
//

#ifndef HEADWAITER_H
#define HEADWAITER_H
#include "Order.h"
#include "Table.h"
#include "ClientModel.h"
#include <queue>
/**
 * @class HeadWaiter
 *
 * @brief the guys who lead the client to his table
 */
class HeadWaiter {
    queue<Order> orderQueue;
public:
    /**
     * @brief the function to lead the clients to their table
     *
     * @param table
     * @param clients
     */
    void leadClients(Table &table, vector<ClientModel> &clients);

    /**
     * @brief the function to take order and pass it to the chief
     */
    void passOrdersTochief();
};
#endif //HEADWAITER_H
