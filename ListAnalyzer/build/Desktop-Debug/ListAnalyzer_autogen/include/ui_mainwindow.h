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
#include <QtWidgets/QTextBrowser>
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
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *filePathLbl;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QWidget *processingTab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QWidget *outputTab;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1270, 793);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        MainWindow->setWindowIcon(icon);
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
        label = new QLabel(mainTab);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(45);
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        filePathLbl = new QLabel(mainTab);
        filePathLbl->setObjectName("filePathLbl");
        filePathLbl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(filePathLbl, 3, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton = new QPushButton(mainTab);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 25));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #22282f; border-radius: 7px;"));

        gridLayout_2->addWidget(pushButton, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        tabWidget->addTab(mainTab, QString());
        processingTab = new QWidget();
        processingTab->setObjectName("processingTab");
        verticalLayout_2 = new QVBoxLayout(processingTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        comboBox = new QComboBox(processingTab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(200, 25));
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	selection-background-color: #5e5e5e;\n"
"	background-color: #22282f ;	\n"
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
"	selection-background-color: #5e5e5e;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"  border: 1px solid grey;\n"
"  background-color: #22282f ;\n"
"  selection-background-color: #5e5e5e;\n"
"}\n"
"\n"
"QComboBox QListView {\n"
"	background-color: lightgreen;\n"
"}"));
        comboBox->setFrame(false);
        comboBox->setModelColumn(0);

        gridLayout_3->addWidget(comboBox, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(processingTab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #22282f; border-radius: 7px;"));

        gridLayout_3->addWidget(pushButton_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        tabWidget->addTab(processingTab, QString());
        outputTab = new QWidget();
        outputTab->setObjectName("outputTab");
        verticalLayout_3 = new QVBoxLayout(outputTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(4);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(outputTab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(150, 25));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #22282f; border-radius: 7px;"));

        gridLayout_4->addWidget(pushButton_3, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(outputTab);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: #22282f;\n"
"color: #fff;\n"
"border: none;\n"
"border-radius: 15px;"));

        gridLayout_4->addWidget(textBrowser, 0, 0, 1, 3);


        verticalLayout_3->addLayout(gridLayout_4);

        tabWidget->addTab(outputTab, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ListProcessing", nullptr));
        filePathLbl->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mainTab), QCoreApplication::translate("MainWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\216", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \321\202\320\270\320\277\321\203", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));

        comboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(processingTab), QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(outputTab), QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
