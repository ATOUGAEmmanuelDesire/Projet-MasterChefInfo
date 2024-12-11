//
// Created by wolverine on 12/2/24.
//

#ifndef STORAGEMODEL_H
#define STORAGEMODEL_H
#include <iostream>
using namespace std;

/**
 * @class StorageModel
 *
 * @brief the class use to manage the storage
 */
class StorageModel {
public:
    /**
     * @brief storageModel constructor
     *
     * @param current_content
     * @param durability
     * @param name
     */
    StorageModel(int current_content, int durability, const string &name)
        : currentContent(current_content),
          durability(durability),
          name(name) {
    }

    /**
     * @brief a function to save the product in a storage
     *
     * @param name
     * @param quantity
     */
    void saveProduct(string name, int quantity);

    /**
     * @brief to move a product of the storage
     *
     * @param name
     * @param quantity
     */
    void outProduct(string name, int quantity);

private:
    int currentContent;
    int durability;
    string name;

};
#endif //STORAGEMODEL_H
