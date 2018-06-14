#ifndef EDITORDELEGATE_H
#define EDITORDELEGATE_H

#include <QWidget>
#include <QMessageBox>
#include "core/abstractmenuvisitor.h"

namespace Ui {
class EditorDelegate;
}

class EditorDelegate : public QWidget, public AbstractMenuVisitor
{
    Q_OBJECT

public:
    explicit EditorDelegate(QWidget *parent = nullptr);
    ~EditorDelegate();

    virtual void visit(MenuItem *item) override;
    virtual void visit(MenuSection *menu) override;

    void clear();

public slots:
    bool slotSave();
    std::string getTempTitle();

signals:
    void itemChanged();

private:
    Ui::EditorDelegate *ui;
    std::string mTempTitle;
    MenuSection *mEditedMenu;
    MenuItem *mEditedMenuItem;
};

#endif // EDITORDELEGATE_H
