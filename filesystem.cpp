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
        QImage target = frame->getImage();
        frameWriter(frameObject,target);
        frameArray.append(frameObject);
    }
    json["frames"] = frameArray;

}

void FileSystem:: frameWriter(QJsonObject &json, const QImage& image)
{
    std::vector<std::vector<std::vector<int>>> colorMatrix = getColorMatrix(image);
    json["frame"] = QString::fromStdString(std::string(colorMatrix.begin(),colorMatrix.end()));
}

std::vector<std::vector<std::vector<int>>> FileSystem:: getColorMatrix(const QImage &image)
{
    int width =image.width();
    int height = image.height();
    std::vector<std::vector<std::vector<int>>> result;
    for(int i = 0; i < width; i++)
    {
        for(int j =0; j < height; j++ )
        {
            std::vector<int> color = {image.pixelColor(i,j).alpha(),image.pixelColor(i,j).red(),image.pixelColor(i,j).green(),image.pixelColor(i,j).blue()};
            result[i][j] = color;
        }
    }
    return result;
}
