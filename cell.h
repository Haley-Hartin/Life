/*!
This file contains definitions of the cells class.
*/

#ifndef Cell_H
#define Cell_H

#include <QColor>
#include <QGraphicsItem>
#include <QTableWidgetItem>
#include <QMouseEvent>
#include <QDebug>

class Cell : public QObject,  public QGraphicsItem {
    Q_OBJECT

public:
    Cell(QColor color, const int x, const int y);  // constructor

    //inline functions
    bool get_alive(){return alive_;}
    bool get_next_turn_status(){return next_turn_; }
    int get_x(){return x_;}
    int get_y(){return y_;}
    bool get_immortal(){return is_immortal_;}
    void set_color(QColor c){immortal_color_ = c;
                             color_ = c;
                            update();}


    //setters
    void setStatus(bool status);
    void setNextTurnStatus(bool status);
    void setImmortal(bool status);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

protected:
    //get click types
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
  QColor color_;
  QColor immortal_color_;

  int x_;
  int y_;

  bool alive_;
  bool next_turn_;
  bool is_immortal_  = false;

};  // class Cell



#endif // Cell_H
