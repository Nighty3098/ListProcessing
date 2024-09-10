/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *mainTab;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *openFileBtn;
    QLabel *filePathLbl;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *processingTab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1270, 793);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #0d1117; color: #ffffff; border: none; border-radius: 15px;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar { alignment: center; }\n"
"\n"
"QTabWidet {\n"
"	background-color: #0d1117;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 0px solid lightgray;\n"
"    border-radius: 10px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"	width: 100px;\n"
"	height: 25px;\n"
"	margin: 4px;\n"
"	border: none;\n"
"	background: transparent	;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: #22282f;\n"
"	color: #fff;\n"
"	border-radius: 5px;\n"
"	width: 100px;\n"
"	height: 25px;\n"
"	margin: 4px;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        mainTab = new QWidget();
        mainTab->setObjectName("mainTab");
        verticalLayout = new QVBoxLayout(mainTab);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        openFileBtn = new QPushButton(mainTab);
        openFileBtn->setObjectName("openFileBtn");
        openFileBtn->setMinimumSize(QSize(100, 100));
        openFileBtn->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        openFileBtn->setStyleSheet(QString::fromUtf8("background-color: transparent; color: #fff; border: none; border-radius: 10px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/folder.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openFileBtn->setIcon(icon);
        openFileBtn->setIconSize(QSize(70, 70));
        openFileBtn->setFlat(true);

        gridLayout_2->addWidget(openFileBtn, 1, 1, 1, 1);

        filePathLbl = new QLabel(mainTab);
        filePathLbl->setObjectName("filePathLbl");
        filePathLbl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(filePathLbl, 2, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        tabWidget->addTab(mainTab, QString());
        processingTab = new QWidget();
        processingTab->setObjectName("processingTab");
        verticalLayout_2 = new QVBoxLayout(processingTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        comboBox = new QComboBox(processingTab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 25));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	background-color: #22282f;\n"
"	border-radius: 7px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"  border: 1px solid grey;\n"
"  background: #22282f ;\n"
"  selection-background-color: blue;\n"
"}"));

        gridLayout_3->addWidget(comboBox, 3, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(processingTab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #22282f; border-radius: 7px;"));

        gridLayout_3->addWidget(pushButton_2, 4, 3, 1, 1);

        pushButton = new QPushButton(processingTab);
        pushButton->setObjectName("pushButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/document.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(120, 120));

        gridLayout_3->addWidget(pushButton, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 5, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        tabWidget->addTab(processingTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        openFileBtn->setToolTip(QCoreApplication::translate("MainWindow", "Open file", nullptr));
#endif // QT_CONFIG(tooltip)
        openFileBtn->setText(QString());
#if QT_CONFIG(shortcut)
        openFileBtn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        filePathLbl->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(mainTab), QCoreApplication::translate("MainWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\216", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \321\202\320\270\320\277\321\203", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));

        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214", nullptr));
        pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(processingTab), QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
