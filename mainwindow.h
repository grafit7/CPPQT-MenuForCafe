#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

namespace Ui {
class MainWindow;
}

class AbstractMenuItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initMenu();

private slots:
    void slotPrintMenu();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AbstractMenuItem> mRoot;
};

#endif // MAINWINDOW_H
