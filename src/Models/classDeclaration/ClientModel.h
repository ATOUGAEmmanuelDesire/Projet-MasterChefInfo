//
// Created by wolverine on 12/2/24.
//

#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H
#include <iostream>
#include <vector>
#include "Recipe.h"
#include "Order.h"
#include "Human.h"
using namespace std;

/**
 * @class ClientModel
 * @brief management of the different instance of the client
 *
 * the clientModel class is used to create the different instance of the client,
 * they are the one with the different methods of the client
 */
class ClientModel : Human{
public:
    /**
     *@brief constructor of the Client class
     *
     * @param abscice
     * @param intercept
     * @param type
     * @param id
     * @param has_odered
     * @param order_time_left
     * @param has_ordered_entree
     * @param has_ordered_main_course
     * @param has_ordered_dessert
     */
    ClientModel(double abscice, double intercept, const string &type, int id, bool has_odered,
                int order_time_left, bool has_ordered_entree, bool has_ordered_main_course, bool has_ordered_dessert)
        : Human(abscice, intercept),
          type(type),
          id(id),
          hasOdered(has_odered),
          orderTimeLeft(order_time_left),
          hasOrderedEntree(has_ordered_entree),
          hasOrderedMainCourse(has_ordered_main_course),
          hasOrderedDessert(has_ordered_dessert) {
    }
    /**
     * @brief this function is use for the client to make a choice
     *
     * @param recipes
     */

    void makeChoice(vector<Recipe> &recipes);

    /**
     * @brief change the hasOrdered state
     */
    void toogleHasOrdered();

    /**
     * C
     */
    void toogleHasOrderedMainCourse();
    void toogleHasOrderedDessert();
    void toogleHasOrderedEntree();

    /**
     * @brief client method eat
     * @param order
     */
    // void eat(vector<Order> &order);

private:
    string type;
    int id;
    bool hasOdered;
    int orderTimeLeft; /** < the time left to the user to order. */
    bool hasOrderedEntree;
    bool hasOrderedMainCourse;
    bool hasOrderedDessert;
    vector<Recipe> choices;
};



#endif //CLIENTMODEL_H
