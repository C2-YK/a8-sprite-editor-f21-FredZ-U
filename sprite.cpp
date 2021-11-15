#include "sprite.h"

Sprite::Sprite()
{
    height = 400;
    width = 600;
    maxFrame = 10;
}

Sprite::Sprite(int height, int width){
    this->height = height;
    this->width = width;
    maxFrame = 10;
}

Sprite::~Sprite(){
    for(int i = 0; frames.size(); i++){
        delete frames[i];
    }
}

Sprite& Sprite::operator=(Sprite other){

}

bool Sprite::addFrame(){

}

bool Sprite::deleteFrame(){

}

void Sprite::setEditingTarget(int){

}

const QImage& Sprite::getPlaybackImage(int FrameIndex){

}

const QImage& Sprite::getEditingImage(){

}

Frame& Sprite::getCurrentFrame(){

}

void Sprite::setMax(int){

}

void Sprite::moveFrame(int from, int to){

}

void Sprite::resize(int height, int width){

}
