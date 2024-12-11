#ifndef TABLE_H
#define TABLE_H

#include <QLabel>
#include <QString>

class Table : public QLabel
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);

    // Attributs spécifiques
    int getId() const;
    void setId(int id);

    bool isOccupied() const;
    void setOccupied(bool occupied);

    QString getDescription() const;
    void setDescription(const QString &description);

private:
    int m_id;              // Identifiant unique de la table
    bool m_occupied;       // Statut de la table (occupée ou non)
    QString m_description; // Description ou nom de la table
};

#endif // TABLE_H
