/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    myLabel *imageLabel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *zoomLabel;
    QSlider *zoomSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *brightnessLabel;
    QSlider *brightnessSlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *contrastLabel;
    QSlider *contrastSlider;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *openPushbutton;
    QPushButton *measurePushbutton;
    QPushButton *clearPushbutton;
    QPushButton *sharpenPushButton;
    QVBoxLayout *verticalLayout;
    QPushButton *displayhaloButton;
    QPushButton *line_displayButton;
    QPushButton *displayallButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *instructimgLabel;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_6;
    QLabel *instructLabel;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_3;
    QSpacerItem *verticalSpacer_3;
    QTableWidget *tableWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1545, 982);
        QIcon icon;
        icon.addFile(QStringLiteral("image/icon/iMQ.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1094, 940));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral(""));
        horizontalLayout_8 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        imageLabel = new myLabel(scrollAreaWidgetContents);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setMinimumSize(QSize(100, 100));
        imageLabel->setMaximumSize(QSize(16777215, 16777215));
        imageLabel->setBaseSize(QSize(480, 240));
        imageLabel->setCursor(QCursor(Qt::ArrowCursor));
        imageLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(imageLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_8->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_6->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(425, 0));
        scrollArea_2->setMaximumSize(QSize(400, 16777215));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 423, 940));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        zoomLabel = new QLabel(scrollAreaWidgetContents_2);
        zoomLabel->setObjectName(QStringLiteral("zoomLabel"));

        horizontalLayout_5->addWidget(zoomLabel);

        zoomSlider = new QSlider(scrollAreaWidgetContents_2);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        zoomSlider->setMinimum(20);
        zoomSlider->setMaximum(180);
        zoomSlider->setSingleStep(5);
        zoomSlider->setValue(100);
        zoomSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(zoomSlider);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        brightnessLabel = new QLabel(scrollAreaWidgetContents_2);
        brightnessLabel->setObjectName(QStringLiteral("brightnessLabel"));

        horizontalLayout_3->addWidget(brightnessLabel);

        brightnessSlider = new QSlider(scrollAreaWidgetContents_2);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setMinimum(-100);
        brightnessSlider->setMaximum(100);
        brightnessSlider->setSingleStep(20);
        brightnessSlider->setValue(0);
        brightnessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(brightnessSlider);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        contrastLabel = new QLabel(scrollAreaWidgetContents_2);
        contrastLabel->setObjectName(QStringLiteral("contrastLabel"));

        horizontalLayout_4->addWidget(contrastLabel);

        contrastSlider = new QSlider(scrollAreaWidgetContents_2);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setMinimum(-127);
        contrastSlider->setMaximum(128);
        contrastSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(contrastSlider);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        openPushbutton = new QPushButton(scrollAreaWidgetContents_2);
        openPushbutton->setObjectName(QStringLiteral("openPushbutton"));

        verticalLayout_6->addWidget(openPushbutton);

        measurePushbutton = new QPushButton(scrollAreaWidgetContents_2);
        measurePushbutton->setObjectName(QStringLiteral("measurePushbutton"));

        verticalLayout_6->addWidget(measurePushbutton);

        clearPushbutton = new QPushButton(scrollAreaWidgetContents_2);
        clearPushbutton->setObjectName(QStringLiteral("clearPushbutton"));

        verticalLayout_6->addWidget(clearPushbutton);

        sharpenPushButton = new QPushButton(scrollAreaWidgetContents_2);
        sharpenPushButton->setObjectName(QStringLiteral("sharpenPushButton"));

        verticalLayout_6->addWidget(sharpenPushButton);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        displayhaloButton = new QPushButton(scrollAreaWidgetContents_2);
        displayhaloButton->setObjectName(QStringLiteral("displayhaloButton"));

        verticalLayout->addWidget(displayhaloButton);

        line_displayButton = new QPushButton(scrollAreaWidgetContents_2);
        line_displayButton->setObjectName(QStringLiteral("line_displayButton"));

        verticalLayout->addWidget(line_displayButton);

        displayallButton = new QPushButton(scrollAreaWidgetContents_2);
        displayallButton->setObjectName(QStringLiteral("displayallButton"));

        verticalLayout->addWidget(displayallButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        widget = new QWidget(scrollAreaWidgetContents_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 5));
        widget->setMaximumSize(QSize(16777215, 5));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(17, 255, 248);"));

        verticalLayout_3->addWidget(widget);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        instructimgLabel = new QLabel(scrollAreaWidgetContents_2);
        instructimgLabel->setObjectName(QStringLiteral("instructimgLabel"));
        instructimgLabel->setMinimumSize(QSize(250, 250));
        instructimgLabel->setMaximumSize(QSize(250, 250));

        horizontalLayout_7->addWidget(instructimgLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        instructLabel = new QLabel(scrollAreaWidgetContents_2);
        instructLabel->setObjectName(QStringLiteral("instructLabel"));
        instructLabel->setMaximumSize(QSize(16777215, 30));
        instructLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_9->addWidget(instructLabel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_9);

        widget_3 = new QWidget(scrollAreaWidgetContents_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 5));
        widget_3->setMaximumSize(QSize(16777215, 5));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(17, 255, 248);"));

        verticalLayout_3->addWidget(widget_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        tableWidget = new QTableWidget(scrollAreaWidgetContents_2);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(255, 255, 255));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 1, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 2, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 3, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 2, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 3, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 2, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 3, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 3, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 1, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 2, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 3, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 0, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 1, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 2, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 3, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 1, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 2, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 3, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 0, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 1, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 2, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 3, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 0, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 1, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 2, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 3, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 0, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 1, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 2, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 3, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 0, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 1, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 2, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 3, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        __qtablewidgetitem75->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 0, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        __qtablewidgetitem76->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 1, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 2, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 3, __qtablewidgetitem78);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(398, 471));
        tableWidget->setMaximumSize(QSize(400, 471));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setTextElideMode(Qt::ElideLeft);
        tableWidget->setShowGrid(true);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tableWidget);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_6->addWidget(scrollArea_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        imageLabel->setText(QString());
        zoomLabel->setText(QApplication::translate("MainWindow", "\347\274\251\346\224\276  ", 0));
        brightnessLabel->setText(QApplication::translate("MainWindow", "\344\272\256\345\272\246  ", 0));
        contrastLabel->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\345\272\246", 0));
        openPushbutton->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", 0));
        measurePushbutton->setText(QApplication::translate("MainWindow", "\346\265\213\351\207\217", 0));
        clearPushbutton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        sharpenPushButton->setText(QApplication::translate("MainWindow", "\351\224\220\345\214\226", 0));
        displayhaloButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\216\257", 0));
        line_displayButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\272\277", 0));
        displayallButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\205\250\351\203\250", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\232\202\345\256\232", 0));
        instructimgLabel->setText(QString());
        instructLabel->setText(QApplication::translate("MainWindow", "\347\202\271", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\345\217\202\350\200\203\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\265\213\351\207\217\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "6", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "7", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "8", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "9", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "10", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "11", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "12", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "13", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "14", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "15", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(0, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "SNA\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(0, 1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "82.8\302\2614.0\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(1, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "SNB\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(1, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "80.1\302\2613.9\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "ANB\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(2, 1);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "2.7\302\2612.0\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "NP-FH\351\235\242\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 1);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "85.4\302\2613.7\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(4, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Y\350\275\264\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(4, 1);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "66.3\302\2617.1\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(5, 0);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "MP-FH\351\242\214\345\271\263\351\235\242\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(5, 1);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "31.1\302\2615.6\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(6, 0);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "NA-PA\351\242\214\345\207\270\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(6, 1);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "6.0\302\2614.4\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(7, 0);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "\344\270\2121-SN\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(7, 1);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "105.7\302\2616.3\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(8, 0);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "\344\270\2121-NA\350\267\235", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(8, 1);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "5.1\302\2612.4mm", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(9, 0);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "\344\270\2121-NA\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(9, 1);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "22.8\302\2615.7\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(10, 0);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "\344\270\2131-MP\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(10, 1);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "93.9\302\2616.2\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(11, 0);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "\344\270\2131-NB\350\267\235", 0));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(11, 1);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "6.7\302\2612.1mm", 0));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(12, 0);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "\344\270\2131-NB\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(12, 1);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "30.5\302\2615.8\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(13, 0);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "\344\270\2121-\344\270\2131\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(13, 1);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "124.2\302\2618.2\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(14, 0);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "NLA\350\247\222", 0));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(14, 1);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "95\302\26115.0\302\260", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
