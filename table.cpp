#include "Table.h"
#include <QLabel>

Table::Table(QWidget *parent)
    : QLabel(parent), m_id(-1), m_occupied(false), m_description("Default")
{
    // Configuration par défaut
    this->setScaledContents(true);
}

// Getter et setter pour l'ID
int Table::getId() const {
    return m_id;
}

void Table::setId(int id) {
    m_id = id;
}

// Getter et setter pour le statut
bool Table::isOccupied() const {
    return m_occupied;
}

void Table::setOccupied(bool occupied) {
    m_occupied = occupied;
}

// Getter et setter pour la description
QString Table::getDescription() const {
    return m_description;
}

void Table::setDescription(const QString &description) {
    m_description = description;
}
