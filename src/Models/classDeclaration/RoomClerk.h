//
// Created by wolverine on 12/2/24.
//

#ifndef ROOMCLERK_H
#define ROOMCLERK_H
#include "Server.h"
using namespace std;

/**
 * @class RoomClerk
 *
 * @brief a subsitute server
 */
class RoomClerk : Server{
public:
    /**
     * @brief the RoomClerk constructor
     *
     * @param area
     * @param max_ready_order
     * @param dirty_dishes_collected
     * @param type
     */
    RoomClerk(int area, int max_ready_order, const vector<UstensilModel> &dirty_dishes_collected, const string &type)
        : Server(area, max_ready_order, dirty_dishes_collected),
          type(type) {
    }

    /**
     * @brief the function to serve apero(bread and drink)
     * TODO: Retoucher cette méthode(enlever todo une fois fait)
     */
    void serveApero();

private:
    string type;

};
#endif //ROOMCLERK_H
