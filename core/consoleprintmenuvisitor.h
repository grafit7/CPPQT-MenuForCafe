#ifndef CONSOLEPRINTMENUVISITOR_H
#define CONSOLEPRINTMENUVISITOR_H

#include "abstractmenuvisitor.h"

class ConsolePrintMenuVisitor : public AbstractMenuVisitor
{
public:
    ConsolePrintMenuVisitor() : AbstractMenuVisitor()
    {}
    void visit(MenuSection *menuSection) override;
    void visit(MenuItem *menuItem) override;
};

#endif // CONSOLEPRINTMENUVISITOR_H
