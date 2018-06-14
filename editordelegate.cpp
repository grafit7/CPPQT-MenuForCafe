#include "editordelegate.h"
#include "ui_editordelegate.h"

#include "core/menusection.h"
#include "core/menuitem.h"

EditorDelegate::EditorDelegate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorDelegate)
{
    ui->setupUi(this);

    connect(ui->menuNameLineEdit, &QLineEdit::textChanged,
            this, &EditorDelegate::itemChanged, Qt::UniqueConnection);
    connect(ui->menuItemNameLineEdit, &QLineEdit::textChanged,
            this, &EditorDelegate::itemChanged, Qt::UniqueConnection);
    connect(ui->menuItemDescriptionLineEdit, &QLineEdit::textChanged,
            this, &EditorDelegate::itemChanged, Qt::UniqueConnection);
    connect(ui->menuItemPriceSpinBox,
            static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &EditorDelegate::itemChanged, Qt::UniqueConnection);
}

EditorDelegate::~EditorDelegate()
{
    delete ui;
}

void EditorDelegate::visit(MenuItem *item)
{
    blockSignals(true);

    clear();

    ui->stackedWidget->setCurrentWidget(ui->pageMenuItem);
    ui->menuItemNameLineEdit->setText(item->name().c_str());
    QString ingredients;
    for (size_t i = 0; i < item->ingredients().size(); ++i)
    {
        ingredients.append(item->ingredients().at(i).c_str());
    }
    ui->menuItemDescriptionLineEdit->setText(ingredients);
    ui->menuItemPriceSpinBox->setValue(item->price());

    mEditedMenuItem = item;

    blockSignals(false);
}

void EditorDelegate::visit(MenuSection *menu)
{
    blockSignals(true);

    clear();

    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    ui->menuNameLineEdit->setText(menu->name().c_str());
    ui->menuCountLabel->setText(QString::number(menu->size()));

    mEditedMenu = menu;

    blockSignals(false);
}

void EditorDelegate::clear()
{
    mEditedMenu = nullptr;
    mEditedMenuItem = nullptr;
}



bool EditorDelegate::slotSave()
{
    bool returnValue = false;
    if((ui->menuItemNameLineEdit->text().toStdString().empty()
        && ui->stackedWidget->currentWidget() == ui->pageMenuItem)
        || (ui->menuNameLineEdit->text().toStdString().empty()
        && ui->stackedWidget->currentWidget() == ui->pageMenu))
    {
        QMessageBox msgBox;
        msgBox.setText("Please, enter name first.");
        msgBox.exec();
    }
    else
    {
        if (mEditedMenuItem)
        {
            mEditedMenuItem->setName(ui->menuItemNameLineEdit->text().toStdString());
            std::vector<std::string> ingredients;
            ingredients.push_back(ui->menuItemDescriptionLineEdit->text().toStdString());
            mEditedMenuItem->setIngredients(ingredients);
            mEditedMenuItem->setPrice(ui->menuItemPriceSpinBox->value());
            mTempTitle = ui->menuItemNameLineEdit->text().toStdString();
            returnValue = true;
        }

        if (mEditedMenu)
        {
            mEditedMenu->setName(ui->menuNameLineEdit->text().toStdString());
            mTempTitle = ui->menuNameLineEdit->text().toStdString();
            returnValue = true;
        }
    }
    return returnValue;
}

std::string EditorDelegate::getTempTitle()
{
    return mTempTitle;
}
