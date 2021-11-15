#include "filesystem.h"


FileSystem::FileSystem()
{

}

void FileSystem::setSprite(Sprite* target){

    sprite = target;

}

void FileSystem::loadJason(QString filepath){



}

void FileSystem::saveSprite(QString filename){


    QFile saveFile(filename);

    if(!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Could not open save file.");
        return;
    }

    QJsonObject spriteObject;
    //write method
    spriteWriter(spriteObject);
    QJsonDocument saveDoc(spriteObject);
    saveFile.write(saveDoc.toJson());
}

void FileSystem:: spriteWriter(QJsonObject &json){

    json["height"] = sprite->getHeight();
    json["width"] = sprite->getWidth();
    json["numberOfFrames"] = sprite->getMaxFrame();

    QJsonArray frameArray;
    foreach(Frame* frame, sprite->getFrames())
    {
        QJsonObject frameObject;
        frameWriter(frameObject);
        frameArray.append(frameObject);
    }
    json["frames"] = frameArray;

}

void FileSystem:: frameWriter(QJsonObject &json)
{
    QJsonObject qImageObject;
    qImageWriter(qImageObject);
    json["frame"] = qImageObject;
}

void FileSystem:: qImageWriter(QJsonObject &json)
{
    QJsonArray pixelArray;
    foreach(pixel)
}
