/*!
This file contains implementations of the plotwindow class.
*/
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <bars.h>
#include <cell.h>
#include <grid.h>
#include <vector>
#include <QVector>
#include <cmath>
#include <QComboBox>
#include <QHBoxLayout>

#include "plotwindow.h"
#include "ui_plotwindow.h"

// Name: Haley Hartin

/*!
  \fn PlotWindow::PlotWindow(QWidget *parent)

    Constructor. Initializes the Plot Window. Creates a scene for the grid and graph.
    Sets the sizes of the each scene.
    Creates cells and adds them to the grid scene.
    Passes the cells to an instance of the grid class.
*/
PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    ui->setupUi(this);
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));
    qDebug()<<"working";
    //declare scenes
    graph_scene = new QGraphicsScene;
    grid_scene = new QGraphicsScene;
    QGraphicsView * grid = ui->grid;
    QGraphicsView * graph = ui->graphicsView;

    //set features and size for graph ui
    graph->setMinimumWidth(1350);
    graph->setMaximumWidth(1350);
    graph->setMaximumHeight(100);
    graph->setMinimumHeight(100);

    int graph_y_mid = graph->frameSize().width() / 2;
    QGraphicsItem  *yline =graph_scene->addLine(graph_y_mid, 0, graph_y_mid, graph->frameSize().height());
    yline->setVisible(false);
    graph->setScene(graph_scene);
    graph->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    //set features and size for grid ui
    int x_mid = grid->frameSize().height() / 2;
    int y_mid = grid->frameSize().width() / 2;

    QGraphicsItem  *grid_linex = grid_scene->addLine(0, x_mid, grid->frameSize().width(), x_mid);
    QGraphicsItem  *grid_line= grid_scene->addLine(y_mid, 0, y_mid, grid->frameSize().height());
    grid->setMinimumWidth(1350);
    grid->setMaximumWidth(1350);
    grid->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    grid->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    grid->setScene(grid_scene);
    grid_line->setVisible(false);
    grid_linex->setVisible(false);

    //create cells to fill the grid
    int rand_num;
    int width = 0;
    int height = 0;
    grid_ = new Grid(10,20);
    Cell *c;
    for(int i=0; i<10; i++){
        for(int j =0; j<20; j++){
            //50-50 chance of being alive
            rand_num = rand() % 2 + 1;
            if(rand_num==1){
                c = new Cell(Qt::magenta, width, height);
                c->setStatus(false);
            }
            else{
                c = new Cell(Qt::white, width, height);
                c->setStatus(true);
            }

            grid_scene->addItem(c);
            grid_->addCell(c, width, height); //pass the cell to grid class
            width += 67;
        }
        width = 0;
        height+=35;
    }

    //initialize graph and labels for first turn
    addBar();
    updateLabels();
//    QLabel *label = new QLabel(this);
//    QPixmap qpx;
//    string str =
//    qpx = QPixmap(str.c_str());
//    label->setPixmap(qpx);


    QString filename = ":/snowball.jpeg";
    QLabel* label = new QLabel(this);
    /** set content to show center in label */
    label->setAlignment(Qt::AlignCenter);
    QPixmap pix;

    /** to check wether load ok */
    if(pix.load(filename)){
        /** scale pixmap to fit in label'size and keep ratio of pixmap */
        pix = pix.scaled(label->size(),Qt::KeepAspectRatio);
        label->setPixmap(pix);
        qDebug()<<"loaded";
    }

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    setLayout(layout);


}

/*!
  \fn PlotWindow::updateLabels()

    Updates the turn and population labels on ther ui.
    Calculates the population based on number of cells alive
    and the total population.
*/
void PlotWindow::updateLabels(){
        //update turn
        std::string s = "Turn: " + std::to_string(turn_);
        QString qs(s.c_str());
        ui->turn_label->setText(qs);

        //update population
        int live_cells = grid_->get_population();
        int percentage = floor((float(live_cells)/float(200.0)*100));
        std::string pop = "Population: " + std::to_string(live_cells) + " (" + std::to_string(percentage) + "%)";
        QString ps(pop.c_str());
        ui->pop_label->setText(ps);
}


/*!
  \fn PlotWindow::updateGraph()

    Updates the list of bars to plot on the graph if the graph UI is full.
    Deltes the first bar in the bars vector.
    Update the new positions of the remaining bars.
*/
void PlotWindow::updateGraph(){
    QList<Bars*> temp = {};
    int first = 0;
    foreach(Bars* item, bars){
        //move all the bars left one
        if(first != 0){
           item->set_x(item->get_x()-20);
           item->set_y(item->get_y());
           temp.append(item);

        }
        //delete the first bar
        graph_scene->removeItem(item);
        first +=1;

    }
    update();
    bars = temp;
}

