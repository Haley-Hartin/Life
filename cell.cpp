/*!
This file contains implememtations of the cells class.
*/
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QMouseEvent>



#include "cell.h"

/*!
  \fn Cell::Cell(QColor color, const int x, const int y)

    Constructor. Initializes a cell object.
    Sets the sizes and color of the cell.
*/
Cell::Cell(QColor color, const int x, const int y) {
  this->color_ = color;
  x_ = x;
  y_ = y;
  immortal_color_ = QColor(0,0,0);
}

/*!
  \fn Cell::setStatus(bool status)

    Sets the status of the cell (alive or dead).
    Checks if the cell is immortal.
    Updates the cells color

*/
void Cell::setStatus(bool status){

    //if the cell is alive
    if(status){
        if(is_immortal_){
            setImmortal(true);
        }
        else{
            alive_ = true;
            QColor c = Qt::magenta;
            color_ = c;
        }

    }
    //if the cell is dead
    else{
        alive_= false;
        QColor c = Qt::white;
        color_ = c;
    }
    update();
}

/*!
  \fn Cell::setImmortal(bool status)

    Change the status of a cells mortality (immortal or not).
    Updates the cells color, alive and mortality variables.

*/
void Cell::setImmortal(bool status){
    if(status){
        alive_ = true;
        is_immortal_ = true;
        color_ = immortal_color_;
    }
    else{
        alive_= false;
        is_immortal_ = false;
        QColor c = Qt::white;
        color_ = c;
    }
    update();
}

/*!
  \fn Cell::setNextTurnStatus(bool status)

    Sets the status of the cell for the next turn (alive or dead).

*/
void Cell::setNextTurnStatus(bool status){
    if(status){
        next_turn_ = true;
    }
    else{
        next_turn_= false;
    }
}

/*!
  \fn QRectF Bars::boundingRect() const

    Creates and returns a rectangle with the given sizes.
*/
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, 67, 35);
}

/*!
  \fn Bars::QPainterPath Cell::shape() const

    Creates a circle.
*/
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, 67, 35);
    return path;
}

/*!
  \fn Bars::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

    Draws the shape with the given color.
*/
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(this->x_, this->y_, 67, 35));
    painter->setBrush(b);
}

/*!
  \fn Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)

    Responds to mouse press events on an cell.
    Checks which type of click it was.
    Calls the appropriate functions to update the status of the cell.

*/
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //left click
    if(event->button() == Qt::RightButton){

        //makes a cell die
        setStatus(false);

    }
   //right click
   if(event->button() == Qt::LeftButton){

       //makes a cell immortal
       if(event->modifiers() == Qt::ShiftModifier){
           if(is_immortal_){
               setImmortal(false);
           }
           else{
               setImmortal(true);
           }
       }
       //makes a cell alive
       else{
           setStatus(true);
       }
   }
   update();
}


