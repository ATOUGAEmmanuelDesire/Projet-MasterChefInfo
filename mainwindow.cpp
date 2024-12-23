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
#include <QPushButton>
#include "TaskThread.h"

// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
, isPaused(false) // Initialisez la variable isPaused
{
    ui->setupUi(this);
    // Connecter les signaux du thread aux slots de la fenêtre principale
    connect(backgroundTask, &TaskThread::progressUpdate, this, &MainWindow::handleProgressUpdate);

    // Initialisation de l'interface
    setupUI();

    // Ajoutez le bouton de pause
    QPushButton *pauseButton = new QPushButton("Pause", this);
    pauseButton->setGeometry(10, 10, 100, 30); // Positionnez le bouton
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::togglePause);


    // Appeler la fonction pour ajouter des personnages statiques
    addStaticCharacters();


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


void MainWindow::startBackgroundTask() {
    if (!backgroundTask->isRunning()) {
        backgroundTask->start(); // Démarrer le thread
    }
}

void MainWindow::handleProgressUpdate(int value) {
    qDebug() << "Progrès : " << value << "%";
    // Mettez à jour l'interface utilisateur, comme une barre de progression
}

// Initialise l'interface utilisateur
void MainWindow::setupUI() {
    this->setWindowState(Qt::WindowMaximized);
     this->setStyleSheet("QMainWindow { background-image: url('C:/Users/HP/Downloads/Projet-X3-save-main/Images/background.jpg'); background-repeat: no-repeat; background-position: center; }");
}



void MainWindow::togglePause() {
    isPaused = !isPaused; // Inverse l'état de pause
    if (isPaused) {
        // Arrêtez les timers ou les animations
        // Par exemple :
        // timer->stop();
        // animations->setPaused(true);
        qDebug() << "Le programme est en pause.";
    } else {
        // Redémarrez les timers ou les animations
        // Par exemple :
        // timer->start();
        // animations->setPaused(false);
        qDebug() << "Le programme reprend.";
    }
}

// Crée et configure les tables (4x4) et les clients
void MainWindow::createTablesAndClients() {
    // Charger les images
    QPixmap tablePixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/table.png");
    QPixmap clientPixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/client.png");

    if (tablePixmap.isNull() || clientPixmap.isNull()) {
        qDebug() << "Erreur : Impossible de charger les images.";
        return;
    }
    // Dimensions pour positionner les tables
    int rows = 4; // Nombre de lignes
    int cols = 4; // Nombre de colonnes
    int tableSize = 90; // Taille des tables
    int spacing = 30;   // Espace entre les tables
    int specialSpacing = 90; // Espacement spécifique entre les colonnes 2 et 3
    int startX = 100;   // Position de départ en X
    int startY = 100;   // Position de départ en Y

    // Création des cadres des groupes
    QRect leftGroupBounds;  // Rectangle pour le premier groupe
    QRect rightGroupBounds; // Rectangle pour le deuxième groupe
    int groupPadding = 20;  // Espacement entre les tables et le cadre

    // Création des tables (4x4 grille)
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Table *table = new Table(this);
            table->setId(row * cols + col + 1); // ID unique
            table->setDescription(QString("Table %1").arg(row * cols + col + 1));
            table->setPixmap(tablePixmap);

            // Calcul de la position X avec espacement spécifique pour les colonnes 2 et 3
            int posX = startX + col * (tableSize + spacing);
            if (col >= 2) {
                posX += (specialSpacing - spacing); // Ajouter l'espacement spécial pour les colonnes 2 et 3
            }

            // Définir la géométrie de la table
            table->setGeometry(
                posX,                                // Position en X
                startY + row * (tableSize + spacing), // Position en Y
                tableSize,                           // Largeur
                tableSize                            // Hauteur
                );
            table->show();
            tableList.append(table);

            // Calculer les limites des groupes
            if (col < cols / 2) {
                if (leftGroupBounds.isNull()) {
                    leftGroupBounds = table->geometry();
                } else {
                    leftGroupBounds = leftGroupBounds.united(table->geometry());
                }
            } else {
                if (rightGroupBounds.isNull()) {
                    rightGroupBounds = table->geometry();
                } else {
                    rightGroupBounds = rightGroupBounds.united(table->geometry());
                }
            }
        }
    }

    // Ajouter des marges au cadre des groupes
    leftGroupBounds.adjust(-groupPadding, -groupPadding, groupPadding, groupPadding);
    rightGroupBounds.adjust(-groupPadding, -groupPadding, groupPadding, groupPadding);

    // Création des cadres autour des groupes
    QFrame *leftGroupFrame = new QFrame(this);
    leftGroupFrame->setGeometry(leftGroupBounds);
    leftGroupFrame->setStyleSheet("border: 2px solid blue;");
    leftGroupFrame->show();

    QFrame *rightGroupFrame = new QFrame(this);
    rightGroupFrame->setGeometry(rightGroupBounds);
    rightGroupFrame->setStyleSheet("border: 2px solid red;");
    rightGroupFrame->show();



    // Création des clients (4 clients) avec position initiale
    int entryX = 40; // Position initiale en X (entrée)
    int entryY = 500; // Position initiale en Y (entrée)
    for (int i = 0; i < 8; ++i) {
        Client *client = new Client(this);
        client->setId(i + 1);
        client->setName(QString("Client %1").arg(i + 1));
        client->setPixmap(clientPixmap);
        client->setGeometry(entryX, entryY + i * 60, 50, 50); // Alignés verticalement à l'entrée
        client->show();
        clientList.append(client);
        clientCurrentTable[client] = nullptr; // Initialisation sans table
    }



}

