#ifndef FRAME_H
#define FRAME_H
#include "layer.h"
#include <QList>

class Frame
{
public:
    Frame();
    ~Frame();
    Frame(const Frame& other);
    Frame& operator=(Frame other);
    Layer masterLayer; //for one layer support, we just use master to edit and render
    //QList<Layer*> layers;
    //int editing;
    //ignore below before importment multi layers support
    //void pushNewLayer();
    //void sawpLayer(int layer1, int layer2);
    //void popLayer();
    //void setTarget(int target);
private:
    //void updateMaster();
    //void layersBlending();


};

#endif // FRAME_H
