#ifndef DBCONTROLLER_H
#define DBCONTROLLER_H

#include <string>
#include <../../../src/MySQL/include/jdbc/mysql_connection.h>
#include <../../../src/MySQL/include/jdbc/mysql_driver.h>
#include <../../../src/MySQL/include/jdbc/cppconn/driver.h>
#include <../../../src/MySQL/include/jdbc/cppconn/connection.h>
#include <../../../src/MySQL/include/jdbc/cppconn/statement.h>
#include <../../../src/MySQL/include/jdbc/cppconn/prepared_statement.h>
#include <../../../src/MySQL/include/jdbc/cppconn/resultset.h>


class DBController {
private:
    std::string dbname;      // Nom de la base de données
    std::string user;        // Nom d'utilisateur
    std::string password;    // Mot de passe
    std::string host;        // Hôte (par défaut : localhost)
    int port;                // Port (par défaut : 5432)

    sql::Driver* driver;                             // Driver MySQL
    std::unique_ptr<sql::Connection> connection;

public:
    // Constructeur
    DBController(const std::string& host, const std::string& user, const std::string& password, const std::string& database);

    // Méthodes principales
    bool DBconnect();             // Se connecter à la base de données
    void DBdisconnect();          // Se déconnecter
    bool executeQuery(const std::string& query);    // Exécuter une requête SQL
    std::unique_ptr<sql::ResultSet> fetchQuery(const std::string& query); // Récupérer les résultats d'une requête

~DBController();
};

#endif // DBCONTROLLER_H