// Lancer le comportement répétitif
void MainWindow::startBehavior() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveClientsBetweenTables);
    timer->start(1000000); // Répète toutes les 5 secondes

    // Premier cycle
    moveClientsBetweenTables();
}

// Déplace les clients vers différentes tables aléatoirement sans collision
void MainWindow::moveClientsBetweenTables() {
    // Réinitialiser les tables occupées
    occupiedTables.clear();

    int delay = 0; // Début sans délai
    const int delayIncrement = 10000; // Délai entre chaque client (en millisecondes)

    for (Client *client : clientList) {
        if (!client)
            continue;

        // Planifier le déplacement du client avec un délai
        QTimer::singleShot(delay, this, [this, client]() {
            Table *nextTable = getNextTable(client);
            if (nextTable) {
                // Déplacer le client vers la table
                moveClientToTable(client, nextTable);
                occupiedTables.insert(nextTable); // Marquer la table comme occupée
                qDebug() << client->getName() << "se déplace vers" << nextTable->getDescription();
            }

            // Si c'est le dernier client, lancer le déplacement des serveurs
            if (client == clientList.last()) {
                QTimer::singleShot(delayIncrement, this, [this]() {
                    moveServersToOccupiedTables();
                });
            }
        });

        delay += delayIncrement; // Incrémenter le délai pour le prochain client
    }
}


void MainWindow::showTemporaryMessage(Client *client, const QString &message) {
    if (!client)
        return;

    // Crée un QLabel pour afficher le message
    QLabel *messageLabel = new QLabel(this);
    messageLabel->setText(message);
    messageLabel->setStyleSheet("QLabel { background-color: white; color: black; font: bold 14px; border-radius: 5px; padding: 5px; }");
    messageLabel->setAlignment(Qt::AlignCenter);

    // Positionne le message juste au-dessus du client
    QRect clientGeometry = client->geometry();
    int messageWidth = 200;
    int messageHeight = 50;
    int posX = clientGeometry.center().x() - (messageWidth / 2);
    int posY = clientGeometry.top() - messageHeight - 10;

    messageLabel->setGeometry(posX, posY, messageWidth, messageHeight);
    messageLabel->show();

    // Faire disparaître le message après 2 secondes
    QTimer::singleShot(2000, this, [messageLabel]() {
        messageLabel->deleteLater();
    });
}


