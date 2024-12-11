//
// Created by wolverine on 12/2/24.
//

#ifndef BUTLE_H
#define BUTLE_H
#include <vector>
#include "Table.h"
#include "ClientModel.h"
using namespace std;

/**
 * @class Butler
 *
 * the class of the butler (he is supposed to welcome the client at thier
 * entry)
 */
class Butler {
public:
    /**
     * @brief Constructor of the class Butler
     *
     * @param client_n_umber
     * @param priority_table
     */
    Butler(const int client_n_umber, const vector<int> &priority_table)
        : clientNUmber(client_n_umber),
          priorityTable(priority_table) {
    }

    /**
     * @ brief to assign a table to a client
     */
    void assignTable();

    /**
     * @brief to notify a headwaiter tha he has to take a client
     * to his table
     *
     * @param table
     * @param client
     */
    void notifyHeadWaiter(Table table, ClientModel client);

private:
    int clientNUmber;
    vector<int> priorityTable;
};
#endif //BUTLE_H
