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
    void paintOn(QPoint position, QColor brushColor, int brushSize);
    void eraseOn(QPoint position, int brushSize);
    QColor colorPickOn(QPoint position);
    int getHeight();
    int getWidth();


private:
    QImage image;
    int height;
    int width;
};

#endif // FRAME_H
