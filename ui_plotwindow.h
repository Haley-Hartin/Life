/********************************************************************************
** Form generated from reading UI file 'plotwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWINDOW_H
#define UI_PLOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotWindow
{
public:
    QWidget *centralWidget;
    QSlider *horizontalSlider;
    QGraphicsView *graphicsView;
    QLabel *turn_label;
    QLabel *pop_label;
    QGraphicsView *grid;
    QPushButton *step_button;
    QPushButton *play_button;
    QPushButton *pause_button;
    QLabel *label;
    QLabel *label_2;
    QLabel *speed_label;
    QComboBox *comboBoxGraph;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menuPoint_Grapher;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlotWindow)
    {
        if (PlotWindow->objectName().isEmpty())
            PlotWindow->setObjectName(QString::fromUtf8("PlotWindow"));
        PlotWindow->resize(979, 782);
        centralWidget = new QWidget(PlotWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(590, 630, 281, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 490, 681, 121));
        turn_label = new QLabel(centralWidget);
        turn_label->setObjectName(QString::fromUtf8("turn_label"));
        turn_label->setGeometry(QRect(40, 30, 141, 16));
        pop_label = new QLabel(centralWidget);
        pop_label->setObjectName(QString::fromUtf8("pop_label"));
        pop_label->setGeometry(QRect(40, 60, 311, 16));
        grid = new QGraphicsView(centralWidget);
        grid->setObjectName(QString::fromUtf8("grid"));
        grid->setGeometry(QRect(30, 90, 681, 401));
        step_button = new QPushButton(centralWidget);
        step_button->setObjectName(QString::fromUtf8("step_button"));
        step_button->setGeometry(QRect(40, 630, 113, 32));
        play_button = new QPushButton(centralWidget);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        play_button->setGeometry(QRect(170, 630, 113, 32));
        pause_button = new QPushButton(centralWidget);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));
        pause_button->setGeometry(QRect(300, 630, 113, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 630, 59, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(890, 630, 59, 16));
        speed_label = new QLabel(centralWidget);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));
        speed_label->setGeometry(QRect(540, 670, 91, 16));
        comboBoxGraph = new QComboBox(centralWidget);
        comboBoxGraph->addItem(QString());
        comboBoxGraph->addItem(QString());
        comboBoxGraph->addItem(QString());
        comboBoxGraph->addItem(QString());
        comboBoxGraph->addItem(QString());
        comboBoxGraph->setObjectName(QString::fromUtf8("comboBoxGraph"));
        comboBoxGraph->setGeometry(QRect(170, 670, 141, 32));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 680, 141, 16));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(600, 20, 151, 32));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 30, 191, 16));
        PlotWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PlotWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 979, 22));
        menuPoint_Grapher = new QMenu(menuBar);
        menuPoint_Grapher->setObjectName(QString::fromUtf8("menuPoint_Grapher"));
        PlotWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlotWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PlotWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlotWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PlotWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPoint_Grapher->menuAction());

        retranslateUi(PlotWindow);

        QMetaObject::connectSlotsByName(PlotWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlotWindow)
    {
        PlotWindow->setWindowTitle(QApplication::translate("PlotWindow", "PlotWindow", nullptr));
        turn_label->setText(QApplication::translate("PlotWindow", "Turn: ", nullptr));
        pop_label->setText(QApplication::translate("PlotWindow", "Population:", nullptr));
        step_button->setText(QApplication::translate("PlotWindow", "Step", nullptr));
        play_button->setText(QApplication::translate("PlotWindow", "Play", nullptr));
        pause_button->setText(QApplication::translate("PlotWindow", "Pause", nullptr));
        label->setText(QApplication::translate("PlotWindow", "Slower", nullptr));
        label_2->setText(QApplication::translate("PlotWindow", "Faster", nullptr));
        speed_label->setText(QApplication::translate("PlotWindow", "Speed: 1", nullptr));
        comboBoxGraph->setItemText(0, QApplication::translate("PlotWindow", "Red", nullptr));
        comboBoxGraph->setItemText(1, QApplication::translate("PlotWindow", "White", nullptr));
        comboBoxGraph->setItemText(2, QApplication::translate("PlotWindow", "Blue", nullptr));
        comboBoxGraph->setItemText(3, QApplication::translate("PlotWindow", "Black", nullptr));
        comboBoxGraph->setItemText(4, QApplication::translate("PlotWindow", "Green", nullptr));

        label_3->setText(QApplication::translate("PlotWindow", "Graph bar color:", nullptr));
        comboBox->setItemText(0, QApplication::translate("PlotWindow", "Black", nullptr));
        comboBox->setItemText(1, QApplication::translate("PlotWindow", "Gray", nullptr));
        comboBox->setItemText(2, QApplication::translate("PlotWindow", "Yellow", nullptr));
        comboBox->setItemText(3, QApplication::translate("PlotWindow", "Green", nullptr));
        comboBox->setItemText(4, QApplication::translate("PlotWindow", "Blue", nullptr));

        label_4->setText(QApplication::translate("PlotWindow", "Immortal Cell Color:", nullptr));
        menuPoint_Grapher->setTitle(QApplication::translate("PlotWindow", "Point Grapher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotWindow: public Ui_PlotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWINDOW_H
