#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket> // Pour la gestion des sockets UDP

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeur explicite de la fenêtre principale
    explicit MainWindow(QWidget *parent = nullptr);

    // Destructeur de la fenêtre principale
    ~MainWindow();

private slots:
    // Slot pour envoyer un message via la socket UDP
    void sendMessage();

    // Slot pour recevoir des messages via la socket UDP
    void receiveMessage();

private:
    Ui::MainWindow *ui;         // Pointeur vers l'interface utilisateur
    QUdpSocket *udpSocket;      // Pointeur vers l'objet socket UDP
};

#endif // MAINWINDOW_H
