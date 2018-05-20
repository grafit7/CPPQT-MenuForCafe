#ifndef ABSTRACTMENUVISITOR_H
#define ABSTRACTMENUVISITOR_H

class MenuItem;
class MenuSection;

class AbstractMenuVisitor
{
public:
    virtual void visit(MenuSection *) = 0;
    virtual void visit(MenuItem *) = 0;
};

#endif // ABSTRACTMENUVISITOR_H
