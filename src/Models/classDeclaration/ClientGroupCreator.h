//
// Created by wolverine on 12/2/24.
//

#ifndef CLIENTGROUPCREATOR_H
#define CLIENTGROUPCREATOR_H
#include <vector>
#include "ClientModel.h"

using namespace std;

/**
 * @class ClientGroupCreator
 *
 * @brief the generations of clients group
 */
class ClientGroupCreator {
public:
    /**
     * @brief the clientGroup class constructor
     *
     * @param client_groups
     * @param client_number
     */
    ClientGroupCreator(const vector<ClientModel> &client_groups, int client_number)
        : clientGroups(client_groups),
          clientNumber(client_number) {
    }

    /**
     * @brief the function that lay group of clients
     */
    void createGroup();

private:
    vector<ClientModel> clientGroups;
    int clientNumber;
};
#endif //CLIENTGROUPCREATOR_H
