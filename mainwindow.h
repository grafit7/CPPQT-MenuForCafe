#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MenuSection;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    void initMenu();
    void printMenu(MenuSection *menuSection);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
