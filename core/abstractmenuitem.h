#ifndef ABSTRACTMENUITEM_H
#define ABSTRACTMENUITEM_H

#include <string>
#include <memory>

class AbstractMenuVisitor;
class MenuSection;

/*!
 * \brief The AbstractMenuItem class.
 * base class for all menu items in the application.
 */
class AbstractMenuItem
{
public:
    AbstractMenuItem(const std::string &name);
    virtual ~AbstractMenuItem() = 0;

    std::string name() const;

    void setMenu(MenuSection *menuSection);

    virtual void apply(AbstractMenuVisitor *visitor) = 0;

private:
    std::string mName;
    MenuSection *mMenuSection;
};

#endif // ABSTRACTMENUITEM_H
