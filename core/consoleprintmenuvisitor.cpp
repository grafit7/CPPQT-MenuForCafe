#include "consoleprintmenuvisitor.h"
#include "menusection.h"
#include "menuitem.h"

#include <iostream>

void ConsolePrintMenuVisitor::visit(MenuSection *menuSection)
{
    std::cout << "*********" << menuSection->name() << "*********" << std::endl;

    for (int i = 0; i < menuSection->size(); ++i)
    {
        std::cout << "\t";
        menuSection->at(i)->apply(this);
    }
}

void ConsolePrintMenuVisitor::visit(MenuItem *menuItem)
{
    if (menuItem)
    {
        std::cout << menuItem->name() << '\t' << menuItem->price() << '$' << std::endl;
    }
}
