#include "../classDeclaration/SocketController.h"
#include <iostream>

SocketController::SocketController(int port) : port(port), serverActive(false) {}

void SocketController::IncomingRequests() {
    std::cout << "Processing incoming requests on port " << port << "..." << std::endl;
    // Simulation du traitement des requêtes
}

void SocketController::Response(const std::string& message) {
    std::cout << "Sending response: " << message << std::endl;
}

// Envoyer une commande à la cuisine
void SocketController::sendOrderToKitchen(const std::string& order) {
    messagesToKitchen.push(order);
    std::cout << "Commande envoyée à la cuisine : " << order << std::endl;
}

// Récupérer une commande dans la cuisine
std::string SocketController::receiveOrderInKitchen() {
    if (!messagesToKitchen.empty()) {
        std::string order = messagesToKitchen.front();
        messagesToKitchen.pop();
        std::cout << "Commande reçue en cuisine : " << order << std::endl;
        return order;
    } else {
        std::cerr << "Aucune commande en attente pour la cuisine." << std::endl;
        return "";
    }
}

// Envoyer un message à la salle de restauration
void SocketController::sendMessageToDiningRoom(const std::string& message) {
    messagesToDiningRoom.push(message);
    std::cout << "Message envoyé à la salle de restauration : " << message << std::endl;
}

// Récupérer un message dans la salle de restauration
std::string SocketController::receiveMessageInDiningRoom() {
    if (!messagesToDiningRoom.empty()) {
        std::string message = messagesToDiningRoom.front();
        messagesToDiningRoom.pop();
        std::cout << "Message reçu dans la salle de restauration : " << message << std::endl;
        return message;
    } else {
        std::cerr << "Aucun message en attente pour la salle de restauration." << std::endl;
        return "";
    }
}