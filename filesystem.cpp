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
    QJsonDocument saveDoc(spriteObject);
    saveFile.write(saveDoc.toJson());

}
