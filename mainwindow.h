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
    void menuElementSelected();
    void slotUpdateMenu();
    void slotAddNewItem();
    void slotItemChanged();
    void slotSaveEditedItem();
    void slotDeleteItem();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AbstractMenuItem> mRoot;
};

#endif // MAINWINDOW_H
