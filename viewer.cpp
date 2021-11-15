#include "viewer.h"
#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Viewer)
{
    ui->setupUi(this);
}

Viewer::~Viewer()
{
    delete ui;
}

void Viewer::playback(const QImage &frameImage){

}
void Viewer::updateEditor(const QImage &frameImage){

    image = frameImage;
    update();

}
void Viewer::saveCallback(bool success){

}
void Viewer::loadCallback(bool success){

}













void Viewer::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){//if mouse left button clicked

        emit useToolOn(event -> pos());//get mouse position as start point
    }

}



void Viewer::mouseMoveEvent(QMouseEvent * event){
    if(event->buttons()&Qt::LeftButton){//if mouse left button clicked and move at same time

        emit useToolOn(event -> pos());//get mouse position as end point

    }


}


void Viewer::mouseReleaseEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){//if mouse left button clicked

        emit useToolOn(event -> pos());//get mouse position as end point

    }


}


void Viewer::paintEvent(QPaintEvent *){


    QPainter painter(this);
    painter.drawImage(0,0, image);//set canvas

}
