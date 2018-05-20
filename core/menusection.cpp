#include "menusection.h"
#include "abstractmenuvisitor.h"

MenuSection::MenuSection(const std::string &name)
    : AbstractMenuItem{name}
{

}

MenuSection::~MenuSection()
{

}

void MenuSection::addItem(std::unique_ptr<AbstractMenuItem> item)
{
    setMenu(this);
    mSubItems.push_back(std::move(item));
}

void MenuSection::apply(AbstractMenuVisitor *visitor)
{
    if (visitor)
    {
        visitor->visit(this);
    }
}

int MenuSection::size() const
{
    return mSubItems.size();
}

AbstractMenuItem *MenuSection::at(int index)
{
    AbstractMenuItem *returnValue = nullptr;
    if (index >= 0 && index < mSubItems.size())
    {
        returnValue = mSubItems.at(index).get();
    }
    return returnValue;
}
