#ifndef PREVIEWER_H
#define PREVIEWER_H

#include <QObject>
#include <QImage>
#include "sprite.h"

class Previewer : public QObject
{
    Q_OBJECT
public:
    Previewer();
    void setSprite(Sprite*);
public slots:
    void updateEditorWindow();
    void setPlaybackSpeed(int speed);
    void startPlayback(bool);
signals:
    void playback(QImage);
private:
    Sprite* targetSprite;
    int playbackSpeed;
    int playbackPointer;
    int editingPointer;
};

#endif // PREVIEWER_H
