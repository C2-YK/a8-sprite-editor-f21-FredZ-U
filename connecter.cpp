#include "connecter.h"

Connecter::Connecter()
{
    //set target sprite
    filesystem.setSprite(&targetSprite);
    previewer.setSprite(&targetSprite);
    spriteEditor.setSprite(&targetSprite);
    //connection
    connectViewToFilesystem();
    connectViewToPreviewer();
    connectViewToSpriteEditor();
}

void Connecter::show(){
    viewer.show();
}
void Connecter::connectViewToFilesystem(){
    QObject::connect(&viewer, &Viewer::saveSprite, &filesystem, &FileSystem::saveSprite);
    QObject::connect(&viewer, &Viewer::loadJason, &filesystem, &FileSystem::loadJason);
}
void Connecter::connectViewToPreviewer(){
    QObject::connect(&previewer, &Previewer::playback, &viewer, &Viewer::playback);
    QObject::connect(&viewer, &Viewer::startPlayback, &previewer, &Previewer::startPlayback);
    QObject::connect(&viewer, &Viewer::setPlaybackSpeed, &previewer, &Previewer::setPlaybackSpeed);
}
void Connecter::connectViewToSpriteEditor(){

}
