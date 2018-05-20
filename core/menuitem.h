#ifndef MENUITEM_H
#define MENUITEM_H

#include <vector>

#include "abstractmenuitem.h"

class MenuItem : public AbstractMenuItem
{
public:
    MenuItem(const std::string &name,
             const double price);

    MenuItem(const std::string &name,
             const double price,
             const int weight,
             std::vector<std::string>&ingredients);

    virtual ~MenuItem();

    std::vector<std::string> ingredients() const;
    double price() const;
    int weight() const;

    void apply(AbstractMenuVisitor *visitor) override;

private:
    double mPrice;
    int mWeight;
    std::vector<std::string> mIngredients;
};

#endif // MENUITEM_H
