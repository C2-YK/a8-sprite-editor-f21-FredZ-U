#ifndef SPRITEEDITOR_H
#define SPRITEEDITOR_H

#include <QObject>
#include <QVector>

class SpriteEditor
{
    Q_OBJECT
public:
    SpriteEditor();
private:
    QVector<int> brushColor;
    QVector<int> brushAlpha; //size = brushSize^2
    int brushSize;

};

#endif // SPRITEEDITOR_H
