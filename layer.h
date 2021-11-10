#ifndef LAYER_H
#define LAYER_H
#include <QList>
#include <QVector>


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
    void setPixel(QVector<int> pixel2DPosition); //pixel2DPosition[0] = x [1] = y
    void resize(int width, int hight);
    QVector<int> getRGBA(QVector<int> pixel2DPosition);

};

#endif // LAYER_H
