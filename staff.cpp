#include "staff.h"
#include <QPropertyAnimation>

Staff::Staff(QWidget *parent)
    : QLabel(parent), busy(false)
{
    setScaledContents(true);
}

void Staff::moveTo(const QRect &destination) {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(2000);
    animation->setStartValue(geometry());
    animation->setEndValue(destination);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    // Émettre le signal après l'animation
    connect(animation, &QPropertyAnimation::finished, this, [this, destination]() {
        if (geometry() == destination) {
            emit returnedToKitchen();
        }
    });
}

bool Staff::isBusy() const {
    return busy;
}

void Staff::setBusy(bool busyStatus) {
    busy = busyStatus;
}
