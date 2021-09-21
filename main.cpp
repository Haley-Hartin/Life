/*!
Haley Hartin
HW_4 Life
This program creates a simulation of Conways's Game of Life.
This program takes no arguments.
*/

#include "plotwindow.h"
#include <QApplication>

//driver of program
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int code = 0;
    //run the application until a restart command has been set
    do
    {
        PlotWindow w;
        w.show();
        code = a.exec();
    }while(code == 1000);
}
