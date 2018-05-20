#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "core/consoleprintmenuvisitor.h"
#include "core/abstractmenuitem.h"
#include "core/menusection.h"
#include "core/menuitem.h"

#include <iostream>
#include <utility>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit_2, &QAction::triggered, this, &MainWindow::close);
    initMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    auto drinks = std::make_unique<MenuSection>("drinks");
    drinks->addItem(std::make_unique<MenuItem>("Beer", 0.0));
    drinks->addItem(std::make_unique<MenuItem>("water", 0.0));

    auto food = std::make_unique<MenuSection>("food");
    food->addItem(std::make_unique<MenuItem>("potatoFree", 0.0));
    food->addItem(std::make_unique<MenuItem>("borshch", 0.0));

    MenuSection menu("MENU");
    menu.addItem(std::move(drinks));
    menu.addItem(std::move(food));

    printMenu(&menu);
}

void MainWindow::printMenu(MenuSection *menuSection)
{
    auto visitor = std::make_unique<ConsolePrintMenuVisitor>();
    menuSection->apply(visitor.get());
}
