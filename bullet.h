#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QVector2D>
#include <iostream>
#include <qmath.h>

#include <unit.h>


class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    static int counter;
    explicit Bullet(qreal x  ,qreal y,qreal x1 ,qreal x2 ,QObject *parent = nullptr);
signals:
    void SignalCheckItem(Unit *obj);
    void SignalLanded();
public slots:
    void SlotShoot(QGraphicsItem *item);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
     qreal x1,x2,y1,y2;
};

