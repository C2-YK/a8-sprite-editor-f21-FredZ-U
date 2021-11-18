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

class FileSystem : public QObject
{
    Q_OBJECT
public:
    FileSystem(Sprite*);
    FileSystem();
    void setSprite(Sprite*);
public slots:
    void loadJason(QString filepath);
    void saveSprite(QString filename, QString fileDir);
signals:
    void loadCallback(bool success);
    void saveCallback(bool success);
private:
    Sprite* sprite;
    void spriteWriter(QJsonObject &json);
    void frameWriter(QJsonObject &json,const QImage &image);
    void spriteReader(const QJsonObject &json, Sprite &s);
    Frame frameReader(const QJsonObject &json,int,int);
    //std::vector<std::vector<std::vector<int>>> getColorMatrix(const QImage &image);
};

#endif // FILESYSTEM_H



