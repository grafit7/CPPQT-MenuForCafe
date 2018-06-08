#include "helpervisitor.h"

void HelperVisitor::setMenuSectionHandler(std::function<void (MenuSection *)> menuSectionHandler)
{
    mMenuSectionHandler = menuSectionHandler;
}

void HelperVisitor::setMenuItemHandler(std::function<void (MenuItem *)> menuItemHandler)
{
    mMenuItemHandler = menuItemHandler;
}

void HelperVisitor::visit(MenuSection *item)
{
    if (mMenuSectionHandler)
    {
        mMenuSectionHandler(item);
    }
}

void HelperVisitor::visit(MenuItem *item)
{
    if (mMenuItemHandler)
    {
        mMenuItemHandler(item);
    }
}
