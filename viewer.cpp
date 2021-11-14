#include "viewer.h"
#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Viewer)
{
    ui->setupUi(this);
    canvas = QPixmap(640,480);
    canvas.fill(Qt::white);
}

Viewer::~Viewer()
{
    delete ui;
}

void Viewer::playback(const QImage &frameImage){

}
void Viewer::updateEditor(const QImage &frameImage){

}
void Viewer::saveCallback(bool success){

}
void Viewer::loadCallback(bool success){

}


void Viewer::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){//if mouse left button clicked
        lastPoint = event -> pos();//get mouse position as start point
    }

}



void Viewer::mouseMoveEvent(QMouseEvent * event){
    if(event->buttons()&Qt::LeftButton){//if mouse left button clicked and move at same time
        endPoint = event -> pos();//get mouse position as end point
        update();//and drawing
    }


}


void Viewer::mouseReleaseEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){//if mouse left button clicked
        endPoint = event -> pos();//get mouse position as end point
        update();
    }


}





void Viewer::paintEvent(QPaintEvent *){

    QPainter pp(&canvas);
    pp.drawLine(lastPoint, endPoint);
    lastPoint = endPoint;
    QPainter painter(this);
    painter.drawPixmap(0,0, canvas);//set canvas

}
