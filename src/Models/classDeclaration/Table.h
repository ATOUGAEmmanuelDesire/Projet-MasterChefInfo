//
// Created by wolverine on 12/2/24.
//

#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>

#include "ClientModel.h"

/**
 * @class Table
 *
 * @brief the class table for the management of all the table of
 * the dinning room
 */
class Table {
private:
    double abscice;
    double intercept;
    int capacity;
    int occupied;
    vector<ClientModel> clientList;
    int breadCartNeeded;
    int id;

public:
    /**
     * @brief Constructor of the class Table
     *
     * @param abscice
     * @param intercept
     * @param capacity
     * @param occuped
     * @param client_list
     * @param bread_cart_needed
     */
    Table(double abscice, double intercept, int capacity, int occupied, const vector<ClientModel> &client_list,
          int bread_cart_needed, int id)
        : abscice(abscice),
          intercept(intercept),
          capacity(capacity),
          occupied(occupied),
          clientList(client_list),
          breadCartNeeded(bread_cart_needed),
          id(id){
    }

    /**
     * @brief a function to add clients on the table
     *
     * @param clients
     */
    void addClientsToTable(vector<ClientModel> clients);

    /**
     * @brief to move the client when they have finished eating
     */
    void releaseClients();

    void setAbscice(double abscice);
    void setIntercept(double intercept);
    void setOccupied(int occupied);
    void setClientList(vector<ClientModel> clientList);

    int getCapacity() const {
        return capacity;
    };

    bool isOccupied() const {
        return occupied > 0; // Une table est considérée occupée si occupied_ est supérieur à 0.
    }

    int getId() const {
        return id;
    }
};
#endif //TABLE_H
