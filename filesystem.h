#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <vector>
#include "sprite.h"

class FileSystem : public QObject
{
    Q_OBJECT
public:
    FileSystem();
    void setSprite(Sprite*);
public slots:
    void loadJason(QString filepath);
    void saveSprite(QString filename);
signals:
    void loadCallback(bool success);
    void saveCallback(bool success);
private:
    Sprite* sprite;
    void spriteWriter(QJsonObject &json);
    void frameWriter(QJsonObject &json,const QImage &image);
    std::vector<std::vector<std::vector<int>>> getColorMatrix(const QImage &image);
};

#endif // FILESYSTEM_H
