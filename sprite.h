#ifndef SPRITE_H
#define SPRITE_H
#include <QList>
#include "frame.h"

class Sprite
{
public:
    Sprite();
    Sprite(int height, int width);
    Sprite(int height, int width, QList<Frame*> frames, int maxFrame);
    ~Sprite();
    Sprite(const Sprite& other);
    Sprite& operator=(Sprite other);
    //add an empty frame on current editing position iff editing position is no pointer
    //user has to delete frame then new frame to prevent overwrite
    void addFrame();
    void deleteFrame();//target editing, return success?
    void setEditingTarget(int); //editing = input
    const QImage& getPlaybackImage(int FrameIndex);
    const QImage& getEditingImage();
    Frame& getCurrentFrame();
    void setMax(int);//maxFrame = input, and contruct a new frames
    void moveFrame(int from, int to);
    void resize(int height, int width);
    const QList<Frame*> getFrames();
    int getMaxFrame();
    int getHeight();
    int getWidth();


private:
    QList<Frame*> frames;
    int editingFrame;
    int maxFrame;
    int height;
    int width;
};

#endif // SPRITE_H
