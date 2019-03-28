#include "bullet.h"

Bullet::Bullet(qreal x1,qreal y1,qreal x2,qreal y2,QObject *parent) : QObject(parent), QGraphicsItem()
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
     this->setPos(x1,y1);
    Bullet::counter++;
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);
    painter->drawEllipse(0,0,4,4);
    qreal angle;
    if(x2>x1)
    angle =qRadiansToDegrees(qAtan( ((x2-x1)/(y2-y1))));
    else
      angle =qRadiansToDegrees(qAtan( ((x1-x2)/(y2-y1))));


    setRotation( angle);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,4,4);
}
void Bullet::SlotShoot(QGraphicsItem *item)
{



    qreal attack_radius = 4;
    QLineF linetoUnit (QPoint(0,0),mapFromItem(item,0,0));
    qreal angle;
    angle = qRadiansToDegrees( qAcos(linetoUnit.dx()/linetoUnit.length()));

    if (linetoUnit.dy()<0)
        angle = -angle;
      this->setRotation(this->rotation()+angle);

    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                       << mapToScene(-attack_radius, -attack_radius)
                                                       << mapToScene(-attack_radius, attack_radius)
                                                       << mapToScene(attack_radius, -attack_radius)
                                                       << mapToScene(attack_radius,attack_radius));

    foreach (QGraphicsItem *tete, foundItems)
            {
                if( dynamic_cast<Unit*>(tete) != nullptr)
                    {

                    emit SignalCheckItem(static_cast<Unit*>(tete));
                    emit SignalLanded();
                    scene()->removeItem(this);
                    this->deleteLater();

                    }

            }

setPos(mapToScene(13,0));
/*
if((currentposX == this->x())&&(currentposY == this->y()))
    scene()->removeItem(this);
    this->deleteLater();*/


}
