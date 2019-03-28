#include "unit.h"
#include "bullet.h"
#include "tower.h"


Unit::Unit(QObject *parent) :
    QObject(parent), QGraphicsItem() , NextUnit(NULL)
{
    count = 1;
    level = 1;
    health = 3;
    virtualhealth = health;
   unitimage.load("D:/QtProjects/android/1.png");
}
Unit::~Unit()
{

}

QRectF Unit::boundingRect() const
{
    return QRectF(0,-5,unitimage.width()+1,unitimage.height()+1);
}

void Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



  painter->drawImage(0,-5,unitimage);



   if(this->x() - 10 > 250)
    this->setX(-240);



    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Unit::slotGameTimer()
{
QList <QGraphicsItem*> collitem = scene()->items(/*QRectF*/(mapToScene( 0,0,unitimage.width()+10,unitimage.height()+10)));
foreach (QGraphicsItem* item, collitem) {
    if (( dynamic_cast<Tower*> (item) !=nullptr)) /*|| ( dynamic_cast <Bullet*> (item) !=nullptr))*/
    {
       setPos(mapToParent(0,5));

    }
    else
    {
    setPos(mapToParent(5,0));
    break;
    }

}


emit SignalBulletMove(this);

}
void Unit::setHealth(int a)
{
   health = health+a;
}
int Unit::getHealth()
{
    return this->health;
}







