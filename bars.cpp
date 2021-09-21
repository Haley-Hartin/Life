/*!
This file contains implementations of the bars class.
*/

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "bars.h"

/*!
  \fn Bars::Bars(QColor color, int x, int y, int height)

    Constructor. Initializes a Bar object.
    Sets the sizes and color of the bar.
*/
Bars::Bars(QColor color, int x, int y, int height) {
  this->color_ = color;
  x_ = x;
  y_ = y;
  height_ = height;
}


/*!
  \fn QRectF Bars::boundingRect() const

    Creates and returns a rectangle with the given sizes.
*/
QRectF Bars::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}


/*!
  \fn Bars::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

    Draws the shape with the given color.
*/
void Bars::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));
    painter->setBrush(b);
}




