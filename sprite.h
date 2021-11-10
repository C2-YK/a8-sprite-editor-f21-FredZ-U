#ifndef SPRITE_H
#define SPRITE_H
#include <QList>
#include "frame.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();
    Sprite(const Sprite& other);
    Sprite& operator=(Sprite other);

    QList<Frame*> frames;
    int editing;
    int maxFrame;
    //add an empty frame on current editing position iff editing position is no pointer
    //user has to delete frame then new frame to prevent overwrite
    void newFrame();//target editing
    void deleteFrame();//target editing
    void swapFrames(int, int); //swap the frames on the index positions prevent int == int
    void setEditingTarget(int); //editing = input
    void setMax(int);//maxFrame = input


};

#endif // SPRITE_H
