#ifndef PREVIEWER_H
#define PREVIEWER_H

#include <QObject>
#include "sprite.h"

class Previewer
{
    Q_OBJECT
public:
    Previewer();
    Sprite* targetSprite;
    int playbackSpeed;
    int playbackPointer;
    int editingPointer;
    void updateEditorWindow();
    void playback(); //playbackPointer++ send signal to render
    void setPlaybackSpeed();
};

#endif // PREVIEWER_H
