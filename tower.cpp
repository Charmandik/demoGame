#include "tower.h"
#include "bullet.h"

Tower::Tower(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
level = 1;
attack_radius = 250;
canattack = true;
towerimage.load("D:/QtProjects/android/tower.png");

}
Tower::~Tower()
{

}
QRectF Tower::boundingRect() const
{

    return QRectF(0,0,250,250);  // Ограничиваем область, в которой лежит треугольник
}
void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        painter->drawEllipse(0,0,attack_radius,attack_radius);
    painter->drawImage(0,0,towerimage);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void Tower::Shoot()
{
    if(this->canattack)
    {

    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                       << mapToScene(-attack_radius, -attack_radius)
                                                       << mapToScene(-attack_radius, attack_radius)
                                                       << mapToScene(attack_radius, -attack_radius)
                                                       << mapToScene(attack_radius,attack_radius));
    foreach (QGraphicsItem *item, foundItems)
            {
            if ((dynamic_cast<Tower*>(item) != nullptr)||(dynamic_cast<Bullet*>(item) != nullptr))
                continue;

            emit signalCheckItem(dynamic_cast<Unit*>(item),this);
            break;


            }

}
}
void Tower::SlotCanAttack()
{
    this->canattack = true;
}
