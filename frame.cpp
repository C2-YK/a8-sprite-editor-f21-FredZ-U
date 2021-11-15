#include "frame.h"
#include <QtDebug>
Frame::Frame()
{
    height = 200;
    width = 100;
    image = QImage(width, height, QImage::Format_ARGB32);
    for(int i = 0; i<height; i++){
        for(int j = 0; j < width; j++){
            image.setPixel(j, i, QColor(0,0,0, 255).rgba());
        }
    }

}

Frame::Frame(int height, int width){
    this->height = height;
    this->width = width;
    image = QImage(width, height, QImage::Format_ARGB32);
    for(int i = 0; i<height; i++){
        for(int j = 0; j < width; j++){
            image.setPixel(j, i, QColor(0,0,0,255).rgba());
        }
    }
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
    std::swap(this->height, other.height);
    std::swap(this->width, other.width);
    std::swap(this->image, other.image);
    return *this;
}
const QImage& Frame::getImage(){
    return image;
}
void Frame::resize(int height, int width){
    QImage replacement = QImage(width, height, QImage::Format_ARGB32);
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->height; j++){
            if(i<width && j<height){
                replacement.setPixel(i, j,image.pixel(i, j));
            }
        }
    }
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
