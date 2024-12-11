#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.h"
#include "Table.h"
#include "staff.h"
#include "kitchencontroller.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QTimer>
#include <QRandomGenerator>

// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation de l'interface
    setupUI();

    // Création des tables et des clients
    createTablesAndClients();

    // Lancer le comportement répétitif
    startBehavior();
    setupKitchen();
    setupStaff();
    setupChefMovement();
}

// Destructeur
MainWindow::~MainWindow()
{
    delete ui;

    // Nettoyage des objets créés dynamiquement
    qDeleteAll(clientList);
    qDeleteAll(tableList);
}

// Initialise l'interface utilisateur
void MainWindow::setupUI() {
    this->setWindowState(Qt::WindowMaximized);
    this->setStyleSheet("QMainWindow{background:rgb(126,164,146);}");
}

// Crée et configure les tables (3x3) et les clients
void MainWindow::createTablesAndClients() {
    // Charger les images
    QPixmap tablePixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/table.png");
    QPixmap clientPixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/client.png");

    if (tablePixmap.isNull() || clientPixmap.isNull()) {
        qDebug() << "Erreur : Impossible de charger les images.";
        return;
    }

    // Dimensions pour positionner les tables
    int rows = 3; // Nombre de lignes
    int cols = 3; // Nombre de colonnes
    int tableSize = 170; // Taille des tables
    int spacing = 50;    // Espace entre les tables
    int startX = 100;    // Position de départ en X
    int startY = 100;    // Position de départ en Y

    // Création des tables (3x3 grille)
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Table *table = new Table(this);
            table->setId(row * cols + col + 1); // ID unique
            table->setDescription(QString("Table %1").arg(row * cols + col + 1));
            table->setPixmap(tablePixmap);
            table->setGeometry(startX + col * (tableSize + spacing), startY + row * (tableSize + spacing), tableSize, tableSize);
            table->show();
            tableList.append(table);
        }
    }

    // Création des clients (2 clients)
    for (int i = 0; i < 2; ++i) {
        Client *client = new Client(this);
        client->setId(i + 1);
        client->setName(QString("Client %1").arg(i + 1));
        client->setPixmap(clientPixmap);
        client->setGeometry(50, 400 + i * 100, 50, 50); // Position dynamique
        client->show();
        clientList.append(client);
        clientCurrentTable[client] = nullptr; // Initialisation
    }
}

// Lancer le comportement répétitif
void MainWindow::startBehavior() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveClientsBetweenTables);
    timer->start(5000); // Répète toutes les 5 secondes

    // Premier cycle
    moveClientsBetweenTables();
}

// Déplace les clients vers différentes tables aléatoirement sans collision
void MainWindow::moveClientsBetweenTables() {
    // Réinitialiser les tables occupées
    occupiedTables.clear();

    for (Client *client : clientList) {
        if (!client)
            continue;

        Table *nextTable = getNextTable(client);

        if (nextTable) {
            moveClientToTable(client, nextTable); // Déplace le client et appelle le serveur
            occupiedTables.insert(nextTable); // Marquer la table comme occupée
            qDebug() << client->getName() << "se déplace vers" << nextTable->getDescription();
        }
    }
}

void MainWindow::moveClientToTable(Client *client, Table *table) {
    // Déplacement du client vers la table
    client->moveTo(table->geometry());
    clientCurrentTable[client] = table; // Met à jour la table actuelle du client

    // Appeler le serveur une fois que le client est à sa table
    QTimer::singleShot(2000, this, [this, client]() {
        moveServerToClient(client);
    });
}



