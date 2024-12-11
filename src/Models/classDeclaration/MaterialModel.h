//
// Created by wolverine on 12/2/24.
//

#ifndef MATERIALMODEL_H
#define MATERIALMODEL_H
#include <iostream>
#include <utility>
using namespace std;

/**
 * @class MaterialModel
 */
class MaterialModel {
public:
    /**
     * @brief
     *
     * @param is_active
     * @param name
     * @param timeleft
     */
    MaterialModel(bool is_active, string name, int timeleft)
        : isActive(is_active),
          name(std::move(name)),
          timeleft(timeleft) {
    }

    bool get_isActive() const;
    void toogle_isActive();

private:
    bool isActive;
    string name;
    int timeleft;
};
#endif //MATERIALMODEL_H
