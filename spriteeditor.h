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
    void setBrushSize(int size);
    void useToolOn(QVector2D position);
    void switchToolTo(int toolIndex);
private:
    Sprite* target;
    QColor brushColor;
    int toolSwitch;
    int brushSize;
    void paintOn(QVector2D position);
    void eraseOn(QVector2D position);
    void colorPickOn(QVector2D position);

};

#endif // SPRITEEDITOR_H
