#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "core/consoleprintmenuvisitor.h"

#include "texteditprintmenuvisitor.h"
#include "menuiterator.h"

#include "core/consoleprintmenuvisitor.h"
#include "core/abstractmenuitem.h"
#include "core/menusection.h"
#include "core/menuitem.h"

#include <iostream>
#include <utility>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,mRoot{nullptr}
{
    ui->setupUi(this);

    connect(ui->actionExit_2, &QAction::triggered, this, &MainWindow::close);

    initMenu();
    slotPrintMenu();
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

    auto menu = std::make_unique<MenuSection>("MENU");
    menu->addItem(std::move(drinks));
    menu->addItem(std::move(food));
    mRoot = std::move(menu);
}

void MainWindow::slotPrintMenu()
{
    TextEditPrintMenuVisitor visitor(ui->printTextEdit);

    MenuIterator iterator(mRoot.get());
    while(iterator.hasNext())
    {
        auto item =  iterator.next();
        item->apply(&visitor);
    }
}
