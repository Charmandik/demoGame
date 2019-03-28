#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QProgressBar>
#include <iostream>
#include <QImage>






class Unit :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Unit(QObject *parent = 0);
    int health;
    int virtualhealth;
     ~Unit();
    void setHealth(int a);
    int getHealth();
    QImage unitimage;
void AddUnit(Unit *b, int a);
void AddToScene(Unit *b, QGraphicsScene *scene);
 Unit *NextUnit;
signals:
    void SignalBulletMove(QGraphicsItem *item);
public slots:
    void slotGameTimer();  // Слот, который отвечает за обработку перемещения треугольника


protected:
    QRectF boundingRect() const; /* Определяем виртуальный метод, который возвращает область, в которой
                                   находится треугольник */
   void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:

    int level;
    int count;


};

#endif // UNIT_H
