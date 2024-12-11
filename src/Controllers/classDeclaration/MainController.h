//
// Created by wolverine on 12/2/24.
//

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "DBController.h"
#include "MotionlessElementController.h"
#include "SocketController.h"
#include <QObject>
using namespace std;

class MainController: public QObject {
    signals:
    void dataUpdate();
    void errorOccurred(QString errorMessage);

    private:
        DBController dbController;
        MotionlessElementController motionlessController;
        SocketController socketController;

    public:
   MainController();

    void initializeRestaurant();
    void connectToDB();    
    void disconnectToDB(); 
    void makeRequest();
    void handleUserInteraction();
};
#endif //MAINCONTROLLER_H
