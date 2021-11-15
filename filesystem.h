#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QString>
#include "sprite.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
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
    void frameWriter(QJsonObject &json);
    void qImageWriter(QJsonObject &json);
};

#endif // FILESYSTEM_H
