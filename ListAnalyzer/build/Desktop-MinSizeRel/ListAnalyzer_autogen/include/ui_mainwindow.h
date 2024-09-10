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
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1270, 793);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #242424; color: #ffffff; border: none; border-radius: 15px;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
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
        label = new QLabel(processingTab);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/document.svg")));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


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
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(processingTab), QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
