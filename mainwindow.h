#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMap>
#include <QSet>
#include "Client.h"
#include "Table.h"
#include "kitchencontroller.h"
#include "staff.h"
#include <QPushButton>
#include "TaskThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayOrderMessage(Staff *server, const QString &message);

private:
    Ui::MainWindow *ui;
    bool isPaused;
    TaskThread *backgroundTask; // Ajout du thread



    // Listes pour stocker les tables et les clients
    QList<Client*> clientList;
    QList<Table*> tableList;
    QMap<Client*, Table*> clientCurrentTable; // Associe chaque client à sa table actuelle
    QSet<Table*> occupiedTables;             // Ensemble des tables occupées

    Staff *chef;    // Objet représentant le chef
    Staff *server;  // Objet représentant le serveur


    // Méthodes pour configurer et gérer les tables et les clients
    void setupUI();                               // Initialise l'interface utilisateur
    void createTablesAndClients();               // Crée et configure les tables (4x4) et les clients
    void startBehavior();                        // Lance le comportement répétitif
    void moveClientsBetweenTables();             // Déplace les clients vers différentes tables
    Table* getNextTable(Client *client);         // Retourne une table non occupée
    void setupKitchen();
    void setupStaff();              // Méthode pour initialiser le personnel
    void moveServerToClient(Client *client); // Déplacer le serveur vers un client
    void moveClientToTable(Client *client, Table *table);
    void moveChefInKitchen();
    void resizeServer();
    void moveChefToNextTask();
    void moveChefBetweenComptoirAndFrigo();
    void setupChefMovement();
    void addStaticCharacters();
    void moveServersToOccupiedTables(); // Déplace les serveurs vers les tables occupée
    void showTemporaryMessage(Client *client, const QString &message);


private slots:
    void togglePause();
    void startBackgroundTask(); // Démarrer le thread
    void handleProgressUpdate(int value); // Mettre à jour l'interface utilisateur
};

#endif // MAINWINDOW_H
