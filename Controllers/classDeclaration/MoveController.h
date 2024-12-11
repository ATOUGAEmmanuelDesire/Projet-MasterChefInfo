//
// Created by the_pek on 12/2/24.
//

#ifndef MOVECONTROLLER_H
#define MOVECONTROLLER_H
#include "../../Models/classDeclaration/headWaiter.h"
#include "../../Models/classDeclaration/RestaurantDiver.h"
#include "../../Models/classDeclaration/Server.h"
#include "../../Models/classDeclaration/Chief.h"
#include "../../Models/classDeclaration/KitchenAssistant.h"
#include "../../Models/classDeclaration/KitchenCounter.h"
#include "../../Models/classDeclaration/RoomClerk.h"
#include "../../Models/classDeclaration/ClientModel.h"
using namespace std;
class MoveController {
public:
    void moveServe(Server server);
    void moveHeadWaiter(HeadWaiter headWaiter);
    void moveRestaurantDiver(RestaurantDiver restaurantDiver);
    void moveChief(Chief chief);
    void moveKitchenAssistant(KitchenAssistant kitchenAssistant);
    void moveKitchenCounter(KitchenCounter kitchenCounter);
    void moveRoomClerk(RoomClerk roomClerk);
    void moveClientModel(ClientModel clientModel);
};
#endif //MOVECONTROLLER_H
