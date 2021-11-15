#include "sprite.h"

Sprite::Sprite()
{
    height = 800;
    width = 600;
    maxFrame = 10;
    editingFrame = 0;
    frames = QList<Frame*>(maxFrame);
    for(int i = 0; i < maxFrame; i++){
        frames[i] = nullptr;
    }
    frames[editingFrame] = new Frame(height, width);
}

Sprite::Sprite(int height, int width){
    this->height = height;
    this->width = width;
    maxFrame = 10;
    frames = QList<Frame*>(maxFrame);
    for(int i = 0; i < maxFrame; i++){
        frames[i] = nullptr;
    }
    frames[editingFrame] = new Frame(height, width);
}

Sprite::~Sprite(){
    for(int i = 0; frames.size(); i++){
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

bool Sprite::addFrame(){
    if(frames[editingFrame] == nullptr){
        frames[editingFrame] = new Frame(height, width);
        return true;
    }else{
        return false;
    }
}

void Sprite::deleteFrame(){
    delete frames[editingFrame];
    frames[editingFrame] = nullptr;
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
int Sprite::getMaxFrame(){
   return maxFrame;
}
