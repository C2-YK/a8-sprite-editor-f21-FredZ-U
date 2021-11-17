#include "sprite.h"
#include <QDebug>

Sprite::Sprite()
{
    height = 16;
    width = 16;
    maxFrame = 1;
    editingFrame = 0;
    frames = QList<Frame*>(maxFrame);
    frames[editingFrame] = new Frame(height, width);
}

Sprite::Sprite(int height, int width){
    this->height = height;
    this->width = width;
    maxFrame = 1;
    editingFrame = 0;
    frames = QList<Frame*>(maxFrame);
    frames[editingFrame] = new Frame(this->height, this->width);
}

Sprite::Sprite(int height, int width, QList<Frame*> frames, int maxFrame){
    this->height = height;
    this->width = width;
    this->frames = frames;
    this->maxFrame = maxFrame;
}

Sprite::Sprite(const Sprite& other){
    this->height = other.height;
    this->width = other.width;
    this->maxFrame = other.maxFrame;
    frames = QList<Frame*>(maxFrame);
    for(int i = 0; i < maxFrame; i++){
        frames[i] = new Frame(*other.frames[i]);
    }
}

Sprite::~Sprite(){
    for(int i = 0; i < maxFrame; i++){
        delete frames[i];
    }
}

Sprite& Sprite::operator=(Sprite other){
    std::swap(this->height, other.height);
    std::swap(this->width, other.width);
    std::swap(this->maxFrame, other.maxFrame);
    std::swap(this->frames, other.frames);
    return *this;
}

void Sprite::addFrame(){
    Frame* f = new Frame(height, width);
    frames.append(f);
    maxFrame++;
    editingFrame = maxFrame - 1;
}

void Sprite::deleteFrame(){
    moveFrame(editingFrame, maxFrame-1);
    delete frames[maxFrame-1];
    frames.pop_back();
    maxFrame--;
}

void Sprite::setEditingTarget(int index){
    editingFrame = index;
}

const QImage& Sprite::getPlaybackImage(int FrameIndex){
    return frames[FrameIndex]->getImage();
}

const QImage& Sprite::getEditingImage(){
    return frames[editingFrame]->getImage();
}

Frame& Sprite::getCurrentFrame(){
    return *frames[editingFrame];
}

void Sprite::setMax(int max){
    maxFrame = max;
}

void Sprite::moveFrame(int from, int to){
    Frame* temp = frames[from];
    for(int i = from; i < to; i++){
        frames[i] = frames[i+1];
    }
    frames[to] = temp;
}

void Sprite::resize(int height, int width){
    for(int i = 0; i < maxFrame; i++){
        if(frames[i]){
            frames[i]->resize(height, width);
        }
    }
}
const QList<Frame*> Sprite::getFrames(){
    return frames;
}
int Sprite::getMaxFrame(){
   return maxFrame;
}
int Sprite::getHeight(){
    return height;
}
int Sprite::getWidth(){
    return width;
}
int Sprite::getEditingFrame(){
    return editingFrame;
}
