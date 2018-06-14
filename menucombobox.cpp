#include "menucombobox.h"
#include "menuiterator.h"

MenuComboBox::MenuComboBox(QWidget *parent)
    : QComboBox(parent)
    ,mRoot{nullptr}
{
}

void MenuComboBox::setMenu(AbstractMenuItem *menu)
{
    if (menu)
    {
        mRoot = menu;
        clear();
        mItemByIndex.clear();
        populateComboBox();
    }
}

AbstractMenuItem *MenuComboBox::currentMenuItem() const
{
    int itemId = currentData().toInt();
    return mItemByIndex.value(itemId);
}

void MenuComboBox::clearData()
{
    clear();
    mItemByIndex.clear();
}

void MenuComboBox::updateComboBox()
{
    clear();
    populateComboBox();
}


void MenuComboBox::populateComboBox()
{
    if (mRoot)
    {
        MenuIterator iterator(mRoot);
        while (iterator.hasNext())
        {
            AbstractMenuItem *item = iterator.next();
            int itemId = mItemByIndex.size();
            mItemByIndex.insert(itemId, item);
            addItem(item->name().c_str(), itemId);
        }
    }
}

bool MenuComboBox::checkDublicate(const std::string &tempTitle)
{
    if (mRoot)
    {
        MenuIterator iterator(mRoot);
        while (iterator.hasNext())
        {
            AbstractMenuItem * item = iterator.next();
            if(item->name() == tempTitle)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
