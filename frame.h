#ifndef FRAME_H
#define FRAME_H
#include <QImage>

class Frame
{
public:
    Frame(int height, int width);
    ~Frame();
    Frame(const Frame& other);
    Frame& operator=(Frame other);
    const QImage& getImage();
    void resize(int height, int width);
private:
    QImage image;
    int height;
    int width;
};

#endif // FRAME_H
