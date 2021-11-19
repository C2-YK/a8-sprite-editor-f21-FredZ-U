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

void FileSystem::saveSprite(QString filename){


    QFile saveFile(filename);
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
    int frameIndex;
    QJsonArray frameArray;
    foreach(Frame* frame, sprite->getFrames())
    {
        if(frame != nullptr)
        {
            QJsonObject frameObject;
            QImage target = frame->getImage();
            frameWriter(frameObject,target,frameIndex);
            frameArray.append(frameObject);
        }
    }
    json["frames"] = frameArray;
}

void FileSystem:: frameWriter(QJsonObject &json, const QImage& image, int frameIndex)
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
        frameInfo.append("[");
        for(int j = 0; j < height; j++ )
        {
            frameInfo.append("[");
            frameInfo.append(QString::number(colorMatrix[i][j][0]));
            frameInfo.append(" ");
            frameInfo.append(QString::number(colorMatrix[i][j][1]));
            frameInfo.append(" ");
            frameInfo.append(QString::number(colorMatrix[i][j][2]));
            frameInfo.append(" ");
            frameInfo.append(QString::number(colorMatrix[i][j][3]));
            frameInfo.append(" ");
            frameInfo.append("]");
        }
        frameInfo.append("]");
    }
    QString label = QStringLiteral("frame").append(QString::number(frameIndex));
    json[label] = frameInfo;

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
        frame = new Frame(frameReader(frameObject,width,height,frameIndex));
        frames.append(frame);
    }
    sprite = Sprite(height, width, frames, maxFrame);
}

Frame FileSystem::frameReader(const QJsonObject &json,int width, int height,int frameIndex)
{
    QString label = QStringLiteral("frame").append(QString::number(frameIndex));
    QString s = json[label].toString();
    QStringList colorList = s.split(QRegularExpression("\\W+"),Qt::SkipEmptyParts);
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
    for(int i = 0; i < width; i++)
    {
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
    return Frame(height,width,toBeSet);


}


