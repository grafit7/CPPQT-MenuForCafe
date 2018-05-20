#include "printmenuvisitor.h"

#include <iostream>

#include "menuitem.h"
#include "menusection.h"

PrintMenuVisitor::PrintMenuVisitor()
    : mLevel{}
{

}

void PrintMenuVisitor::visit(MenuItem *item)
{
    levelUp();
    std::cout << indent() << item->name()  << " - $$$ " << item->price() << std::endl;
    levelDown();
}

std::string PrintMenuVisitor::indent() const
{
    std::string rIndent;

    for (int i = 0; i < mLevel; ++i)
    {
        rIndent.append("    ");
    }

    return rIndent;
}

void PrintMenuVisitor::visit(MenuSection *section)
{
    levelUp();

    std::cout << indent() << "[" << section->name() << "]" << std::endl;
    for (int index = 0; index < section->size(); ++index)
    {
        auto nextElement = section->at(index);
        nextElement->apply(this);
    }

    levelDown();
}

void PrintMenuVisitor::levelUp()
{
    mLevel++;
}

void PrintMenuVisitor::levelDown()
{
    mLevel--;
}
