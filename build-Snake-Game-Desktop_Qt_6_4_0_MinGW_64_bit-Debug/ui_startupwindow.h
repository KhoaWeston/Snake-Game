/********************************************************************************
** Form generated from reading UI file 'startupwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUPWINDOW_H
#define UI_STARTUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_StartupWindow
{
public:

    void setupUi(QDialog *StartupWindow)
    {
        if (StartupWindow->objectName().isEmpty())
            StartupWindow->setObjectName("StartupWindow");
        StartupWindow->resize(800, 600);

        retranslateUi(StartupWindow);

        QMetaObject::connectSlotsByName(StartupWindow);
    } // setupUi

    void retranslateUi(QDialog *StartupWindow)
    {
        StartupWindow->setWindowTitle(QCoreApplication::translate("StartupWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartupWindow: public Ui_StartupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUPWINDOW_H
