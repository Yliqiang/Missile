#include "mainscene.h"
#include "config.h"
#include "move.h"
#include<iostream>
#include<QIcon>
#include<QPixmap>
#include<QPalette>
#include<QBrush>
#include<QPainter>
using namespace std;
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{

    //��濮����烘��
    initScene();
    //��ㄦ父��
   // playGame();
}
void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(TITLE);

    //瀹��跺�ㄨ缃�
    m_Timer.setInterval(GAME_RATE);
    //寮�濮�娓告������
    MainButton_1=new QPushButton(this);
    MainButton_1->setIcon(QIcon(QUIT_PATH));
    MainButton_1->setIconSize(QSize(150, 70));
    MainButton_1->setGeometry(50,560,120,28);
    connect(MainButton_1,&QPushButton::clicked,this,&MainScene::playGame);
    //缁���娓告������
    MainButton_1=new QPushButton(this);
    MainButton_1->setIcon(QIcon(QUIT_PATH1));
    MainButton_1->setIconSize(QSize(150, 70));
    MainButton_1->setGeometry(50,600,120,34);
    connect(MainButton_1,&QPushButton::clicked,this,&MainScene::close);
}

MainScene::~MainScene()
{

}

void MainScene::collisionDetection()
{
    /*m_missile.m_hit=0;
    m_missile1.m_hit=0;
    m_missile2.m_hit=0;
    m_missile3.m_hit=0;
    m_missile4.m_hit=0;*/
    if(m_jianting.jianting_life>0)
    {
    if(m_jianting.m_XJianting-2<m_feiji.missile.m_X and m_feiji.missile.m_X<m_jianting.m_XJianting+2)
{
        m_jianting.jianting_life-=500;
}
    if(m_jianting.m_XJianting-2<m_feiji1.missile1.m_X1 and m_feiji1.missile1.m_X1<m_jianting.m_XJianting+2)
{
        m_jianting.jianting_life-=500;
}
    if(m_jianting.m_XJianting-2<m_feiji2.missile2.m_X2 and m_feiji2.missile2.m_X2<m_jianting.m_XJianting+2)
    {
        m_jianting.jianting_life-=500;
}
    if(m_jianting.m_XJianting-2<m_feiji3.missile3.m_X3 and m_feiji3.missile3.m_X3<m_jianting.m_XJianting+2)
    {
m_jianting.jianting_life-=500;
}
    if(m_jianting.m_XJianting-2<m_feiji4.missile4.m_X4 and m_feiji4.missile4.m_X4<m_jianting.m_XJianting+2)
    {
m_jianting.jianting_life-=500;
}
    }
//��剧���告����
    for(int k = 0 ; k < BOMB_NUM;k++)
    {
if(m_bombs[k].m_Free)
{ //���哥�舵��璁剧疆涓洪��绌洪��
m_bombs[k].m_Free = false;
//�存�板����
m_bombs[k].m_X = 660;
m_bombs[k].m_Y = 370;
break; } }
}
void MainScene::playGame()
{
    m_Timer.start();
    //�����跺��
    connect(&m_Timer,&QTimer::timeout,[=](){
    //�存�版父��涓��绱�������
        updatePosition();
    //���扮��跺�剧��
        update();
       time +=0.01;
        //纰版��妫�娴�
     collisionDetection();
       /*if(m_jianting.jianting_life<=0)
       {
         m_Timer.stop();
        }*/
       });

}
void MainScene::updatePosition()
{
    //�存�板�板�惧����
     m_jianting.m_Free = false;
    m_jianting.updatePosition();
    m_feiji.m_Free = false;
    m_feiji.updatePosition();
    m_feiji1.m_Free = false;
    m_feiji1.updatePosition();
    m_feiji2.m_Free = false;
    m_feiji2.updatePosition();
    m_feiji3.m_Free = false;
    m_feiji3.updatePosition();
    m_feiji4.m_Free = false;
    m_feiji4.updatePosition();
    m_lanjiedan1.m_Free = false;
    m_lanjiedan1.updatePosition();
    m_lanjiedan2.m_Free = false;
    m_lanjiedan2.updatePosition();
    //��灏�瀵煎脊
   m_feiji.shoot();
    //璁＄�瀵煎脊����
    for(int i = 0 ;i <1;i++)
    { //濡���瀛�寮圭�舵��涓洪��绌洪�诧�璁＄���灏�浣�缃�
        if(!m_feiji.missile.m_Free)
        { m_feiji.missile.updatePosition(); } }
    m_feiji1.shoot1();
     for(int i = 0 ;i <1;i++)
     {
         if(!m_feiji1.missile1.m_Free)
         { m_feiji1.missile1.updatePosition(); } }
      m_feiji2.shoot2();
     for(int i = 0 ;i <1;i++)
     {
         if(!m_feiji2.missile2.m_Free)
         { m_feiji2.missile2.updatePosition(); } }
     m_feiji3.shoot3();
    for(int i = 0 ;i <1;i++)
    {if(!m_feiji3.missile3.m_Free)
        { m_feiji3.missile3.updatePosition(); } }
    m_feiji4.shoot4();
   for(int i = 0 ;i <1;i++)
   {if(!m_feiji4.missile4.m_Free)
       { m_feiji4.missile4.updatePosition(); } }

   m_jianting.shoot5();
  for(int i = 0 ;i <1;i++)
  {if(!m_jianting.m_lanjiedan1.m_Free)
      { m_jianting.m_lanjiedan1.updatePosition(); } }
  m_jianting.shoot6();
 for(int i = 0 ;i <1;i++)
 {if(!m_jianting.m_lanjiedan2.m_Free)
     { m_jianting.m_lanjiedan2.updatePosition(); } }

 //if(m_feiji.temp_missile.m_X==m_jianting.m_XJianting){
    // cout<<m_jianting.m_XJianting<<endl;
// }

 //璁＄����告��剧���剧��
 for(int i = 0 ; i < BOMB_NUM;i++) {
     if(m_bombs[i].m_Free == false)
     {
         m_bombs[i].updateInfo(); } }

}


