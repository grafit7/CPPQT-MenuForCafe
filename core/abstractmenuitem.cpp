#include "abstractmenuitem.h"
#include "abstractmenuvisitor.h"

/*!
 * \brief AbstractMenuItem constructor.
 * \param name Name of menu item.
 */
AbstractMenuItem::AbstractMenuItem(const std::string &name)
    : mName{name}
    ,mMenuSection{nullptr}
{
}

AbstractMenuItem::~AbstractMenuItem() {}

/*!
 * \brief Getter for menu item name.
 * \return Returns name of menu item.
 */
std::string AbstractMenuItem::name() const
{
    return mName;
}

void AbstractMenuItem::setMenu(MenuSection *menuSection)
{
    if (menuSection && mMenuSection != menuSection)
    {
        mMenuSection = menuSection;
    }
}
