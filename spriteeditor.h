#ifndef SPRITEEDITOR_H
#define SPRITEEDITOR_H
#include "sprite.h"
#include <QObject>
#include <QColor>
#include <QVector2D>

class SpriteEditor : public QObject
{
    Q_OBJECT
public:
    SpriteEditor();
    void setSprite(Sprite*);
public slots:
    //frame setting
    void setEditingFrame(int);
    void addFrame();
    void deleteFrame();
    void moveFrame(int from, int to);
    //tool setting
    void setBrushColor(QColor);
    void useToolOn(QPoint position);
    void switchToolTo(int toolIndex);
signals:
    void updatePreviewer();
private:
    Sprite* target;
    QColor brushColor;
    int toolSwitch;
    void paintOn(QPoint position);
    void eraseOn(QPoint position);
    void colorPickOn(QPoint position);
    void bucketOn(QPoint position);

};

#endif // SPRITEEDITOR_H
