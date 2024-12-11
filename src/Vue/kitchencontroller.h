#ifndef KITCHENCONTROLLER_H
#define KITCHENCONTROLLER_H

#include <QObject>
#include <QList>
#include "Order.h"

class KitchenController : public QObject
{
    Q_OBJECT

public:
    explicit KitchenController(QObject *parent = nullptr);

    void addOrder(int clientId, const QString &dishName);
    void processNextOrder();
    QList<Order*> getPendingOrders() const;

private:
    QList<Order*> orders; // Liste des commandes
};

#endif // KITCHENCONTROLLER_H
