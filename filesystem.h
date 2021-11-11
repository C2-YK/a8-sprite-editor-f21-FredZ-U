#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QString>
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
};

#endif // FILESYSTEM_H
