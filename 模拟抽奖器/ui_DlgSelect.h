/********************************************************************************
** Form generated from reading UI file 'DlgSelect.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSELECT_H
#define UI_DLGSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DlgSelect
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *m_ctlDisplay;
    QToolButton *m_btnStart;
    QListWidget *m_lstResult;

    void setupUi(QDialog *DlgSelect)
    {
        if (DlgSelect->objectName().isEmpty())
            DlgSelect->setObjectName(QStringLiteral("DlgSelect"));
        DlgSelect->resize(486, 128);
        horizontalLayout = new QHBoxLayout(DlgSelect);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_ctlDisplay = new QLabel(DlgSelect);
        m_ctlDisplay->setObjectName(QStringLiteral("m_ctlDisplay"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(36);
        font.setBold(false);
        font.setWeight(50);
        m_ctlDisplay->setFont(font);
        m_ctlDisplay->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 85, 0);"));

        horizontalLayout->addWidget(m_ctlDisplay);

        m_btnStart = new QToolButton(DlgSelect);
        m_btnStart->setObjectName(QStringLiteral("m_btnStart"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_btnStart->sizePolicy().hasHeightForWidth());
        m_btnStart->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resouces/Resources/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_btnStart->setIcon(icon);
        m_btnStart->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(m_btnStart);

        m_lstResult = new QListWidget(DlgSelect);
        m_lstResult->setObjectName(QStringLiteral("m_lstResult"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_lstResult->sizePolicy().hasHeightForWidth());
        m_lstResult->setSizePolicy(sizePolicy1);
        m_lstResult->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(m_lstResult);


        retranslateUi(DlgSelect);

        QMetaObject::connectSlotsByName(DlgSelect);
    } // setupUi

    void retranslateUi(QDialog *DlgSelect)
    {
        DlgSelect->setWindowTitle(QApplication::translate("DlgSelect", "\346\212\275\345\245\226", 0));
        m_ctlDisplay->setText(QApplication::translate("DlgSelect", "18600000000", 0));
        m_btnStart->setText(QApplication::translate("DlgSelect", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class DlgSelect: public Ui_DlgSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSELECT_H
