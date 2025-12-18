#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"monitor.h"
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updateValues();
private:
    Ui::MainWindow *ui;
    PerformanceMonitor monitor;
};
#endif // MAINWINDOW_H
