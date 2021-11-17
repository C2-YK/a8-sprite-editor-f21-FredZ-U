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
    Frame(const Frame& other);
    Frame& operator=(Frame other);
    const QImage& getImage();
    void resize(int height, int width);
    void paintOn(QPoint position, QColor brushColor);
    void eraseOn(QPoint position);
    void bucketOn(QPoint position, QColor brushColor);
    QColor colorPickOn(QPoint position);
    int getHeight();
    int getWidth();


private:
    QImage image;
    int height;
    int width;
    void bucketRecursive(int x, int y, QColor target, QColor overWrite);
};

#endif // FRAME_H
