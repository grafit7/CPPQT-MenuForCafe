#ifndef PRINTMENUVISITOR_H
#define PRINTMENUVISITOR_H

#include <string>

#include "abstractmenuvisitor.h"

class PrintMenuVisitor : public AbstractMenuVisitor
{
public:
    PrintMenuVisitor();

    // AbstractMenuVisitor interface
public:
    virtual void visit(MenuItem *item) override;
    virtual void visit(MenuSection *section) override;

private:
    void levelUp();
    void levelDown();

    std::string indent() const;

private:
    char mLevel;
};

#endif // PRINTMENUVISITOR_H
