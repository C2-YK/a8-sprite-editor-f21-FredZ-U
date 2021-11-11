#include "sprite.h"

Sprite::Sprite()
{
}

Sprite::~Sprite(){
    for(int i = 0; frames.size(); i++){
        delete frames[i];
    }
}
