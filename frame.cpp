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
void Frame::paintOn(QPoint position, QColor brushColor, int brushSize){

    int x = position.x();
    int y = position.y();

    for(int i= x-brushSize/2; i <= brushSize/2; i++){
        for(int j = y-brushSize/2; j <= brushSize/2; j++){
            image.setPixel(i, j, brushColor.rgba());
        }
    }


}
void Frame::eraseOn(QPoint position, int brushSize){

}
QColor Frame::colorPickOn(QPoint position){

}
