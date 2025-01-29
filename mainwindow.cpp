#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress> // Pour gérer les adresses IP
#include <QMessageBox>  // Pour afficher des messages d'erreur si nécessaire

// Constructeur de la fenêtre principale
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    udpSocket(new QUdpSocket(this)) // Initialisation de la socket UDP
{
    ui->setupUi(this); // Configuration de l'interface utilisateur

    // Récupère le port saisi dans le champ de l'interface et le convertit en entier
    quint16 port = ui->port->text().toUInt();

    // Lie la socket pour écouter sur le port spécifié
    if (!udpSocket->bind(QHostAddress::Any, port)) {
        // Affiche un message d'erreur si le port ne peut pas être lié
        QMessageBox::warning(this, "Erreur", "Impossible de lier le port pour recevoir des messages.");
        return;
    }

    // Connecte le signal readyRead de la socket au slot receiveMessage pour la réception des messages
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::receiveMessage);

    // Connecte le clic du bouton d'envoi au slot sendMessage pour l'envoi des messages
    connect(ui->btn_send, &QPushButton::clicked, this, &MainWindow::sendMessage);
}

// Destructeur de la fenêtre principale
MainWindow::~MainWindow()
{
    delete udpSocket; // Libère la mémoire utilisée par la socket UDP
    delete ui;        // Libère la mémoire utilisée par l'interface utilisateur
}

// Slot : Envoyer un message
void MainWindow::sendMessage()
{
    // Récupère le message saisi dans le champ de texte de l'interface
    QString message = ui->message_input->text();

    // Récupère l'adresse IP de destination depuis le champ de texte de l'interface
    QString ipAddress = ui->ip->text();

    // Récupère le port de destination depuis le champ de texte de l'interface
    quint16 port = ui->port->text().toUInt();

    // Vérifie que le message n'est pas vide
    if (message.isEmpty()) {
        ui->message_input->setPlaceholderText("Le message est vide !");
        return;
    }

    // Vérifie que l'adresse IP et le port sont valides
    if (ipAddress.isEmpty() || port == 0) {
        QMessageBox::warning(this, "Erreur", "Adresse IP ou port invalide.");
        return;
    }

    // Convertit le message en QByteArray pour l'envoi via le socket
    QByteArray data = message.toUtf8();

    // Envoie le message à l'adresse IP et au port spécifiés
    udpSocket->writeDatagram(data, QHostAddress(ipAddress), port);

    // Affiche le message envoyé dans la zone d'affichage avec une mention "Moi"
    ui->message_display->append("Moi : " + message);

    // Efface le champ de saisie après l'envoi du message
    ui->message_input->clear();
}

// Slot : Recevoir un message
void MainWindow::receiveMessage()
{
    // Boucle pour traiter tous les messages en attente dans la socket
    while (udpSocket->hasPendingDatagrams()) {
        // Tampon pour stocker les données reçues
        QByteArray buffer;

        // Ajuste la taille du tampon à la taille du datagramme en attente
        buffer.resize(udpSocket->pendingDatagramSize());

        // Variables pour stocker l'adresse IP et le port de l'expéditeur
        QHostAddress sender;
        quint16 senderPort;

        // Lit le datagramme reçu et remplit le tampon, l'adresse IP et le port de l'expéditeur
        udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        // Convertit le tampon en une chaîne de caractères
        QString message = QString::fromUtf8(buffer);

        // Formate les informations de l'expéditeur (adresse IP et port)
        QString senderInfo = QString("[%1:%2]").arg(sender.toString()).arg(senderPort);

        // Affiche le message reçu avec les informations de l'expéditeur
        ui->message_display->append(senderInfo + " : " + message);
    }
}
