//
// Created by wolverine on 12/2/24.
//

#ifndef SERVER_H
#define SERVER_H
#include "UstensilModel.h"
#include "Table.h"
#include "Order.h"
#include <vector>
/**
 * @class Server
 *
 * @brief the class that manage the server
 */
class Server : Human{
public:
    /**
     * @brief the constructor of the server class
     *
     * @param abscice the position x of the server
     * @param intercept the position y of the server
     * @param area the actual square of the server
     * @param max_ready_order
     * @param dirty_dishes_collected
     */


    Server(double abscice, double intercept, int area, int max_ready_order,
     const vector<UstensilModel> &dirty_dishes_collected)
     : Human(abscice, intercept),
       area(area),
       maxReadyOrder(max_ready_order),
       dirtyDishesCollected(dirty_dishes_collected) {
    }

    Server(int area, int max_ready_order, const vector<UstensilModel> & vector);

    /**
     * @brief to take the ready order on the counter
     */
    void getReadyOrder();/* je pense aussi cette méthode devrait
                          * prendre des paramétres
                          * ps: on verra */

    /**
     * @brief to take all the dirty dishes on the table
     */
    void clearTable();

    /**
     * @brief the function use to serve the clients
     *
     * @param ustensilList
     * @param table
     * @param order
     */
    void serveClient(vector<UstensilModel> ustensilList, Table &table, Order &order);

     void dropDirtyDishes();

    /**
     * @brief to help another square when he is free and the square is
     * busy
     */
    void help();/* je pense sincérement que cette fonction doit prendre
                 * des paramétres
                 * et retourner un truc */
private:
    int area;
    int maxReadyOrder;
    vector<UstensilModel> dirtyDishesCollected;
    // TODO: add didisto (dirtyDishesStorage)

};
#endif //SERVER_H
