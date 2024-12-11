//
// Created by wolverine on 12/2/24.
//

#ifndef RECIPE_H
#define RECIPE_H
#include <iostream>
#include <utility>
#include <vector>
#include "UstensilModel.h"
using namespace std;

/**
 * @class Recipe
 *
 * @brief this class has the differents dishes of the card
 */
class Recipe {
public:
    /**
     *@brief the constructor of the class Recipe
     *
     * @param name
     * @param type
     * @param cooking_time
     * @param is_makable
     * @param ingredients_list
     * @param cooking_ustensils_list
     * @param eating_ustensil
     */

    Recipe(const string &name, const string &type, int cooking_time, bool is_makable,
        const vector<string> &ingredients_list, const vector<UstensilModel> &cooking_ustensils_list,
        const vector<UstensilModel> &eating_ustensil)
        : name(name),
          type(type),
          cookingTime(cooking_time),
          isMakable(is_makable),
          ingredientsList(ingredients_list),
          cookingUstensilsList(cooking_ustensils_list),
          eatingUstensil(eating_ustensil) {
    }

    /**
     * @brief to change the feasibility of a dishes if it isn't feasible anymore
     */
    void toogleIsMakable();
private:
    string name;
    string type;
    int cookingTime;
    bool isMakable;
    vector<string> ingredientsList;
    vector<UstensilModel> cookingUstensilsList;
    vector<UstensilModel> eatingUstensil;
};
#endif //RECIPE_H
