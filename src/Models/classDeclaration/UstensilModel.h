//
// Created by wolverine on 12/2/24.
//

#ifndef USTENSILMODEL_H
#define USTENSILMODEL_H
#include <iostream>
#include <utility>
using namespace std;

/**
 * @class UstensilModel
 *
 * @brief the mmodel to create the differents ustensil (cutlery and others)
 */
class UstensilModel {
public:
    /**
     *@brief the constructor of the ustensil class
     *
     * @param is_clean
     * @param name
     * @param wash_time
     */
    UstensilModel(bool is_clean, string name, int wash_time)
        : isClean(is_clean),
          name(std::move(name)),
          washTime(wash_time) {
    }
    //to get the wash time i have to pass this comment into a docstring comment
    int getWashTime() const;
    // to change the state of the isCleand attribute
    void toogleIsClean();

private:
    bool isClean;
    string name;
    int washTime;
    // should i add a type ??

};
#endif //USTENSILMODEL_H
