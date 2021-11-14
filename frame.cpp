#include "frame.h"

Frame::Frame()
{
    height = 200;
    width = 100;
    image = QImage(height, width, QImage::Format_ARGB32);

}

Frame::Frame(int height, int width){
    this->height = height;
    this->width = width;
    image = QImage(height, width, QImage::Format_ARGB32);

}

Frame::Frame(int height, int width, QImage image){
    this->height = height;
    this->width = width;
    this->image =image;

}


Frame::~Frame(){

}

Frame::Frame(const Frame& other){
    height = other.height;
    width = other.width;

}
Frame& Frame::operator=(Frame other){

}
const QImage& Frame::getImage(){
    return image;
}
void Frame::resize(int height, int width){

}
void Frame::paintOn(QVector2D position, QColor brushColor, int brushSize){
    image.setPixel((int)(position.x()), (int)(position.y()), brushColor.rgba());

    for(int x= (x-brushSize)/2; x = ; x++){
        for(int y=0; y = brushSize; y++){

        }
    }


}
void Frame::eraseOn(QVector2D position, int brushSize){

}
QColor Frame::colorPickOn(QVector2D position){

}
