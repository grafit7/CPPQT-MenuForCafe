#include "menuiterator.h"
#include "helpervisitor.h"

#include "core/menusection.h"

#include <iostream>

MenuIterator::MenuIterator(AbstractMenuItem *menu)
    : mChildrenVisitor{std::make_unique<HelperVisitor>()}
{
    auto childrenForTraversal = [this](MenuSection *item)
    {
        if (!item)
        {
            return;
        }

        for (int index = 0; index < item->size(); ++index)
        {
            auto next = item->at(index);
            std::cout << next->name() << std::endl;
            this->mItemsStack.push(next);
        }
    };

    mChildrenVisitor->setMenuSectionHandler(childrenForTraversal);
    menu->apply(mChildrenVisitor.get());
}

bool MenuIterator::hasNext() const
{
    return !mItemsStack.empty();
}

AbstractMenuItem *MenuIterator::next()
{
    AbstractMenuItem *nextItem = mItemsStack.top();
    mItemsStack.pop();

    nextItem->apply(mChildrenVisitor.get());
    return nextItem;
}
