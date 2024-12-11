#include "kitchencontroller.h"
#include <QDebug>

KitchenController::KitchenController(QObject *parent)
    : QObject(parent)
{
}

// Ajouter une commande
void KitchenController::addOrder(int clientId, const QString &dishName) {
    Order *order = new Order(clientId, dishName);
    orders.append(order);
    qDebug() << "Nouvelle commande ajoutée pour le client" << clientId << ":" << dishName;
}

// Traiter la prochaine commande
void KitchenController::processNextOrder() {
    if (orders.isEmpty()) {
        qDebug() << "Aucune commande à traiter.";
        return;
    }

    // Traiter la première commande
    Order *order = orders.takeFirst();
    order->setStatus(Order::READY);
    qDebug() << "Commande prête pour le client" << order->getClientId() << ":" << order->getDishName();

    delete order; // Libérer la mémoire
}

// Obtenir la liste des commandes en attente
QList<Order*> KitchenController::getPendingOrders() const {
    return orders;
}
