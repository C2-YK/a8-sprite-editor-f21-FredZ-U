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
int Frame::getHeight(){
    return height;
}
int Frame::getWidth(){
    return width;
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
void Frame::paintOn(QPoint position, QColor brushColor){
    image.setPixel(position.x(), position.y(), brushColor.rgba());
}
void Frame::eraseOn(QPoint position){
    image.setPixel(position.x(), position.y(), QColor(0,0,0,0).rgba());
}
QColor Frame::colorPickOn(QPoint position){
    return image.pixelColor(position.x(), position.y());
}
void Frame::bucketOn(QPoint position, QColor brushColor){
    QColor target = image.pixelColor(position.x(), position.y());
    if(brushColor == target){
        return;
    }
    bucketRecursive(position.x(), position.y(), target, brushColor);
}
void Frame::bucketRecursive(int x, int y, QColor target, QColor overWrite){
    if(x<0||x>=width){
        return;
    }
    if(y<0||y>=height){
        return;
    }
    if(image.pixelColor(x, y) == target){
        image.setPixelColor(x,y,overWrite);
        bucketRecursive(x-1, y, target, overWrite);
        bucketRecursive(x, y+1, target, overWrite);
        bucketRecursive(x+1, y, target, overWrite);
        bucketRecursive(x, y-1, target, overWrite);
    }
}
