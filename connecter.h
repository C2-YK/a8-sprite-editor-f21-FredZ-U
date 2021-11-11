#ifndef CONNECTER_H
#define CONNECTER_H

#include <QObject>
#include "filesystem.h"
#include "sprite.h"
#include "previewer.h"
#include "viewer.h"
#include "spriteeditor.h"
/*
 * Connecter is a collection of connecting methods and store static object data
 */
class Connecter : public QObject
{
    Q_OBJECT
public:
    Connecter();
    void show();
private:
    Sprite targetSprite;
    Previewer previewer;
    FileSystem filesystem;
    SpriteEditor spriteEditor;
    Viewer viewer;
    void connectViewToPreviewer();
    void connectViewToSpriteEditor();
    void connectViewToFilesystem();
};

#endif // CONNECTER_H
