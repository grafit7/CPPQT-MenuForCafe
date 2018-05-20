#include <QApplication>
#include "mainwindow.h"
//#include <iostream>
//#include "abstractmenuitem.h"
//#include "menuitem.h"
//#include "menusection.h"

//#include <memory>
//#include <utility>

int main(int argc, char** argv)
{
    /*
    auto drinks = std::make_unique<MenuSection>("drinks");
    drinks->addItem(std::make_unique<MenuItem>("Beer", 0.0));
    drinks->addItem(std::make_unique<MenuItem>("water", 0.0));

    auto food = std::make_unique<MenuSection>("food");
    food->addItem(std::make_unique<MenuItem>("potatoFree", 0.0));
    food->addItem(std::make_unique<MenuItem>("borshch", 0.0));

    MenuSection menu("MENU");
    menu.addItem(std::move(drinks));
    menu.addItem(std::move(food));
    */
    QApplication app(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    return app.exec();

}
