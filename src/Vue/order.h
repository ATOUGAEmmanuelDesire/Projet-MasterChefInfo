#ifndef ORDER_H
#define ORDER_H

#include <QString>

class Order
{
public:
    enum Status {
        PENDING,
        READY
    };

    Order(int clientId, const QString &dishName);

    int getClientId() const;
    QString getDishName() const;
    Status getStatus() const;
    void setStatus(Status newStatus);

private:
    int clientId;
    QString dishName;
    Status status;
};

#endif // ORDER_H
