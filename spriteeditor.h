#ifndef SPRITEEDITOR_H
#define SPRITEEDITOR_H
#include "sprite.h"
#include <QObject>
#include <QColor>

class SpriteEditor : public QObject
{
    Q_OBJECT
public:
    SpriteEditor();
    void setSprite(Sprite*);
public slots:
    void setEditingFrame(int);
    void setBrushColor(QColor);
    void setBrushSize(int size);
private:
    Sprite* target;
    QColor brushColor;
    QVector<int> brushAlpha; //size = brushSize^2
    int brushSize;

};

#endif // SPRITEEDITOR_H
