//
// Created by wolverine on 12/2/24.
//

#ifndef ORDER_H
#define ORDER_H
#include <utility>
#include <vector>
#include "Recipe.h"
//#include "ClientModel.h"
using namespace std;

/**
 *@class Order
 *@brief the Order class is use to save the differents order of the clients
 */
class Order {
public:
    /**
     *@brief Order class constructor
     *
     * @param order_recipes
     * @param id
     * @param client
     */
    Order(const vector<Recipe> &order_recipes, int id)
        : orderRecipes(order_recipes),
          id(id)
           {
    }

    /**
     * @brief this method create cutlery for the current order
     *
     */
    void CreateCutlery();

private:
    // declare a table attribute type : table
    vector<Recipe> orderRecipes;
    int id;


};
#endif //ORDER_H