/*!
  \fn PlotWindow::addBar()

    Adds a bar to the graph UI.
    Checks if the graph UI is full.
    Calculates the new bars height and adds it to the graph scene.
*/
void PlotWindow::addBar(){

    //check if scene is full;
    if(bars.size()==67){
        updateGraph();
    }

    //calulate positions of new bar
    int height = grid_->get_population();
    int percentage = (float(height)/float(200.0))*100;
    int new_y = 100 - percentage;
    int new_x = -1350/2 + (bars.size()+1)*20;

    //create new bar
    Bars * bar = new Bars(*(bar_color), new_x, new_y,percentage-1);
    bars.append(bar);

    //plot all the bars
    foreach(Bars* item, bars){
        graph_scene->addItem(item);
    }
}


/*!
  \fn PlotWindow::on_step_button_clicked()

    Responds to the step button being clicked.
    Increaes turn count.
    Calls the appropriate function to make a turn.
*/
void PlotWindow::on_step_button_clicked()
{
    grid_->TakeTurn();
    turn_ += 1;
    addBar();
    updateLabels();
}

/*!
  \fn PlotWindow::on_play_button_clicked()

    Responds to the play button being clicked.
    Checks if the game needs to be restarted.
    Sets and starts a timer to call on_step_button_clicked() each interval
*/
void PlotWindow::on_play_button_clicked()
{
    //check if the game needs to be restarted
    if(pause_clicked_){
        QApplication::exit(1000);
    }
    //create a timer
    else if(timer_==nullptr){
        timer_ = new QTimer(this);
        connect(timer_, &QTimer::timeout, this, &PlotWindow::on_step_button_clicked);
        float interval = 1000.00 *(1/(float(speed_)+1));
        timer_->setInterval(interval);
        timer_->start();
    }
}


/*!
  \fn PlotWindow::on_horizontalSlider_valueChanged(int value)

    Responds to the slider being changed.
    Updates the speed label with the new speed.
    Calculates and sets the new timer interval speed.
*/
void PlotWindow::on_horizontalSlider_valueChanged(int value)
{
    //update label
    speed_ = value + 1;
    std::string speed = "Speed: " + std::to_string(speed_);
    QString ss(speed.c_str());
    ui->speed_label->setText(ss);

    //calculate new interval
    if(timer_ != nullptr){
        float interval = 1000.00 *(1/(float(speed_)+1));
        timer_->setInterval(interval);
        timer_->start();
    }

}

/*!
  \fn PlotWindow::on_pause_button_clicked()

    Responds to the pause button being clicked.
    Stops the timer.
    changes the puse_clicked value to true,
    so the game is restarted if the play button is clicked.
*/
void PlotWindow::on_pause_button_clicked()
{
    timer_->stop();
    timer_=nullptr;
    pause_clicked_ = true;
}


/*!
  \fn PlotWindow::on_comboBoxGraph_currentTextChanged(const QString &arg1)

    Responds to the drop down menu to change the bar color in the graph.
    Gets the new bar color.
    Updates all the bars in the graph scene to the new color.
*/
void PlotWindow::on_comboBoxGraph_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Black"){
        bar_color = new QColor(Qt::black);
    }
    else if(arg1 == "Red"){
        bar_color = new QColor(Qt::red);
    }
    else if(arg1 == "White"){
        bar_color = new QColor(Qt::white);
    }
    else if(arg1 == "Blue"){
        bar_color = new QColor(Qt::blue);
    }
    else if(arg1 == "Green"){
        bar_color = new QColor(Qt::green);
    }
    foreach(Bars* item, bars){
            item->set_color(*(bar_color));
    }
}


/*!
  \fn PlotWindow::on_comboBox_currentTextChanged(const QString &arg1)

    Responds to the drop down menu to change the immortal cell color in the grid.
    Gets the new cell color.
    Updates all the immortal cells in the grid scene to the new color.
*/
void PlotWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Black"){
        cell_color = new QColor(Qt::black);
    }
    else if(arg1 == "Gray"){
        cell_color = new QColor(Qt::gray);
    }
    else if(arg1 == "Yellow"){
        cell_color = new QColor(Qt::yellow);
    }
    else if(arg1 == "Blue"){
        cell_color = new QColor(Qt::blue);
    }
    else if(arg1 == "Green"){
        cell_color = new QColor(Qt::green);
    }
    grid_->UpdateCellColor(*(cell_color));
}


/*!
  \fn PlotWindow::PlotWindow::~PlotWindow()

    Deconstructor that deletes the UI.
*/
PlotWindow::~PlotWindow()
{
    delete ui;
}



