#ifndef PREVIEWER_H
#define PREVIEWER_H

#include <QObject>
#include <QImage>
#include <QTimer>
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
private slots:
    void playbackLoop();
signals:
    void updateEditorWindow(const QImage& updateImage, int editingTarget);
    void playback(const QImage&);
private:
    Sprite* targetSprite;
    int playbackSpeed;
    int playbackPointer;
    bool playing;
};

#endif // PREVIEWER_H
