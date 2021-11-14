#ifndef FRAME_H
#define FRAME_H
#include <QImage>
#include <QVector2D>
#include <QColor>
class Frame
{
public:
    Frame();
    Frame(int height, int width);
    Frame(int height, int width, QImage image);
    ~Frame();
    Frame(const Frame& other);
    Frame& operator=(Frame other);
    const QImage& getImage();
    void resize(int height, int width);
    void paintOn(QVector2D position, QColor brushColor, int brushSize);
    void eraseOn(QVector2D position, int brushSize);
    QColor colorPickOn(QVector2D position);
private:
    QImage image;
    int height;
    int width;
};

#endif // FRAME_H
