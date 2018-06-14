#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "texteditprintmenuvisitor.h"
#include "menuiterator.h"
#include "adddialog.h"

#include "core/consoleprintmenuvisitor.h"
#include "core/abstractmenuvisitor.h"
#include "core/abstractmenuitem.h"
#include "core/menusection.h"
#include "core/menuitem.h"

#include <iostream>
#include <utility>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,mRoot{nullptr}
{
    ui->setupUi(this);

    initMenu();
    slotUpdateMenu();

    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);

    connect(ui->chooseMenuComboBox,
            static_cast<void (MenuComboBox::*)(int)>(&MenuComboBox::currentIndexChanged),
            this, &MainWindow::menuElementSelected, Qt::UniqueConnection);
    connect(ui->savePushButton, &QPushButton::clicked,
            this, &MainWindow::slotSaveEditedItem, Qt::UniqueConnection);
    connect(ui->menuEditorDelegate, &EditorDelegate::itemChanged,
            this, &MainWindow::slotItemChanged, Qt::UniqueConnection);
    connect(ui->addButton, &QPushButton::clicked,
            this, &MainWindow::slotAddNewItem, Qt::UniqueConnection);
    connect(ui->deletePushButton, &QPushButton::clicked,
            this, &MainWindow::slotDeleteItem, Qt::UniqueConnection);
    connect(ui->actionAdd, &QAction::triggered,
            this, &MainWindow::slotAddNewItem, Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    auto drinks = std::make_unique<MenuSection>("drinks");
    drinks->addItem(std::make_unique<MenuItem>("Beer", 0.0));
    drinks->addItem(std::make_unique<MenuItem>("water", 0.0));

    auto food = std::make_unique<MenuSection>("food");
    food->addItem(std::make_unique<MenuItem>("potatoFree", 0.0));
    food->addItem(std::make_unique<MenuItem>("borshch", 0.0));

    auto menu = std::make_unique<MenuSection>("MENU");
    menu->addItem(std::move(drinks));
    menu->addItem(std::move(food));
    mRoot = std::move(menu);
}

void MainWindow::slotPrintMenu()
{
    ui->printTextEdit->clear();
    TextEditPrintMenuVisitor visitor(ui->printTextEdit);

    MenuIterator iterator(mRoot.get());
    while(iterator.hasNext())
    {
        auto item = iterator.next();
        item->apply(&visitor);
    }
}

void MainWindow::menuElementSelected()
{
    ui->savePushButton->setEnabled(false);

    AbstractMenuItem *item = ui->chooseMenuComboBox->currentMenuItem();

    AbstractMenuVisitor *visitor = ui->menuEditorDelegate;
    item->apply(visitor);
    ui->deletePushButton->setEnabled(true);
}

void MainWindow::slotUpdateMenu()
{
    int index = ui->chooseMenuComboBox->currentIndex();

    ui->chooseMenuComboBox->setMenu(mRoot.get());
    slotPrintMenu();
    ui->chooseMenuComboBox->setCurrentIndex(index);
}

void MainWindow::slotAddNewItem()
{
    AddDialog addDialog;
    addDialog.setMenu(mRoot.get());

    if (QDialog::Accepted == addDialog.exec())
    {
        slotUpdateMenu();
    }
}

void MainWindow::slotItemChanged()
{
    ui->savePushButton->setEnabled(true);
}

void MainWindow::slotSaveEditedItem()
{
    if(ui->menuEditorDelegate->slotSave())
    {
        if(ui->chooseMenuComboBox->checkDublicate(ui->menuEditorDelegate->getTempTitle()))
        {
            ui->savePushButton->setEnabled(false);
            slotUpdateMenu();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Menu item with the same name already exists.");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int retVal = msgBox.exec();
            switch (retVal) {
            case QMessageBox::Save:
                slotUpdateMenu();
                break;
            default:
                break;
            }
        }
    }
}

void MainWindow::slotDeleteItem()
{
    auto toDel = ui->chooseMenuComboBox->currentMenuItem();
    ui->chooseMenuComboBox->clearData();
    toDel->removeSubitem();
    ui->chooseMenuComboBox->updateComboBox();
    slotPrintMenu();
    ui->chooseMenuComboBox->updateComboBox();
    if(ui->chooseMenuComboBox->currentIndex() < 0)
    {
        ui->deletePushButton->setEnabled(false);
    }
}
