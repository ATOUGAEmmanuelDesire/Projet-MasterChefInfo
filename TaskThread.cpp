#include "TaskThread.h"
#include <QDebug>
#include <QThread>

TaskThread::TaskThread(QObject *parent) : QThread(parent) {}

TaskThread::~TaskThread() {
    // Arrêtez le thread correctement
    if (isRunning()) {
        quit();
        wait();
    }
}

void TaskThread::run() {
    for (int i = 0; i < 100; ++i) {
        QThread::msleep(100); // Simule une tâche
        emit progressUpdate(i); // Envoyer une mise à jour
    }
    qDebug() << "Thread terminé.";
}
