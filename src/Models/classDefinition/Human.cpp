
#include "../classDeclaration/Human.h"
#include <QGraphicsEllipseItem>
#include <QApplication>


auto Human::move(QGraphicsEllipseItem *item, QPointF destination) -> void {
    // TODO ajouter un algo de pathfiding pour la fonction move
    auto currentPosition= item->pos();
    if(currentPosition.x() != destination.x()){
        float directionX= (destination.x() - currentPosition.x() > 0) ? 1.0: -1.0;
        item->moveBy(directionX, 0);
    } else if(currentPosition.y() != destination.y()) {
        float directionY= (destination.y() - currentPosition.y() > 0) ? 1.0 : 1.0;
        item->moveBy(0, directionY);
    }
}