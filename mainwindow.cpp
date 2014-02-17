#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/trayicon.png"));
    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason)));

    resize(400, 400);
    QPushButton *bananaButton = new QPushButton("Banana!");
    connect(bananaButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    setCentralWidget(bananaButton);
}

MainWindow::~MainWindow()
{

}

void MainWindow::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
    {
        if(isHidden())
        {
            QPoint tmp = pos();
            show();
            qDebug() << "Previous geometry: " << geometry();
            move(0, 0);
            qDebug() << "New Geometry: " << geometry();
            move(tmp);
        } else {
            hide();
        }
    }
}
