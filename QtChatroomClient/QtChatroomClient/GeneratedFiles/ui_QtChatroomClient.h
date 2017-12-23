/********************************************************************************
** Form generated from reading UI file 'QtChatroomClient.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCHATROOMCLIENT_H
#define UI_QTCHATROOMCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtChatroomClientClass
{
public:
    QFrame *line_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *chatListWidget;
    QTextEdit *inputTextEdit;
    QPushButton *pushButton;
    QListWidget *onlineListWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QDialog *QtChatroomClientClass)
    {
        if (QtChatroomClientClass->objectName().isEmpty())
            QtChatroomClientClass->setObjectName(QStringLiteral("QtChatroomClientClass"));
        QtChatroomClientClass->resize(636, 534);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtChatroomClientClass->sizePolicy().hasHeightForWidth());
        QtChatroomClientClass->setSizePolicy(sizePolicy);
        QtChatroomClientClass->setCursor(QCursor(Qt::ArrowCursor));
        line_2 = new QFrame(QtChatroomClientClass);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(370, 330, 3, 61));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        horizontalLayoutWidget = new QWidget(QtChatroomClientClass);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 638, 489));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        chatListWidget = new QListWidget(horizontalLayoutWidget);
        chatListWidget->setObjectName(QStringLiteral("chatListWidget"));

        verticalLayout->addWidget(chatListWidget);

        inputTextEdit = new QTextEdit(horizontalLayoutWidget);
        inputTextEdit->setObjectName(QStringLiteral("inputTextEdit"));
        inputTextEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inputTextEdit->sizePolicy().hasHeightForWidth());
        inputTextEdit->setSizePolicy(sizePolicy1);
        inputTextEdit->setMinimumSize(QSize(440, 100));
        inputTextEdit->setMaximumSize(QSize(440, 100));
        inputTextEdit->setMouseTracking(false);
        inputTextEdit->setOverwriteMode(false);

        verticalLayout->addWidget(inputTextEdit);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        onlineListWidget = new QListWidget(horizontalLayoutWidget);
        onlineListWidget->setObjectName(QStringLiteral("onlineListWidget"));

        horizontalLayout->addWidget(onlineListWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(QtChatroomClientClass);
        QObject::connect(pushButton, SIGNAL(clicked()), QtChatroomClientClass, SLOT(SendButton()));

        QMetaObject::connectSlotsByName(QtChatroomClientClass);
    } // setupUi

    void retranslateUi(QDialog *QtChatroomClientClass)
    {
        QtChatroomClientClass->setWindowTitle(QApplication::translate("QtChatroomClientClass", "Dialog", Q_NULLPTR));
        inputTextEdit->setHtml(QApplication::translate("QtChatroomClientClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QtChatroomClientClass", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtChatroomClientClass: public Ui_QtChatroomClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCHATROOMCLIENT_H
