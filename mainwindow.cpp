#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <QTime>
using namespace std;
const int maxn=0x3f3f3f3f;
const int times = 1000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void sleep(unsigned int msec)
{
QTime dieTime = QTime::currentTime().addMSecs(msec);
while( QTime::currentTime() < dieTime )
QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red,3));
    painter.drawRect(0,0,200,200);
    painter.drawEllipse(0,0,200,200);
    srand(time(0));
    double residual = maxn;
    double e = 0.0001;
    double pi = 100;
    int cnt = 1;
    int cnt_circle = 0;
    painter.setPen(QPen(Qt::green,1));
    while (residual > e)
    {

        for(int i = 0; i < times; ++i)
        {
            double tmp_x = rand() % 10000 * 0.01;
            double tmp_y = rand() % 10000 * 0.01;
            if(tmp_x*tmp_x+tmp_y*tmp_y<=10000)
            {
                painter.setPen(QPen(Qt::green,5));
                int cha1 = rand()%2;
                int cha2 = rand()%2;
                tmp_x+=100;
                tmp_y+=100;
                if(cha1==1) tmp_x = 200-tmp_x;
                if(cha2==1) tmp_y = 200-tmp_y;

                painter.drawPoint(tmp_x,tmp_y);
                cnt_circle++;
            }
            else
            {
                painter.setPen(QPen(Qt::black,5));
                int cha1 = rand()%2;
                int cha2 = rand()%2;
                tmp_x+=100;
                tmp_y+=100;
                if(cha1==1) tmp_x = 200-tmp_x;
                if(cha2==1) tmp_y = 200-tmp_y;

                painter.drawPoint(tmp_x,tmp_y);
            }
            sleep(5);
        }
        double re_pi = 4 * (1.0 * cnt_circle / (cnt * times));
        residual = fabs(pi - re_pi);
        pi = re_pi;
        ++cnt;

    }
    //painter.setPen(QPen(Qt::red,10));
    //painter.drawPoint(200,200);
    //painter.drawText(QPoint(10,70),"hello");
}


