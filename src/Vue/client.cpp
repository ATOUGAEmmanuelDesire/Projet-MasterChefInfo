#include "Client.h"
#include <QPropertyAnimation>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QLabel>


Client::Client(QWidget *parent)
    : QLabel(parent), m_id(-1), m_name("Unnamed")
{
    // Configuration par défaut
    this->setScaledContents(true);
}

// Getter et setter pour l'ID
int Client::getId() const {
    return m_id;
}

void Client::setId(int id) {
    m_id = id;
}

// Getter et setter pour le nom
QString Client::getName() const {
    return m_name;
}

void Client::setName(const QString &name) {
    m_name = name;
}

// Déplacer le client
void Client::moveTo(const QRect &geometry) {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(2000); // Durée du déplacement
    animation->setStartValue(this->geometry());
    animation->setEndValue(geometry);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
