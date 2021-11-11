#ifndef LAYER_H
#define LAYER_H
#include <QList>
#include <QColor>
#include <QVector2D>

class Layer
{
public:
    Layer();
    ~Layer();
    Layer(const Layer& other);
    Layer& operator=(Layer other);
    int width;
    int hight;
    QList<int> RGBA;
    void setPixel(QVector2D pixel2DPosition); //pixel2DPosition[0] = x [1] = y
    void resize(int width, int hight);
    QColor getRGBA(QVector2D pixel2DPosition);

};

#endif // LAYER_H
