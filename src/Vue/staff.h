#ifndef STAFF_H
#define STAFF_H

#include <QLabel>

class Staff : public QLabel
{
    Q_OBJECT

public:
    explicit Staff(QWidget *parent = nullptr);
    void moveTo(const QRect &destination);
    bool isBusy() const;
    void setBusy(bool busyStatus);

signals:
    void returnedToKitchen(); // Signal émis lorsque le serveur revient à la cuisine

private:
    bool busy = false;
};

#endif // STAFF_H
