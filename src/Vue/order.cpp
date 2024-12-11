#include "Order.h"
#include <QString>

Order::Order(int clientId, const QString &dishName)
    : clientId(clientId), dishName(dishName), status(PENDING)
{
}

int Order::getClientId() const {
    return clientId;
}

QString Order::getDishName() const {
    return dishName;
}

Order::Status Order::getStatus() const {
    return status;
}

void Order::setStatus(Order::Status newStatus) {
    status = newStatus;
}
