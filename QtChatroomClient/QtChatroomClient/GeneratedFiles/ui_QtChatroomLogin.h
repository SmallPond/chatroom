/********************************************************************************
** Form generated from reading UI file 'QtChatroomLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCHATROOMLOGIN_H
#define UI_QTCHATROOMLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtChatroomLoginClass
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *userLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passLabel;
    QLineEdit *passLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginPushButton;
    QPushButton *regPushButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtChatroomLoginClass)
    {
        if (QtChatroomLoginClass->objectName().isEmpty())
            QtChatroomLoginClass->setObjectName(QStringLiteral("QtChatroomLoginClass"));
        QtChatroomLoginClass->resize(386, 227);
        centralWidget = new QWidget(QtChatroomLoginClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(100, 30, 181, 103));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        horizontalLayout->addWidget(nameLabel);

        userLineEdit = new QLineEdit(formLayoutWidget);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));

        horizontalLayout->addWidget(userLineEdit);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        passLabel = new QLabel(formLayoutWidget);
        passLabel->setObjectName(QStringLiteral("passLabel"));

        horizontalLayout_2->addWidget(passLabel);

        passLineEdit = new QLineEdit(formLayoutWidget);
        passLineEdit->setObjectName(QStringLiteral("passLineEdit"));
        passLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passLineEdit);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        loginPushButton = new QPushButton(formLayoutWidget);
        loginPushButton->setObjectName(QStringLiteral("loginPushButton"));

        horizontalLayout_3->addWidget(loginPushButton);

        regPushButton = new QPushButton(formLayoutWidget);
        regPushButton->setObjectName(QStringLiteral("regPushButton"));

        horizontalLayout_3->addWidget(regPushButton);


        formLayout->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::SpanningRole, verticalSpacer);

        QtChatroomLoginClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtChatroomLoginClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 386, 23));
        QtChatroomLoginClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtChatroomLoginClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtChatroomLoginClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtChatroomLoginClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtChatroomLoginClass->setStatusBar(statusBar);

        retranslateUi(QtChatroomLoginClass);
        QObject::connect(loginPushButton, SIGNAL(clicked()), QtChatroomLoginClass, SLOT(Login()));
        QObject::connect(regPushButton, SIGNAL(clicked()), QtChatroomLoginClass, SLOT(OnRegister()));

        QMetaObject::connectSlotsByName(QtChatroomLoginClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtChatroomLoginClass)
    {
        QtChatroomLoginClass->setWindowTitle(QApplication::translate("QtChatroomLoginClass", "QtChatroomClient", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("QtChatroomLoginClass", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        passLabel->setText(QApplication::translate("QtChatroomLoginClass", "\345\257\206  \347\240\201", Q_NULLPTR));
        loginPushButton->setText(QApplication::translate("QtChatroomLoginClass", "Login", Q_NULLPTR));
        regPushButton->setText(QApplication::translate("QtChatroomLoginClass", "register", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtChatroomLoginClass: public Ui_QtChatroomLoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCHATROOMLOGIN_H
