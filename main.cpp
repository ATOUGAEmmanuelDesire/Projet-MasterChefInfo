#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(800, 600); // Définir la taille de la fenêtre
    window.show();

    return app.exec();
}
