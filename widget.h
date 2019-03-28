#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QtCore"
#include "QtGui"
#include <QGraphicsScene>
#include "QString"
#include "QPainter"
#include "QProgressBar"

#include "unit.h"
#include "tower.h"
#include "bullet.h"



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:

void CreateUnit();
void slotDeleteApple(Unit *item, Tower *tower1);
void slotAttacked(Unit* obj);


private:

    Ui::Widget *ui;
    QGraphicsScene *scene;
    Unit *unit1;
    QTimer *timertowershoot;
    QTimer *timer;
    Tower *tower1;
    int Unitcount;
    QList<Unit *> units;
    void mousePressEvent(QMouseEvent *event);

};

#endif // WIDGET_H
