#ifndef TEXTEDITPRINTMENUVISITOR_H
#define TEXTEDITPRINTMENUVISITOR_H


#include "core/abstractmenuvisitor.h"

class QPlainTextEdit;

class TextEditPrintMenuVisitor : public AbstractMenuVisitor
{
public:
    TextEditPrintMenuVisitor(QPlainTextEdit *plainTextEdit = {nullptr});

    void visit(MenuSection *menuSection) override;
    void visit(MenuItem *item) override;

private:
    QPlainTextEdit *mPlainTextEdit;
};

#endif // TEXTEDITPRINTMENUVISITOR_H
