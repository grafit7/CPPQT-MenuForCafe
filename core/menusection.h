#ifndef MENUSECTION_H
#define MENUSECTION_H

#include <vector>
#include <memory>

#include "abstractmenuitem.h"

class MenuSection : public AbstractMenuItem
{
public:
    MenuSection(const std::string &name);
    virtual ~MenuSection();

    void addItem(std::unique_ptr<AbstractMenuItem> item);

    void apply(AbstractMenuVisitor *visitor) override;

    int size() const;

    AbstractMenuItem *at(unsigned index);

    void removeSubitem() override;
    void deleteChild(AbstractMenuItem* child);

private:
    std::vector<std::unique_ptr<AbstractMenuItem>> mSubItems;
};

#endif // MENUSECTION_H
