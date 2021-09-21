/*!
This file contains definitions of the bars class.
*/

#ifndef BARS_H
#define BARS_H

#include <QColor>
#include <QGraphicsItem>

class Bars : public QObject, public QGraphicsItem {

    Q_OBJECT

public:
    Bars(QColor color, int x,int y, int height);  // constructor

    //inline functions
    void set_color(QColor c){color_ = c;
                            update();}
    int get_x(){return x_;}
    int get_y(){return y_;}

    void set_x(int x){x_ = x;
                     update();}
    void set_y(int y){y_ = y;
                     update();}


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;



private:
  int x_;
  int y_;
  int height_;

  QColor color_;
  static const int width_ = 20;

};



#endif
