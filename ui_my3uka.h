/********************************************************************************
** Form generated from reading ui file 'my3uka.ui'
**
** Created: Fri Jun 26 13:11:18 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MY3UKA_H
#define UI_MY3UKA_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my3ukaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lblFolder;
    QComboBox *cmbFolder;
    QPushButton *btnBrowseFolder;
    QLabel *lblFile;
    QLineEdit *txtFile;
    QPushButton *btnBrowseFile;
    QPushButton *btnGenerate;
    QPushButton *btnGenerateAll;
    QProgressBar *progressBar;

    void setupUi(QDialog *my3ukaClass)
    {
        if (my3ukaClass->objectName().isEmpty())
            my3ukaClass->setObjectName(QString::fromUtf8("my3ukaClass"));
        my3ukaClass->setEnabled(true);
        my3ukaClass->resize(429, 121);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(my3ukaClass->sizePolicy().hasHeightForWidth());
        my3ukaClass->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/icon/my3uka.png")), QIcon::Normal, QIcon::Off);
        my3ukaClass->setWindowIcon(icon);
        my3ukaClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        my3ukaClass->setSizeGripEnabled(false);
        layoutWidget = new QWidget(my3ukaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, 13, 420, 98));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblFolder = new QLabel(layoutWidget);
        lblFolder->setObjectName(QString::fromUtf8("lblFolder"));

        gridLayout->addWidget(lblFolder, 0, 0, 1, 2);

        cmbFolder = new QComboBox(layoutWidget);
        cmbFolder->setObjectName(QString::fromUtf8("cmbFolder"));
        cmbFolder->setEditable(false);
        cmbFolder->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);

        gridLayout->addWidget(cmbFolder, 0, 2, 1, 2);

        btnBrowseFolder = new QPushButton(layoutWidget);
        btnBrowseFolder->setObjectName(QString::fromUtf8("btnBrowseFolder"));

        gridLayout->addWidget(btnBrowseFolder, 0, 4, 1, 1);

        lblFile = new QLabel(layoutWidget);
        lblFile->setObjectName(QString::fromUtf8("lblFile"));

        gridLayout->addWidget(lblFile, 1, 0, 1, 2);

        txtFile = new QLineEdit(layoutWidget);
        txtFile->setObjectName(QString::fromUtf8("txtFile"));

        gridLayout->addWidget(txtFile, 1, 2, 1, 2);

        btnBrowseFile = new QPushButton(layoutWidget);
        btnBrowseFile->setObjectName(QString::fromUtf8("btnBrowseFile"));

        gridLayout->addWidget(btnBrowseFile, 1, 4, 1, 1);

        btnGenerate = new QPushButton(layoutWidget);
        btnGenerate->setObjectName(QString::fromUtf8("btnGenerate"));

        gridLayout->addWidget(btnGenerate, 2, 0, 1, 1);

        btnGenerateAll = new QPushButton(layoutWidget);
        btnGenerateAll->setObjectName(QString::fromUtf8("btnGenerateAll"));

        gridLayout->addWidget(btnGenerateAll, 2, 1, 1, 2);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);

        gridLayout->addWidget(progressBar, 2, 3, 1, 2);

        QWidget::setTabOrder(cmbFolder, btnBrowseFolder);
        QWidget::setTabOrder(btnBrowseFolder, txtFile);
        QWidget::setTabOrder(txtFile, btnBrowseFile);
        QWidget::setTabOrder(btnBrowseFile, btnGenerate);
        QWidget::setTabOrder(btnGenerate, btnGenerateAll);

        retranslateUi(my3ukaClass);

        QMetaObject::connectSlotsByName(my3ukaClass);
    } // setupUi

    void retranslateUi(QDialog *my3ukaClass)
    {
        my3ukaClass->setWindowTitle(QApplication::translate("my3ukaClass", "my3uka", 0, QApplication::UnicodeUTF8));
        lblFolder->setText(QApplication::translate("my3ukaClass", "Collection Folder", 0, QApplication::UnicodeUTF8));
        btnBrowseFolder->setText(QApplication::translate("my3ukaClass", "Find Music Collection", 0, QApplication::UnicodeUTF8));
        lblFile->setText(QApplication::translate("my3ukaClass", "Save File", 0, QApplication::UnicodeUTF8));
        btnBrowseFile->setText(QApplication::translate("my3ukaClass", "Find File", 0, QApplication::UnicodeUTF8));
        btnGenerate->setText(QApplication::translate("my3ukaClass", "Generate", 0, QApplication::UnicodeUTF8));
        btnGenerateAll->setText(QApplication::translate("my3ukaClass", "Generate All", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(my3ukaClass);
    } // retranslateUi

};

namespace Ui {
    class my3ukaClass: public Ui_my3ukaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY3UKA_H
