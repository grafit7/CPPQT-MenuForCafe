#include "menuitem.h"
#include "menusection.h"
#include "abstractmenuvisitor.h"

MenuItem::MenuItem(const std::string &name,
                   const double price,
                   const int weight,
                   std::vector<std::string> &ingredients)
    : AbstractMenuItem{name}
    , mPrice{price}
    , mWeight{weight}
    , mIngredients{ingredients}
{

}

MenuItem::~MenuItem() {}

MenuItem::MenuItem(const std::string &name,
                   const double price)
    : AbstractMenuItem{name}
    , mPrice{price}
{

}

std::vector<std::string> MenuItem::ingredients() const
{
    return mIngredients;
}

double MenuItem::price() const
{
    return mPrice;
}

int MenuItem::weight() const
{
    return mWeight;
}

void MenuItem::apply(AbstractMenuVisitor *visitor)
{
    if (visitor)
    {
        visitor->visit(this);
    }
}

void MenuItem::removeSubitem()
{
    menu()->deleteChild(this);
}
