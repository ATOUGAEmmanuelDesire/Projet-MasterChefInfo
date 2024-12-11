//
// Created by wolverine on 12/2/24.
//

#ifndef HUMAN_H
#define HUMAN_H
#include <QApplication>
#include "D:/Qt/6.8.1/mingw_64/include/QtWidgets/QGraphicsEllipseItem"



/**
 * @class Human
 *
 * @brief this class regroup all humans of the structure
 */
class Human {
public:
    /**
     *@brief constructor of the Human class
     *
     * @param abscice
     * @param intercept
     */
    Human(double abscice, double intercept)
        : abscice(abscice),
          intercept(intercept) {
    }
    /**
     * @brief this function mave move the differents human with a pathfinding algorithm
     */
    auto move() -> void {
        abscice= abscice+intercept;
        intercept = intercept;
    };

    static void move(QGraphicsEllipseItem *item, QPointF destination);

private:
    double abscice;/** <L'abscice de chaque humain à un instant T */
    double intercept;/** <L'ordonnée de chaque humain à un instant T */

};
#endif //HUMAN_H