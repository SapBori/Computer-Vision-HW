/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *buttonOpen;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *buttonDeleteContents;
    QSpacerItem *horizontalSpacer;
    QToolButton *buttonShowList;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QPushButton *pushButton;
    QSpinBox *spinHue;
    QLabel *label;
    QDoubleSpinBox *spinSaturation;
    QLabel *label_2;
    QPushButton *ThresholdImage;
    QPushButton *Labeling;
    QPushButton *Erosion;
    QPushButton *Dilation;
    QPushButton *Erosion_2;
    QPushButton *Dilation_2;
    QWidget *tab_3;
    QPushButton *HistoGramMatching;
    QPushButton *HistoTransForm;
    QPushButton *GaussianNoise;
    QPushButton *Salt_Pepper;
    QPushButton *BoxFilter;
    QPushButton *GaussianFilter;
    QPushButton *MedianFilter;
    QDoubleSpinBox *Sigma;
    QSpinBox *nWindow;
    QSpinBox *nWindow_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *CannyEdge;
    QSpinBox *EdgeLow;
    QSpinBox *EdgeHigh;
    QDoubleSpinBox *EdgeSigma;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *tab_4;
    QPushButton *CoinCircle;
    QPushButton *GeneralHough;
    QWidget *tab;
    QWidget *tab_5;
    QListWidget *listWidget;

    void setupUi(QDialog *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName(QString::fromUtf8("MainFrame"));
        MainFrame->resize(622, 461);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainFrame->sizePolicy().hasHeightForWidth());
        MainFrame->setSizePolicy(sizePolicy);
        MainFrame->setMinimumSize(QSize(0, 461));
        MainFrame->setModal(false);
        verticalLayout = new QVBoxLayout(MainFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(MainFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 41));
        frame->setMaximumSize(QSize(16777215, 41));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QToolButton(frame);
        buttonOpen->setObjectName(QString::fromUtf8("buttonOpen"));
        buttonOpen->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonOpen->sizePolicy().hasHeightForWidth());
        buttonOpen->setSizePolicy(sizePolicy2);
        buttonOpen->setMinimumSize(QSize(41, 41));
        buttonOpen->setMaximumSize(QSize(41, 41));
        buttonOpen->setLayoutDirection(Qt::LeftToRight);
        buttonOpen->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOpen->setIcon(icon);
        buttonOpen->setIconSize(QSize(41, 41));
        buttonOpen->setCheckable(false);
        buttonOpen->setAutoRepeat(false);
        buttonOpen->setAutoExclusive(false);
        buttonOpen->setPopupMode(QToolButton::DelayedPopup);
        buttonOpen->setToolButtonStyle(Qt::ToolButtonIconOnly);
        buttonOpen->setAutoRaise(false);

        horizontalLayout_3->addWidget(buttonOpen);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setMinimumSize(QSize(41, 41));
        toolButton_2->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setMinimumSize(QSize(41, 41));
        toolButton_3->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_3);

        buttonDeleteContents = new QToolButton(frame);
        buttonDeleteContents->setObjectName(QString::fromUtf8("buttonDeleteContents"));
        sizePolicy2.setHeightForWidth(buttonDeleteContents->sizePolicy().hasHeightForWidth());
        buttonDeleteContents->setSizePolicy(sizePolicy2);
        buttonDeleteContents->setMinimumSize(QSize(41, 41));
        buttonDeleteContents->setMaximumSize(QSize(41, 41));
        buttonDeleteContents->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/1-21.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDeleteContents->setIcon(icon1);
        buttonDeleteContents->setIconSize(QSize(41, 41));

        horizontalLayout_3->addWidget(buttonDeleteContents);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonShowList = new QToolButton(frame);
        buttonShowList->setObjectName(QString::fromUtf8("buttonShowList"));
        sizePolicy2.setHeightForWidth(buttonShowList->sizePolicy().hasHeightForWidth());
        buttonShowList->setSizePolicy(sizePolicy2);
        buttonShowList->setMinimumSize(QSize(41, 41));
        buttonShowList->setMaximumSize(QSize(41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonShowList->setIcon(icon2);
        buttonShowList->setIconSize(QSize(82, 41));

        horizontalLayout_3->addWidget(buttonShowList);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, -1, -1, -1);
        tabWidget = new QTabWidget(MainFrame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(299, 394));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(255, 85, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush1);
        tabWidget->setPalette(palette);
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(31, 31));
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 20, 101, 41));
        spinHue = new QSpinBox(tab_2);
        spinHue->setObjectName(QString::fromUtf8("spinHue"));
        spinHue->setGeometry(QRect(60, 70, 61, 31));
        spinHue->setMaximum(360);
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 31, 20));
        spinSaturation = new QDoubleSpinBox(tab_2);
        spinSaturation->setObjectName(QString::fromUtf8("spinSaturation"));
        spinSaturation->setGeometry(QRect(60, 110, 61, 31));
        spinSaturation->setDecimals(3);
        spinSaturation->setMaximum(1.000000000000000);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 31, 20));
        ThresholdImage = new QPushButton(tab_2);
        ThresholdImage->setObjectName(QString::fromUtf8("ThresholdImage"));
        ThresholdImage->setGeometry(QRect(160, 20, 121, 41));
        Labeling = new QPushButton(tab_2);
        Labeling->setObjectName(QString::fromUtf8("Labeling"));
        Labeling->setGeometry(QRect(160, 100, 111, 41));
        Erosion = new QPushButton(tab_2);
        Erosion->setObjectName(QString::fromUtf8("Erosion"));
        Erosion->setGeometry(QRect(20, 190, 111, 41));
        Dilation = new QPushButton(tab_2);
        Dilation->setObjectName(QString::fromUtf8("Dilation"));
        Dilation->setGeometry(QRect(160, 190, 111, 41));
        Erosion_2 = new QPushButton(tab_2);
        Erosion_2->setObjectName(QString::fromUtf8("Erosion_2"));
        Erosion_2->setGeometry(QRect(20, 250, 111, 41));
        Dilation_2 = new QPushButton(tab_2);
        Dilation_2->setObjectName(QString::fromUtf8("Dilation_2"));
        Dilation_2->setGeometry(QRect(160, 250, 111, 41));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        HistoGramMatching = new QPushButton(tab_3);
        HistoGramMatching->setObjectName(QString::fromUtf8("HistoGramMatching"));
        HistoGramMatching->setGeometry(QRect(20, 60, 101, 41));
        HistoTransForm = new QPushButton(tab_3);
        HistoTransForm->setObjectName(QString::fromUtf8("HistoTransForm"));
        HistoTransForm->setGeometry(QRect(20, 10, 91, 41));
        GaussianNoise = new QPushButton(tab_3);
        GaussianNoise->setObjectName(QString::fromUtf8("GaussianNoise"));
        GaussianNoise->setGeometry(QRect(170, 10, 101, 41));
        Salt_Pepper = new QPushButton(tab_3);
        Salt_Pepper->setObjectName(QString::fromUtf8("Salt_Pepper"));
        Salt_Pepper->setGeometry(QRect(170, 60, 101, 41));
        BoxFilter = new QPushButton(tab_3);
        BoxFilter->setObjectName(QString::fromUtf8("BoxFilter"));
        BoxFilter->setGeometry(QRect(20, 110, 81, 41));
        GaussianFilter = new QPushButton(tab_3);
        GaussianFilter->setObjectName(QString::fromUtf8("GaussianFilter"));
        GaussianFilter->setGeometry(QRect(20, 210, 81, 41));
        MedianFilter = new QPushButton(tab_3);
        MedianFilter->setObjectName(QString::fromUtf8("MedianFilter"));
        MedianFilter->setGeometry(QRect(20, 160, 81, 41));
        Sigma = new QDoubleSpinBox(tab_3);
        Sigma->setObjectName(QString::fromUtf8("Sigma"));
        Sigma->setGeometry(QRect(110, 220, 62, 22));
        Sigma->setDecimals(3);
        Sigma->setMinimum(0.001000000000000);
        Sigma->setMaximum(5.000000000000000);
        Sigma->setSingleStep(0.001000000000000);
        Sigma->setValue(1.000000000000000);
        nWindow = new QSpinBox(tab_3);
        nWindow->setObjectName(QString::fromUtf8("nWindow"));
        nWindow->setGeometry(QRect(120, 170, 42, 22));
        nWindow->setMinimum(3);
        nWindow->setMaximum(33);
        nWindow_2 = new QSpinBox(tab_3);
        nWindow_2->setObjectName(QString::fromUtf8("nWindow_2"));
        nWindow_2->setGeometry(QRect(120, 130, 42, 22));
        nWindow_2->setMinimum(3);
        nWindow_2->setMaximum(33);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 110, 71, 21));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 200, 41, 21));
        CannyEdge = new QPushButton(tab_3);
        CannyEdge->setObjectName(QString::fromUtf8("CannyEdge"));
        CannyEdge->setGeometry(QRect(180, 130, 111, 51));
        EdgeLow = new QSpinBox(tab_3);
        EdgeLow->setObjectName(QString::fromUtf8("EdgeLow"));
        EdgeLow->setGeometry(QRect(240, 200, 42, 22));
        EdgeLow->setMaximum(255);
        EdgeHigh = new QSpinBox(tab_3);
        EdgeHigh->setObjectName(QString::fromUtf8("EdgeHigh"));
        EdgeHigh->setGeometry(QRect(240, 230, 42, 22));
        EdgeHigh->setMaximum(255);
        EdgeSigma = new QDoubleSpinBox(tab_3);
        EdgeSigma->setObjectName(QString::fromUtf8("EdgeSigma"));
        EdgeSigma->setGeometry(QRect(230, 260, 51, 22));
        EdgeSigma->setSingleStep(0.010000000000000);
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 200, 51, 21));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 230, 51, 21));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 260, 41, 21));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        CoinCircle = new QPushButton(tab_4);
        CoinCircle->setObjectName(QString::fromUtf8("CoinCircle"));
        CoinCircle->setGeometry(QRect(20, 20, 111, 51));
        GeneralHough = new QPushButton(tab_4);
        GeneralHough->setObjectName(QString::fromUtf8("GeneralHough"));
        GeneralHough->setGeometry(QRect(160, 20, 111, 51));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());

        horizontalLayout->addWidget(tabWidget);

        listWidget = new QListWidget(MainFrame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);
        listWidget->setMinimumSize(QSize(0, 394));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 0, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        QBrush brush6(QColor(120, 120, 120, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        QBrush brush7(QColor(240, 240, 240, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        listWidget->setPalette(palette1);
        QFont font;
        font.setPointSize(10);
        listWidget->setFont(font);

        horizontalLayout->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MainFrame);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QDialog *MainFrame)
    {
        MainFrame->setWindowTitle(QCoreApplication::translate("MainFrame", "Homeworks", nullptr));
#if QT_CONFIG(tooltip)
        buttonOpen->setToolTip(QCoreApplication::translate("MainFrame", "open an image file", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonOpen->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonDeleteContents->setToolTip(QCoreApplication::translate("MainFrame", "close all forms", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonDeleteContents->setText(QString());
#if QT_CONFIG(tooltip)
        buttonShowList->setToolTip(QCoreApplication::translate("MainFrame", "show the list view", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonShowList->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainFrame", "Sepia Tone", nullptr));
        label->setText(QCoreApplication::translate("MainFrame", "Hue", nullptr));
        label_2->setText(QCoreApplication::translate("MainFrame", "Sat", nullptr));
        ThresholdImage->setText(QCoreApplication::translate("MainFrame", "Thresholding", nullptr));
        Labeling->setText(QCoreApplication::translate("MainFrame", "Labeling", nullptr));
        Erosion->setText(QCoreApplication::translate("MainFrame", "Erode 3x3", nullptr));
        Dilation->setText(QCoreApplication::translate("MainFrame", "Dilation 3x3", nullptr));
        Erosion_2->setText(QCoreApplication::translate("MainFrame", "Erode 5x5", nullptr));
        Dilation_2->setText(QCoreApplication::translate("MainFrame", "Dilation 5x5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainFrame", "1", nullptr));
        HistoGramMatching->setText(QCoreApplication::translate("MainFrame", "HistoMatching", nullptr));
        HistoTransForm->setText(QCoreApplication::translate("MainFrame", "HistoEqual", nullptr));
        GaussianNoise->setText(QCoreApplication::translate("MainFrame", "Gaussian Noise", nullptr));
        Salt_Pepper->setText(QCoreApplication::translate("MainFrame", "Salt-Pepper", nullptr));
        BoxFilter->setText(QCoreApplication::translate("MainFrame", "Box", nullptr));
        GaussianFilter->setText(QCoreApplication::translate("MainFrame", "Gaussian", nullptr));
        MedianFilter->setText(QCoreApplication::translate("MainFrame", "Median", nullptr));
        label_3->setText(QCoreApplication::translate("MainFrame", "Kernel Size", nullptr));
        label_4->setText(QCoreApplication::translate("MainFrame", "Sigma", nullptr));
        CannyEdge->setText(QCoreApplication::translate("MainFrame", "Canny Edge", nullptr));
        label_5->setText(QCoreApplication::translate("MainFrame", "Low Th", nullptr));
        label_6->setText(QCoreApplication::translate("MainFrame", "High Th", nullptr));
        label_7->setText(QCoreApplication::translate("MainFrame", "Sigma", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainFrame", "2", nullptr));
        CoinCircle->setText(QCoreApplication::translate("MainFrame", "Coin Circle", nullptr));
        GeneralHough->setText(QCoreApplication::translate("MainFrame", "Target Get", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainFrame", "3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainFrame", "4", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainFrame", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
