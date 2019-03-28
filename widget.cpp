#include "widget.h"
#include "ui_widget.h"

qreal count;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    Unitcount = 0;

    ui->setupUi(this);


    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-250,-250,500,500);
//    scene->addLine(-250,0,250,0,QPen(Qt::black));
//    scene->addLine(0,-250,0,250,QPen(Qt::black));

//    scene->addLine(-250,-250, 250,-250, QPen(Qt::black));
//    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
//    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
//    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));



    timer = new QTimer();
    auto timerunit = new QTimer();
    timertowershoot = new QTimer();


//    connect(timerunit,&QTimer::timeout, this, &Widget::CreateUnit );


    timer->start(100);
    timerunit->start(2000);
    timertowershoot->start(1000);
}

void Widget::CreateUnit()
{
    Unitcount++;
    if (Unitcount <=6)
    {
        Unit *unit = new Unit();
        scene->addItem(unit);
        unit->setPos(-240,30);
        units.append(unit);
        connect(timer,&QTimer::timeout,unit, &Unit::slotGameTimer);

    }
}

void Widget::slotDeleteApple(Unit *item,Tower *tower1)
{

    if(dynamic_cast<Unit*>(item) !=nullptr)
    {
        if(item->virtualhealth !=0)
            {
//               tower1->canattack = false;
               item->virtualhealth -=1;
               Bullet *bullet = new Bullet(tower1->x(),tower1->y(), item->x(),item->y());
               connect(item,&Unit::SignalBulletMove, bullet, &Bullet::SlotShoot);
               connect(bullet,&Bullet::SignalCheckItem,this,&Widget::slotAttacked);
//               connect(bullet,&Bullet::SignalLanded,tower1,&Tower::SlotCanAttack);
               scene->addItem(bullet);
               std::cout<<"Unit health = "<<item->virtualhealth<<std::endl;

            }



    }
}
void Widget::slotAttacked(Unit *obj)
{ 
    obj->health-=1;
    if(obj->health == 0)
    {

    scene->removeItem(obj);
    obj->deleteLater();
    std::cout<<"Zero health"<<std::endl;
    }

}
void Widget::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
     Tower *tower2 = new Tower();
     scene->addItem(tower2);
     tower2->setPos(ui->graphicsView->mapToScene(event->pos()));
     connect(timertowershoot, &QTimer::timeout, tower2, &Tower::Shoot);
     connect(tower2,&Tower::signalCheckItem, this,&Widget::slotDeleteApple);



}
    if (event->button() == Qt::RightButton)
    {
     auto *unit = new Unit();
     scene->addItem(unit);
     unit->setPos(ui->graphicsView->mapToScene(event->pos()));
     connect(timer,&QTimer::timeout,unit, &Unit::slotGameTimer);

}
}


Widget::~Widget()
{
    delete ui;
}