void MainWindow::moveClientToTable(Client *client, Table *table) {
    if (!table || occupiedTables.contains(table)) {
        qDebug() << "Erreur : Tentative de déplacement vers une table déjà occupée.";
        return;
    }

    // Déplacement du client vers la table
    client->moveTo(table->geometry());
    clientCurrentTable[client] = table; // Met à jour la table actuelle du client

    // Ajouter la table aux tables occupées
    occupiedTables.insert(table);


    // Appeler un serveur pour servir le client
    QTimer::singleShot(1000, this, [this, client]() {
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


    qDebug() << "Aucune table disponible pour " << client->getName();
    return nullptr; // Aucune table disponible
}


void MainWindow::setupKitchen() {
    // Chargement des images pour les équipements
    QPixmap ovenPixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/lav.png");
    QPixmap fridgePixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/cuisine2.png");
    QPixmap prepTablePixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/cuisine.png");
    QPixmap frigomPixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/frigo.png");
    QPixmap comptoirPixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/compt.png");

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

// Ajoutez une liste pour stocker les serveurs
QList<Staff*> servers;

void MainWindow::setupStaff() {

    // Configuration du chef
    chef = static_cast<Staff*>(ui->chef); // Utiliser le QLabel existant pour le chef
    chef->setPixmap(QPixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/chef.png"));
    chef->setScaledContents(true); // Ajuste l'image au QLabel4
    chef->show();

    // Configuration du deuxième chef
    QLabel *chef2 = new QLabel(this); // Créer un QLabel pour le deuxième chef
    chef2->setPixmap(QPixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/chef.png"));
    chef2->setScaledContents(true); // Ajuste l'image au QLabel
    chef2->setGeometry(1100, 200, 100, 100); // Positionner le deuxième chef (X, Y, largeur, hauteur)
    chef2->show();


    // Chemin de l'image du serveur
    QPixmap pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/serve.png");

    // Vérification que l'image est bien chargée
    if (!pixmap.isNull()) {
        // Taille personnalisée des serveurs
        QSize customSize(80, 80);
        QPixmap resizedPixmap = pixmap.scaled(customSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Position initiale et espacement des serveurs
        int startX = 700;  // Position X de départ
        int startY = 10;  // Position Y de départ
        int spacing = 150; // Espacement entre les serveurs

        // Création de 4 serveurs
        for (int i = 0; i < 4; ++i) {
            Staff* server = new Staff(this);
            server->setPixmap(resizedPixmap);
            server->setScaledContents(false);
            server->setGeometry(startX , startY+ i * spacing, customSize.width(), customSize.height());
            server->show();
            servers.append(server); // Ajouter le serveur à la liste
        }
    } else {
        qDebug() << "Erreur : Impossible de charger l'image du serveur.";
    }
}

void MainWindow::moveServerToClient(Client *client) {
    if (servers.isEmpty()) {
        qDebug() << "Erreur : Aucun serveur initialisé.";
        return;
    }

    // Obtenir la position du client et de sa table
    Table *table = clientCurrentTable[client];
    if (!table) {
        qDebug() << "Erreur : Aucune table assignée au client.";
        return;
    }


    QRect tablePosition = table->geometry();

    // Sélectionner un serveur disponible
    static int serverIndex = 0;
    Staff *server = servers[serverIndex++ % servers.size()]; // Boucler sur les serveurs

    // Animation pour retourner le serveur en cuisine avant de servir le client
    QRect kitchenPosition(700, 10 + (serverIndex - 1) % servers.size() * 150, server->width(), server->height());
    QPropertyAnimation *animationToKitchen = new QPropertyAnimation(server, "geometry");
    animationToKitchen->setDuration(3000);
    animationToKitchen->setStartValue(server->geometry());
    animationToKitchen->setEndValue(kitchenPosition);
    animationToKitchen->setEasingCurve(QEasingCurve::InOutQuad);

    // Animation pour déplacer le serveur vers la table après avoir atteint la cuisine
    QPropertyAnimation *animationToTable = new QPropertyAnimation(server, "geometry");
    animationToTable->setDuration(3000);
    QRect targetPosition(tablePosition.x() + 10, tablePosition.y() - 50, server->width(), server->height());
    animationToTable->setStartValue(kitchenPosition);
    animationToTable->setEndValue(targetPosition);
    animationToTable->setEasingCurve(QEasingCurve::InOutQuad);

    // Chainer les animations
    connect(animationToKitchen, &QPropertyAnimation::finished, this, [animationToTable]() {
        animationToTable->start(QAbstractAnimation::DeleteWhenStopped);
    });

    animationToKitchen->start(QAbstractAnimation::DeleteWhenStopped);

    // Afficher le message avant le déplacement
    showTemporaryMessage(client, "Miam miam. J'ai faim.");



    // Une fois la tâche terminée, le serveur retourne en cuisine
    QTimer::singleShot(7000, this, [this, server, serverIndex]() {
        QRect kitchenPosition(700, 10 + (serverIndex - 1) % servers.size() * 150, server->width(), server->height());
        QPropertyAnimation *animationToKitchenAfterService = new QPropertyAnimation(server, "geometry");
        animationToKitchenAfterService->setDuration(3000);
        animationToKitchenAfterService->setStartValue(server->geometry());
        animationToKitchenAfterService->setEndValue(kitchenPosition);
        animationToKitchenAfterService->setEasingCurve(QEasingCurve::InOutQuad);
        animationToKitchenAfterService->start(QAbstractAnimation::DeleteWhenStopped);

        qDebug() << "Serveur retourne en cuisine après avoir servi.";
    });

    qDebug() << "Serveur retourne en cuisine puis va servir.";

}





void MainWindow::moveServersToOccupiedTables() {
    if (servers.isEmpty() || occupiedTables.isEmpty()) {
        qDebug() << "Erreur : Aucun serveur ou aucune table occupée.";
        return;
    }

    QList<Table*> occupiedTablesList = QList<Table*>(occupiedTables.begin(), occupiedTables.end());
    int totalTables = occupiedTablesList.size();
    int totalServers = servers.size();

    for (int i = 0; i < totalServers; ++i) {
        if (i >= totalTables) {
            qDebug() << "Serveur " << i + 1 << " n'a pas de table à servir.";
            continue; // Si plus de serveurs que de tables occupées, certains serveurs restent en cuisine
        }

        Staff *server = servers[i];
        Table *table = occupiedTablesList[i];
        QRect tablePosition = table->geometry();

        // Définir la position cible du serveur (près de la table)
        QRect targetPosition(tablePosition.x() + 10, tablePosition.y() - 50, server->width(), server->height());

        // Animation pour déplacer le serveur vers la table
        QPropertyAnimation *animationToTable = new QPropertyAnimation(server, "geometry");
        animationToTable->setDuration(3000); // Durée uniforme pour tous les serveurs
        animationToTable->setStartValue(server->geometry());
        animationToTable->setEndValue(targetPosition);
        animationToTable->setEasingCurve(QEasingCurve::InOutQuad);
        animationToTable->start(QAbstractAnimation::DeleteWhenStopped);

        // Retourner le serveur à la cuisine après une pause
        QTimer::singleShot(4000, this, [this, server, i]() {
            QRect kitchenPosition(700, 10 + i * 150, server->width(), server->height()); // Position initiale en cuisine
            QPropertyAnimation *animationToKitchen = new QPropertyAnimation(server, "geometry");
            animationToKitchen->setDuration(3000); // Durée uniforme
            animationToKitchen->setStartValue(server->geometry());
            animationToKitchen->setEndValue(kitchenPosition);
            animationToKitchen->setEasingCurve(QEasingCurve::InOutQuad);
            animationToKitchen->start(QAbstractAnimation::DeleteWhenStopped);

            qDebug() << "Serveur " << i + 1 << " retourne en cuisine.";
        });

        qDebug() << "Serveur " << i + 1 << " se dirige vers une table occupée.";
    }


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
    animation->setDuration(3000); // Durée de l'animation
    animation->setStartValue(chef->geometry());
    animation->setEndValue(adjustedPosition);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    qDebug() << "Chef moves to adjusted position:" << adjustedPosition << "for target:" << nextTarget->objectName();
}




void MainWindow::resizeServer() {
    QPropertyAnimation *resizeAnimation = new QPropertyAnimation(server, "geometry");
    resizeAnimation->setDuration(3000); // Durée de l'animation
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
    chefTimer->start(4000); // Déplacement toutes les 5 secondes
}

void MainWindow::addStaticCharacters() {
    // Chemins des images des personnages statiques
    QPixmap character1Pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/hostel-master.png");
    QPixmap character2Pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/commis-cuisine.png");
    QPixmap character3Pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/plongeur.png");
    QPixmap character4Pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/chef-rang.png");
    QPixmap character5Pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/chef-rang.png");
    QPixmap character6Pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/commis-salle.png");
    QPixmap character7Pixmap("C:/Users/HP/Downloads/Projet-X3-save-main/Images/plongeur.png");

    // Création des personnages statiques
    QLabel* characters[7];
    characters[0] = new QLabel(this);
    characters[1] = new QLabel(this);
    characters[2] = new QLabel(this);
    characters[3] = new QLabel(this);
    characters[4] = new QLabel(this);
    characters[5] = new QLabel(this);
    characters[6] = new QLabel(this);

    // Définition des images
    characters[0]->setPixmap(character1Pixmap);
    characters[1]->setPixmap(character2Pixmap);
    characters[2]->setPixmap(character3Pixmap);
    characters[3]->setPixmap(character4Pixmap);
    characters[4]->setPixmap(character5Pixmap);
    characters[5]->setPixmap(character6Pixmap);
    characters[6]->setPixmap(character7Pixmap);

    // Ajustement des tailles des images
    for (int i = 0; i < 7; ++i) {
        characters[i]->setScaledContents(true);
    }

    // Définir la géométrie des personnages (emplacements spécifiques)
    characters[0]->setGeometry(100, 580, 100, 90);
    characters[1]->setGeometry(950, 120, 140, 140);
    characters[2]->setGeometry(900, 350, 100, 80);
    characters[3]->setGeometry(50, 10, 100, 80);
    characters[4]->setGeometry(500, 10, 100, 80);
    characters[5]->setGeometry(320, 10, 100, 80);
    characters[6]->setGeometry(900, 220, 100, 80);

    // Afficher les personnages et ajouter des animations oscillatoires
    for (int i = 0; i < 7; ++i) {
        characters[i]->show();

        // Créer une animation oscillatoire
        QPropertyAnimation *animation = new QPropertyAnimation(characters[i], "geometry");
        animation->setDuration(1000); // Durée de l'oscillation
        animation->setLoopCount(-1); // Loop indéfini

        // Définir la position de départ et d'arrivée pour un mouvement oscillatoire
        QRect startRect = characters[i]->geometry();
        QRect endRect;

        // Définir des mouvements oscillatoires différents pour chaque personnage
        switch (i) {
        case 0: // Oscillation haut/bas
            endRect = QRect(startRect.x(), startRect.y() - 20, startRect.width(), startRect.height());
            break;
        case 1: // Oscillation gauche/droite
            endRect = QRect(startRect.x() + 20, startRect.y(), startRect.width(), startRect.height());
            break;
        case 2: // Oscillation haut/bas
            endRect = QRect(startRect.x(), startRect.y() - 20, startRect.width(), startRect.height());
            break;
        case 3: // Oscillation haut/bas
            endRect = QRect(startRect.x(), startRect.y() - 20, startRect.width(), startRect.height());
            break;
        case 4: // Oscillation haut/bas
            endRect = QRect(startRect.x(), startRect.y() - 20, startRect.width(), startRect.height());
            break;
        case 5: // Oscillation gauche
            endRect = QRect(startRect.x() - 20, startRect.y(), startRect.width(), startRect.height());
            break;
        case 6: // Oscillation diagonale opposée
            endRect = QRect(startRect.x() - 15, startRect.y() + 15, startRect.width(), startRect.height());
            break;
        }

        // Configurer l'animation pour aller et revenir
        animation->setKeyValueAt(0, startRect);
        animation->setKeyValueAt(0.5, endRect);
        animation->setKeyValueAt(1, startRect);
        animation->setEasingCurve(QEasingCurve::InOutSine); // Courbe d'oscillation douce

        // Démarrer l'animation
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}


