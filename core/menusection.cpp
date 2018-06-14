#include "menusection.h"
#include "abstractmenuvisitor.h"

#include <algorithm>

MenuSection::MenuSection(const std::string &name)
    : AbstractMenuItem{name}
{
}

void MenuSection::addItem(std::unique_ptr<AbstractMenuItem> item)
{
    item->setMenu(this);
    mSubItems.push_back(std::move(item));
}

void MenuSection::apply(AbstractMenuVisitor *visitor)
{
    if (visitor)
    {
        visitor->visit(this);
    }
}

size_t MenuSection::size() const
{
    return mSubItems.size();
}

AbstractMenuItem *MenuSection::at(unsigned index)
{
    AbstractMenuItem *returnValue = nullptr;
    if (index < mSubItems.size())
    {
        returnValue = mSubItems.at(index).get();
    }
    return returnValue;
}

void MenuSection::removeSubitem()
{
    while(!mSubItems.empty())
    {
        mSubItems.back()->removeSubitem();
    }
    if(menu())
    {
        menu()->deleteChild(this);
    }
}

void MenuSection::deleteChild(AbstractMenuItem *child)
{
    if (child)
    {
        auto toDel = std::find_if(mSubItems.begin(), mSubItems.end(), [&child](std::unique_ptr<AbstractMenuItem>& obj)
        {
            return obj.get() == child;
        });
        mSubItems.erase(toDel);
    }
}
