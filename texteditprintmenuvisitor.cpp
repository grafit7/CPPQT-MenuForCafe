#include "texteditprintmenuvisitor.h"

#include "core/menusection.h"
#include "core/menuitem.h"

#include <QPlainTextEdit>
#include <QString>

TextEditPrintMenuVisitor::TextEditPrintMenuVisitor(QPlainTextEdit *plainTextEdit)
    : mPlainTextEdit{plainTextEdit}
{
}

void TextEditPrintMenuVisitor::visit(MenuSection *menuSection)
{
    if (menuSection)
    {
        QString outString;
        outString = QString("\t[%1]").arg(menuSection->name().c_str());
        mPlainTextEdit->appendPlainText(outString);
    }
}

void TextEditPrintMenuVisitor::visit(MenuItem *menuItem)
{
    if (menuItem)
    {
        QString outString = QString(">  %1\t%2$").arg(menuItem->name().c_str()).arg(menuItem->price());
        mPlainTextEdit->appendPlainText(outString);

        QString description;
        for (unsigned i = 0; i < menuItem->ingredients().size(); ++i)
        {
            description.append(QString("::::%1::::").arg(menuItem->ingredients().at(i).c_str()));
        }
        mPlainTextEdit->appendPlainText(description);
    }
}
