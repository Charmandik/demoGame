#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <unit.h>

class Tower : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Tower(QObject *parent = 0);
    ~Tower();
signals:
void signalCheckItem(Unit *item,Tower *tower1);
public slots:
    void SlotCanAttack();
    void Shoot();//Слот отвечающий за момент выстрела
protected:
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    QImage towerimage;
    int attack_radius;
    int level;
    bool canattack;

};

#endif // TOWER_H
