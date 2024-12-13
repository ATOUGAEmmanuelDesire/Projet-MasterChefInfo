#ifndef TASKTHREAD_H
#define TASKTHREAD_H

#include <QThread>
#include <QObject>

class TaskThread : public QThread {
    Q_OBJECT

public:
    explicit TaskThread(QObject *parent = nullptr);
    ~TaskThread();

    void run() override; // Code exécuté dans le thread

signals:
    void progressUpdate(int value); // Signal pour mettre à jour le progrès
};

#endif // TASKTHREAD_H
