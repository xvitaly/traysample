#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setting variables...
    QMenu *trayIconMenu;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    // Setting actions...
    minimizeAction = new QAction("Minimize", this);
    restoreAction = new QAction("Restore", this);
    quitAction = new QAction("Quit", this);

    // Connecting actions to slots...
    connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect (restoreAction, SIGNAL(triggered()),this,SLOT(showNormal()));
    connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    // Setting system tray's icon menu...
    trayIconMenu = new QMenu(this);
    trayIconMenu -> addAction (minimizeAction);
    trayIconMenu -> addAction (restoreAction);
    trayIconMenu -> addAction (quitAction);

    // Setting tray icon...
    QSystemTrayIcon* systray = new QSystemTrayIcon(this);
    QIcon icon(":/images/abc.png");
    systray -> setIcon(icon);
    systray -> setContextMenu(trayIconMenu);
    systray -> show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    if (event -> type() == QEvent::WindowStateChange)
    {
        if(isMinimized())
        {
            this->hide();
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    //
}
