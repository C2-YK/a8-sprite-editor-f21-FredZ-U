#ifndef PREVIEWER_H
#define PREVIEWER_H

#include <QObject>
#include <QImage>
#include <QThread>
#include "sprite.h"

class Previewer : public QObject
{
    Q_OBJECT
public:
    Previewer();
    void setSprite(Sprite*);
public slots:
    void setPlaybackSpeed(int speed);
    void startPlayback(bool);
    void updatePreviewer();
signals:
    void updateEditorWindow(const QImage& updateImage);
    void playback(const QImage&);
private:
    Sprite* targetSprite;
    int playbackSpeed;
    int playbackPointer;
    bool playing;
    void playbackLoop();
};

#endif // PREVIEWER_H
