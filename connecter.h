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
class Connecter
{
    Q_OBJECT
public:
    Connecter();
private:
    Sprite targetSprite;
    Previewer previewer;
    FileSystem filesystem;
    SpriteEditor spriteEditor;
};

#endif // CONNECTER_H
