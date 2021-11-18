#include "filesystem.h"
#include <QDebug>
#include <QDir>
FileSystem::FileSystem()
{

}

FileSystem::FileSystem(Sprite* target)
{
    sprite = target;
}

void FileSystem::setSprite(Sprite* target){

    sprite = target;

}

void FileSystem::loadJason(QString filepath){

    QFile loadFile(filepath);
    qDebug()<<filepath;

    if(!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("Could not open the file.");
        return;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    spriteReader(loadDoc.object(),*sprite);
    emit loadCallback(true);
}

void FileSystem::saveSprite(QString filename, QString fileDir){


    QFile saveFile(fileDir+"/"+filename);
    if(!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Could not open save file.");
        return;
    }
    QJsonObject spriteObject;
    spriteWriter(spriteObject);
    QJsonDocument saveDoc(spriteObject);
    saveFile.write(saveDoc.toJson());
    emit saveCallback(true);
}

void FileSystem:: spriteWriter(QJsonObject &json){

    json["height"] = sprite->getHeight();
    json["width"] = sprite->getWidth();
    json["numberOfFrames"] = sprite->getMaxFrame();
    QJsonArray frameArray;
    foreach(Frame* frame, sprite->getFrames())
    {
        if(frame != nullptr)
        {
            QJsonObject frameObject;
            QImage target = frame->getImage();
            frameWriter(frameObject,target);
            frameArray.append(frameObject);
        }
    }
    json["frames"] = frameArray;
}

void FileSystem:: frameWriter(QJsonObject &json, const QImage& image)
{
    int width =image.width();
    int height = image.height();
    int colorMatrix[width][height][4];
    for(int i = 0; i < width; i++)
    {
        for(int j =0; j < height; j++ )
        {
            colorMatrix[i][j][0] = image.pixelColor(i,j).red();
            colorMatrix[i][j][1] = image.pixelColor(i,j).green();
            colorMatrix[i][j][2] = image.pixelColor(i,j).blue();
            colorMatrix[i][j][3] = image.pixelColor(i,j).alpha();
        }
    }
    QString frameInfo;
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++ )
        {
            frameInfo.append(QString::number(colorMatrix[i][j][0]));
            frameInfo.append(" ");
            frameInfo.append(QString::number(colorMatrix[i][j][1]));
            frameInfo.append(" ");
            frameInfo.append(QString::number(colorMatrix[i][j][2]));
            frameInfo.append(" ");
            frameInfo.append(QString::number(colorMatrix[i][j][3]));
            frameInfo.append(" ");
        }
    }
    json["frame"] = frameInfo;

}

void FileSystem:: spriteReader(const QJsonObject &json, Sprite &sprite)
{
    int height = json["height"].toInt();
    int width = json["width"].toInt();
    int maxFrame = json["numberOfFrames"].toInt();
    QList<Frame*> frames;

    Frame* frame;

    QJsonArray frameArray = json["frames"].toArray();
    for(int frameIndex = 0; frameIndex < frameArray.size(); frameIndex++)
    {
        QJsonObject frameObject = frameArray[frameIndex].toObject();
        frame = new Frame(frameReader(frameObject,width,height));
        qDebug()<<frame->getImage();
        qDebug()<<frame->getImage().pixelColor(0,0).alpha();
        qDebug()<<frame->getImage().pixelColor(0,0).red();
        qDebug()<<frame->getImage().pixelColor(0,0).green();
        qDebug()<<frame->getImage().pixelColor(0,0).blue();
        frames.append(frame);
        qDebug()<<frames[0];
        qDebug()<<frames[0]->getImage();
    }
    qDebug()<<frames[0];
    qDebug()<<frames[0]->getImage();
    sprite = Sprite(height, width, frames, maxFrame);
}

Frame FileSystem::frameReader(const QJsonObject &json,int width, int height)
{
    QString s = json["frame"].toString();
    //qDebug()<<s;
    QStringList colorList = s.split(QRegularExpression("\\W+"),Qt::SkipEmptyParts);
    //qDebug()<<colorList;
    int numberOfColors = width*height*4;
    int colorArray[numberOfColors];
    int colorArrayIndex = 0;
    foreach(QString string,colorList)
    {
        colorArray[colorArrayIndex] = string.toInt();
        colorArrayIndex++;
    }
    int colorMatrix[width][height][4];
    colorArrayIndex = 0;
    //qDebug()<<colorArrayIndex;
    for(int i = 0; i < width; i++)
    {
        //qDebug()<<colorArrayIndex;
        for(int j =0; j < height; j++ )
        {
            colorMatrix[i][j][0] = colorArray[colorArrayIndex];
            colorArrayIndex++;
            colorMatrix[i][j][1] = colorArray[colorArrayIndex];
            colorArrayIndex++;
            colorMatrix[i][j][2] = colorArray[colorArrayIndex];
            colorArrayIndex++;
            colorMatrix[i][j][3] = colorArray[colorArrayIndex];
            colorArrayIndex++;
        }

    }
    //qDebug()<<colorArrayIndex;

    QImage toBeSet(width,height,QImage::Format_ARGB32);
    for(int i = 0; i < width; i++)
    {
        for(int j =0; j < height; j++ )
        {
            toBeSet.setPixelColor(i,j,QColor(
                                  colorMatrix[i][j][0],
                                  colorMatrix[i][j][1],
                                  colorMatrix[i][j][2],
                                  colorMatrix[i][j][3]));
        }
    }
//    qDebug()<<toBeSet;
//    qDebug()<<toBeSet.pixelColor(0,0).alpha();
//    qDebug()<<toBeSet.pixelColor(0,0).red();
//    qDebug()<<toBeSet.pixelColor(0,0).green();
//    qDebug()<<toBeSet.pixelColor(0,0).blue();
    return Frame(height,width,toBeSet);


}


