#ifndef MENUCOMBOBOX_H
#define MENUCOMBOBOX_H

#include <QComboBox>
#include <QHash>

#include "core/menusection.h"

class AbstractMenuItem;

class MenuComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit MenuComboBox(QWidget *parent = nullptr);

    void setMenu(AbstractMenuItem *menu);

    AbstractMenuItem* currentMenuItem() const;
    void clearData();
    void updateComboBox();

    bool checkDublicate(const std::string &tempTitle);

private:
    void populateComboBox();

private:
    AbstractMenuItem *mRoot;
    QHash<int, AbstractMenuItem*> mItemByIndex;
};

#endif // MENUCOMBOBOX_H
