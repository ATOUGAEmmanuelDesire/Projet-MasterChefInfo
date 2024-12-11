//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/DinningRoom.h"

vector<Table> DinningRoom::getEmptyTableList(vector<Table> table) {
    table = tableList;
    /* TODO: ajouter une façon de parcourir la liste
     * de table afin de trouve toutes celles vides
     */
    return table;
}

vector<Table> DinningRoom::getTableList() {
    return tableList;
}
