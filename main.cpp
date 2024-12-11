#include <QApplication>
#include <QPushButton>
#include "src/Vue/mainwindow.h"
#include "src/Controllers/classDeclaration/MainController.h"

// int main(int argc, char* argv[])
// {
//     QApplication a(argc, argv);
//     QPushButton button("Hello world!", nullptr);
//     button.resize(2000, 1000);
//     button.show();
//     return QApplication::exec();
// }
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainController mainController;
    MainWindow window;
    window.resize(800, 600); // Définir la taille de la fenêtre
    window.show();
    QPushButton button;
    return app.exec();
    mainController.connectToDB();
    mainController.initializeRestaurant();
    mainController.makeRequest();

}
