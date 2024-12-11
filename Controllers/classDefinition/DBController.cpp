#include "../classDeclaration/DBController.h"
#include <iostream>
 

DBController::DBController(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
    : host(host), user(user), password(password), dbname(database), driver(nullptr), connection(nullptr) {}

bool DBController::DBconnect() {
    try {
        driver = get_driver_instance(); // Obtenir le driver MySQL
        connection = std::unique_ptr<sql::Connection>(driver->connect(host, user, password)); // Se connecter
        connection->setSchema(dbname); // Spécifier la base de données
        std::cout << "Connexion réussie à la base de données " << dbname << std::endl;
        return true;
    } catch (sql::SQLException& e) {
        std::cerr << "Erreur de connexion : " << e.what() << std::endl;
        return false;
    }
}

void DBController::DBdisconnect() {
    if (connection) {
        connection->close();
        std::cout << "Déconnecté de la base de données." << std::endl;
    }
}

bool DBController::executeQuery(const std::string& query) {
    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        stmt->execute(query);
        return true;
    } catch (sql::SQLException& e) {
        std::cerr << "Erreur lors de l'exécution de la requête : " << e.what() << std::endl;
        return false;
    }
}

std::unique_ptr<sql::ResultSet> DBController::fetchQuery(const std::string& query) {
    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        return std::unique_ptr<sql::ResultSet>(stmt->executeQuery(query));
    } catch (sql::SQLException& e) {
        std::cerr << "Erreur lors de la récupération des résultats : " << e.what() << std::endl;
        return nullptr;
    }
}

// Destructeur
DBController::~DBController() {
    DBdisconnect();
}