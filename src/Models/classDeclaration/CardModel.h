//
// Created by wolverine on 12/2/24.
//

#ifndef CARDMODEL_H
#define CARDMODEL_H
#include "Recipe.h"
#include <vector>
using namespace std;
/**
 * @class CardModel
 *
 * @brief this class manage all the card
 */
class CardModel {
public:
    /**
     * @brief constructor of the class cardModel
     *
     * @param currentCard
     */
    explicit CardModel(const vector<Recipe> &currentCard)
        : currentCard(currentCard) {}
    virtual ~CardModel() = default; /* TODO: faire la méthode pour
                                     * réincrémenter le compteur
                                     * des cartes actueles */
    /**
     * @brief for the recovery of the current card
     *
     * @return currentCard
     */
    vector<Recipe> getCurrentCard();

private:
    vector<Recipe> currentCard;

};
#endif //CARDMODEL_H
