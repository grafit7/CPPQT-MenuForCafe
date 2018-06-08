#ifndef HELPERVISITOR_H
#define HELPERVISITOR_H

#include "core/abstractmenuvisitor.h"

#include <functional>

class MenuSection;
class MenuItem;

class HelperVisitor : public AbstractMenuVisitor
{
public:
    void setMenuSectionHandler(std::function<void(MenuSection *)> menuSectionHandler);
    void setMenuItemHandler(std::function<void(MenuItem *)> menuItemHandler);

public:
    void visit(MenuSection *item) override;
    void visit(MenuItem *item) override;

private:
    std::function<void(MenuSection *)> mMenuSectionHandler;
    std::function<void(MenuItem *)> mMenuItemHandler;
};

#endif // HELPERVISITOR_H
