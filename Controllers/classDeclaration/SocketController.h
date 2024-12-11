#ifndef SOCKETCONTROLLER_H
#define SOCKETCONTROLLER_H

#include <string>
#include <queue>

class SocketController {
private:
    int port; // Port utilisé pour les connexions
    bool serverActive;
    std::queue<std::string> messagesToKitchen;  // Messages envoyés à la cuisine
    std::queue<std::string> messagesToDiningRoom;  // Messages de la cuisine vers la salle

public:
    // Constructeur
    explicit SocketController(int port);

    // Méthodes
    void IncomingRequests(); // Traiter les requêtes entrantes
    void Response(const std::string& message); // Envoyer une réponse

    // Méthodes de communication
    void sendOrderToKitchen(const std::string& order); // Envoie une commande à la cuisine
    std::string receiveOrderInKitchen(); // Récupère une commande dans la cuisine
    void sendMessageToDiningRoom(const std::string& message); // Envoie un message à la salle
    std::string receiveMessageInDiningRoom(); // Récupère un message dans la salle

};

#endif // SOCKETCONTROLLER_H