void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont f1("妤蜂�",14,QFont::Bold,true);
    painter.setFont(f1);
    painter.setPen(Qt::yellow);
    painter.drawText(600,500,"�拌��琛���锛�");
    painter.drawText(360,500,tr(gcvt(m_jianting.jianting_life,5,ptr)));
    //缁��跺�板��
    painter.drawPixmap(0,m_map.m_map1_Y,m_map.m_map1);
    if(m_jianting.jianting_life>0){
    painter.drawPixmap(m_jianting.m_XJianting,m_jianting.m_YJianting,m_jianting.m_Jianting);}
    painter.drawPixmap(m_feiji.XPlane,m_feiji.YPlane,m_feiji.Plane);
   // painter.drawPixmap(m_feiji.XPlane,m_feiji.YPlane,m_feiji.Plane);

    /*QPixmap pix;
    pix.load(":/res/feiji1.png");

painter.translate(50,50);
painter.rotate(180);
painter.translate(-50,-50);
painter.drawPixmap(0,0,100,100,pix);*/




    painter.drawPixmap(m_feiji1.XPlane1,m_feiji1.YPlane1,m_feiji1.Plane1);
    painter.drawPixmap(m_feiji2.XPlane2,m_feiji2.YPlane2,m_feiji2.Plane2);
    painter.drawPixmap(m_feiji3.XPlane3,m_feiji3.YPlane3,m_feiji3.Plane3);
    painter.drawPixmap(m_feiji4.XPlane4,m_feiji4.YPlane4,m_feiji4.Plane4);

     //缁��跺寮�
         if(!m_feiji.missile.m_Free)
         {
             if(m_feiji.missile.m_X<m_jianting.m_XJianting+10){
             painter.drawPixmap(m_feiji.missile.m_X,m_feiji.missile.m_Y,m_feiji.missile.m_Missile );
             }
         }

         if(!m_feiji1.missile1.m_Free)
         {
             if(m_feiji1.missile1.m_X1<m_jianting.m_XJianting+10){

                painter.drawPixmap(m_feiji1.missile1.m_X1,m_feiji1.missile1.m_Y1,m_feiji1.missile1.m_Missile );
             }}

         if(!m_feiji2.missile2.m_Free)
         {
             if(m_feiji2.missile2.m_X2<=m_jianting.m_lanjiedan1.m_x1){
             painter.drawPixmap(m_feiji2.missile2.m_X2,m_feiji2.missile2.m_Y2,m_feiji2.missile2.m_Missile );
             }
         }
         if(!m_feiji3.missile3.m_Free)
         {
             if(m_feiji3.missile3.m_X3<1050){
             painter.drawPixmap(m_feiji3.missile3.m_X3,m_feiji3.missile3.m_Y3,m_feiji3.missile3.m_Missile );
             } }
         if(!m_feiji4.missile4.m_Free)
         {
             if(m_feiji4.missile4.m_X4<=m_jianting.m_lanjiedan2.m_x2){
             painter.drawPixmap(m_feiji4.missile4.m_X4,m_feiji4.missile4.m_Y4,m_feiji4.missile4.m_Missile );
            }
         }
         if(!m_jianting.m_lanjiedan1.m_Free)
         {
             if(m_jianting.m_lanjiedan1.m_x1>=m_feiji2.missile2.m_X2)  {
             painter.drawPixmap(m_jianting.m_lanjiedan1.m_x1,m_jianting.m_lanjiedan1.m_y1,m_jianting.m_lanjiedan1.m_Missile );
         }
         }
         if(!m_jianting.m_lanjiedan2.m_Free)
{if(m_jianting.m_lanjiedan2.m_x2>=m_feiji4.missile4.m_X4 and m_jianting.m_lanjiedan2.m_y2>=m_feiji4.missile4.m_Y4)
painter.drawPixmap(m_jianting.m_lanjiedan2.m_x2,m_jianting.m_lanjiedan2.m_y2,m_jianting.m_lanjiedan2.m_Missile );
}

//缁��剁���稿�剧��
for(int i = 0 ; i < 1;i++)
{ if(m_bombs[i].m_Free == false)
 {        if(m_feiji4.missile4.m_X4-15<m_jianting.m_lanjiedan2.m_x2 and m_feiji4.missile4.m_X4+15>m_jianting.m_lanjiedan2.m_x2)
        {painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
     }
        if(m_feiji2.missile2.m_X2-15<m_jianting.m_lanjiedan1.m_x1 and m_feiji2.missile2.m_X2+30>m_jianting.m_lanjiedan1.m_x1)
        {painter.drawPixmap(m_bombs[i].m_X-50,m_bombs[i].m_Y+40,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
    }
        if(  m_feiji.missile.m_X-20<m_jianting.m_XJianting and m_jianting.m_XJianting<m_feiji.missile.m_X+70)
        {painter.drawPixmap(m_bombs[i].m_X+210,m_bombs[i].m_Y+170,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
    }
        if(  m_feiji1.missile1.m_X1-20<m_jianting.m_XJianting and m_jianting.m_XJianting<m_feiji1.missile1.m_X1+70)
        {
        painter.drawPixmap(m_bombs[i].m_X+200,m_bombs[i].m_Y+180,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        } }}}