// Choisit une table non occupée
Table* MainWindow::getNextTable(Client *client) {
    QList<Table*> availableTables = tableList;

    // Retirer les tables occupées de la liste
    for (Table *occupied : occupiedTables) {
        availableTables.removeAll(occupied);
    }

    // Retirer la table actuelle du client
    Table *currentTable = clientCurrentTable[client];
    if (currentTable) {
        availableTables.removeAll(currentTable);
    }

    // Choisir une table au hasard parmi celles disponibles
    if (!availableTables.isEmpty()) {
        int randomIndex = QRandomGenerator::global()->bounded(availableTables.size());
        return availableTables[randomIndex];
    }

    return nullptr;
}
void MainWindow::setupKitchen() {
    // Chargement des images pour les équipements
    QPixmap ovenPixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/lav.png");
    QPixmap fridgePixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/cuisine2.png");
    QPixmap prepTablePixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/cuisine.png");
    QPixmap frigomPixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/frigo.png");
    QPixmap comptoirPixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/compt.png");

    // Vérifiez si les images sont chargées correctement
    if (ovenPixmap.isNull() || fridgePixmap.isNull() || prepTablePixmap.isNull()) {
        qDebug() << "Erreur : Impossible de charger certaines images des équipements de la cuisine.";
        return;
    }
    // Affichez les dimensions de kitchenFame

    // Associer les images aux QLabel définis dans Qt Designer
    ui->Four->setPixmap(ovenPixmap);
    ui->Four2->setPixmap(fridgePixmap);
    ui->Plan_de_travail->setPixmap(prepTablePixmap);
    ui->frigo->setPixmap(frigomPixmap);
    ui->comptoir->setPixmap(comptoirPixmap);


    // Ajuster les images à la taille des QLabel
    ui->Four->setScaledContents(true);
    ui->Four2->setScaledContents(true);
    ui->Plan_de_travail->setScaledContents(true);
    ui->frigo->setScaledContents(true);
    ui->comptoir->setScaledContents(true);
}
void MainWindow::setupStaff() {
    // Configuration du chef
    chef = static_cast<Staff*>(ui->chef); // Utiliser le QLabel existant pour le chef
    chef->setPixmap(QPixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/chef.png"));
    chef->setScaledContents(true); // Ajuste l'image au QLabel
    chef->show();

    // Configuration du serveur
    server = static_cast<Staff*>(ui->serveur); // Utiliser le QLabel existant pour le serveur
    server->setPixmap(QPixmap("C:/Users/emman/Downloads/Projet_Programmation_Systeme/src/Vue/Images/serve.png"));
    server->setScaledContents(true); // Ajuste l'image au QLabel
    server->show();
}


void MainWindow::moveServerToClient(Client *client) {
    if (!server) {
        qDebug() << "Erreur : Serveur non initialisé.";
        return;
    }

    // Obtenir la position cible (client)
    QRect clientPosition = client->geometry();
    QRect targetPosition(clientPosition.x() - server->width(), clientPosition.y(), server->width(), server->height());

    // Animation pour déplacer le serveur vers le client
    QPropertyAnimation *animationToClient = new QPropertyAnimation(server, "geometry");
    animationToClient->setDuration(2000);
    animationToClient->setStartValue(server->geometry());
    animationToClient->setEndValue(targetPosition);
    animationToClient->setEasingCurve(QEasingCurve::InOutQuad);
    animationToClient->start(QAbstractAnimation::DeleteWhenStopped);

    qDebug() << "Serveur en déplacement vers le client à :" << targetPosition;

    // Animation pour retourner à la cuisine après une pause
    QTimer::singleShot(3000, this, [this]() {
        QRect kitchenPosition = ui->comptoir->geometry(); // Retourner devant le comptoir
        QPropertyAnimation *animationToKitchen = new QPropertyAnimation(server, "geometry");
        animationToKitchen->setDuration(2000);
        animationToKitchen->setStartValue(server->geometry());
        animationToKitchen->setEndValue(QRect(kitchenPosition.x(), kitchenPosition.y(), server->width(), server->height()));
        animationToKitchen->setEasingCurve(QEasingCurve::InOutQuad);
        animationToKitchen->start(QAbstractAnimation::DeleteWhenStopped);

        qDebug() << "Serveur de retour au comptoir.";
    });
}



void MainWindow::moveChefToNextTask() {
    static int currentTask = 0;

    // Liste des cibles pour le chef
    QList<QLabel*> chefTargets = { ui->Plan_de_travail, ui->Four};

    if (chefTargets.isEmpty()) {
        qDebug() << "Pas d'objets pour le déplacement du chef.";
        return;
    }

    // Déterminer la prochaine cible
    QLabel *nextTarget = chefTargets[currentTask];
    currentTask = (currentTask + 1) % chefTargets.size(); // Alterner entre les cibles

    // Obtenir la position cible (dimensions et position de l’objet)
    QRect targetGeometry = nextTarget->geometry();

    // Ajuster la position pour que le chef reste devant l’objet
    int chefWidth = chef->width();
    int chefHeight = chef->height();
    int adjustedX, adjustedY;

    // Positionnement dynamique en fonction de l’objet
    if (targetGeometry.width() > targetGeometry.height()) {
        // Si l'objet est plus large que haut (ex. comptoir), positionnez au centre devant
        adjustedX = targetGeometry.center().x() - (chefWidth / 2);
        adjustedY = targetGeometry.top() - chefHeight - 15; // Devant l'objet avec un espace
    } else {
        // Si l'objet est plus haut que large (ex. frigo), positionnez à gauche au milieu
        adjustedX = targetGeometry.left() - chefWidth - 15;
        adjustedY = targetGeometry.center().y() - (chefHeight / 2);
    }

    // Vérifier les limites pour s'assurer que le chef ne sort pas de l'écran
    if (adjustedX < 0) adjustedX = 0; // Empêcher de sortir par la gauche
    if (adjustedY < 0) adjustedY = 0; // Empêcher de sortir par le haut

    QRect adjustedPosition(adjustedX, adjustedY, chefWidth, chefHeight);

    // Animation pour déplacer le chef vers la position ajustée
    QPropertyAnimation *animation = new QPropertyAnimation(chef, "geometry");
    animation->setDuration(2000); // Durée de l'animation
    animation->setStartValue(chef->geometry());
    animation->setEndValue(adjustedPosition);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    qDebug() << "Chef moves to adjusted position:" << adjustedPosition << "for target:" << nextTarget->objectName();
}




void MainWindow::resizeServer() {
    QPropertyAnimation *resizeAnimation = new QPropertyAnimation(server, "geometry");
    resizeAnimation->setDuration(1000); // Durée de l'animation
    resizeAnimation->setStartValue(server->geometry());
    resizeAnimation->setEndValue(QRect(server->x(), server->y(), 80, 80)); // Nouvelle taille (80x80)
    resizeAnimation->setEasingCurve(QEasingCurve::InOutQuad);
    resizeAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::moveChefInKitchen() {
    // Obtenir les dimensions locales de la cuisine


    // Animation pour déplacer le chef
    QPropertyAnimation *animation = new QPropertyAnimation(chef, "geometry");
    animation->setDuration(2000); // Durée de l'animation
    animation->setStartValue(chef->geometry());
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}
void MainWindow::setupChefMovement() {
    QTimer *chefTimer = new QTimer(this);
    connect(chefTimer, &QTimer::timeout, this, &MainWindow::moveChefToNextTask);
    chefTimer->start(5000); // Déplacement toutes les 5 secondes
}






