#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "sprite.h"

class FileSystem
{
public:
    FileSystem(Sprite*);
    FileSystem();
    void setSprite(Sprite*);
public:
    void loadJason(QString filepath, Sprite &sprite);
    void saveSprite(QString filename);
private:
    Sprite* sprite;
    void spriteWriter(QJsonObject &json);
    void frameWriter(QJsonObject &json,const QImage &image);
    void spriteReader(const QJsonObject &json, Sprite &s);
    void frameReader(const QJsonObject &json, Frame& frame,int,int);
    //std::vector<std::vector<std::vector<int>>> getColorMatrix(const QImage &image);
};

#endif // FILESYSTEM_H
