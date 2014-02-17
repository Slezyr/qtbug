#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason reason);

private:
    QSystemTrayIcon *trayIcon;
};

#endif // MAINWINDOW_H
