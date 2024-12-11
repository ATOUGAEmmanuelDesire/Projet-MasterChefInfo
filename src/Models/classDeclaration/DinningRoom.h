//
// Created by wolverine on 12/2/24.
//

#ifndef DINNINGROOM_H
#define DINNINGROOM_H

#include <vector>
#include <queue>

#include "Table.h"
using namespace std;

/**
 * @class DinningRoom
 *
 * @brief this class manage all the elements in the dinning room
 */
class DinningRoom {
public:
    /**
     * @brief constructor of the dinning room
     *
     * @param table_list
     * @param bread_cart_available
     * @param card_distribueted
     * @param current_client_number
     * @param total_client_of_the_day
     * @param is_first_square_busy
     * @param is_second_square_busy
     * @param firt_square_busy_server_number
     * @param second_square_busy_server_number
     * @param first_square_request
     * @param second_square_request
     */
    DinningRoom(const vector<Table> &table_list, int bread_cart_available, int card_distribueted,
                int current_client_number, int total_client_of_the_day, bool is_first_square_busy, bool is_second_square_busy,
                int firt_square_busy_server_number, int second_square_busy_server_number,
                const queue<Table> &first_square_request, const queue<Table> &second_square_request)
        : tableList(table_list),
          breadCartAvailable(bread_cart_available),
          cardDistribueted(card_distribueted),
          currentClientNumber(current_client_number),
          totalClientOfTheDay(total_client_of_the_day),
          isFirstSquareBusy(is_first_square_busy),
          isSecondSquareBusy(is_second_square_busy),
          firtSquareBusyServerNumber(firt_square_busy_server_number),
          secondSquareBusyServerNumber(second_square_busy_server_number),
          firstSquareRequest(first_square_request),
          secondSquareRequest(second_square_request) {
    }

    /**
     * @brief this function take the list of table which don't have any client
     * on and send it to the Butler
     *
     * @return EmptyTable[]
     */
    vector<Table> getEmptyTableList(vector<Table> table);

    /**
     * @brief getter for the tableList attribute
     * @return tableList
     */
    vector<Table>  getTableList();

private:
    vector<Table> tableList;
    int breadCartAvailable;
    int cardDistribueted;
    int currentClientNumber;
    int totalClientOfTheDay;
    bool isFirstSquareBusy;
    bool isSecondSquareBusy;
    int firtSquareBusyServerNumber;
    int secondSquareBusyServerNumber;
    queue<Table> firstSquareRequest;
    queue<Table> secondSquareRequest;

};

#endif //DINNINGROOM_H
