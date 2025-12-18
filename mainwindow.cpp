#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "monitor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    if(!monitor.starter())
    {
        qDebug()<< "Initialization Failed";
    }
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateValues);
    timer->start(1000); 


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateValues()
{
    if (!monitor.collector())
        return;   
    double cpu = monitor.getCPU();
    double ram = monitor.getRAM();
    double disk = monitor.getDisk();
    double net = monitor.getNetworkUsage();

    ui->cpuLabel->setText(QString::number(cpu, 'f', 2) + "%");
    ui->ramLabel->setText(QString::number(ram, 'f', 2) + " MB");
    ui->diskLabel->setText(QString::number(disk, 'f', 2) + "%");
    ui->networkLabel->setText(QString::number(net, 'f', 2) + " B/s");
}
