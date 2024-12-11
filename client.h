#ifndef CLIENT_H
#define CLIENT_H

#include <QLabel>
#include <QPixmap>
#include <QRect>
#include <QPropertyAnimation>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QDebug>

class Client : public QLabel
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);

    // Attributs spécifiques
    int getId() const;
    void setId(int id);

    QString getName() const;
    void setName(const QString &name);

    void moveTo(const QRect &geometry); // Déplacer le client

private:
    int m_id;        // Identifiant unique du client
    QString m_name;  // Nom du client
};

#endif // CLIENT_H
