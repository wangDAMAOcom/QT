/********************************************************************************
** Form generated from reading UI file 'ProgressDialg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALG_H
#define UI_PROGRESSDIALG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialg
{
public:
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;

    void setupUi(QDialog *ProgressDialg)
    {
        if (ProgressDialg->objectName().isEmpty())
            ProgressDialg->setObjectName(QStringLiteral("ProgressDialg"));
        ProgressDialg->resize(400, 46);
        horizontalLayout = new QHBoxLayout(ProgressDialg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 6, -1, 6);
        progressBar = new QProgressBar(ProgressDialg);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        retranslateUi(ProgressDialg);

        QMetaObject::connectSlotsByName(ProgressDialg);
    } // setupUi

    void retranslateUi(QDialog *ProgressDialg)
    {
        ProgressDialg->setWindowTitle(QApplication::translate("ProgressDialg", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgressDialg: public Ui_ProgressDialg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALG_H
