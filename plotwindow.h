/*!
This file contains definitions of the plotwindow class.
*/

#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cell.h>
#include <grid.h>
#include <bars.h>
#include <QTimer>
#include <QColor>

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();

    //methods for updating UI
    void updateLabels();
    void addBar();
    void updateGraph();

private slots:

    //methods for UI features
    void on_step_button_clicked();

    void on_play_button_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pause_button_clicked();


    //methods for extra feautures implementations
    void on_comboBoxGraph_currentTextChanged(const QString &arg1);
    void on_comboBox_currentTextChanged(const QString &arg1);

private:

    Ui::PlotWindow *ui;
    Grid *grid_;
    QGraphicsScene *graph_scene;
    QGraphicsScene *grid_scene;

    QTimer *timer_ = nullptr;
    QColor *bar_color = new QColor(255,0,0);
    QColor *cell_color = new QColor(0,0,0);

    int turn_ = 1;
    int speed_ = 0;
    bool pause_clicked_ = false;

    QList<Bars*> bars; //bars to plot



};

#endif // PLOTWINDOW_H
