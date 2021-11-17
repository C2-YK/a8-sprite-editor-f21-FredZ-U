#include "connecter.h"

Connecter::Connecter()
{
    //targetSprite = Sprite(300, 500);
    //set target sprite
    filesystem.setSprite(&targetSprite);
    previewer.setSprite(&targetSprite);
    spriteEditor.setSprite(&targetSprite);
    //connection
    connectViewToFilesystem();
    connectViewToPreviewer();
    connectViewToSpriteEditor();
    connectSpriteEditorToPreviewer();
    spriteEditor.updatePreviewer();
}

void Connecter::show(){
    viewer.show();
}
void Connecter::connectViewToFilesystem(){
    QObject::connect(&viewer, &Viewer::saveSprite, &filesystem, &FileSystem::saveSprite);
    QObject::connect(&viewer, &Viewer::loadJason, &filesystem, &FileSystem::loadJason);
    QObject::connect(&filesystem, &FileSystem::loadCallback, &viewer, &Viewer::loadCallback);
    QObject::connect(&filesystem, &FileSystem::saveCallback, &viewer, &Viewer::saveCallback);
}
void Connecter::connectViewToPreviewer(){
    QObject::connect(&previewer, &Previewer::playback, &viewer, &Viewer::playback);
    QObject::connect(&previewer, &Previewer::updateEditorWindow, &viewer, &Viewer::updateEditor);
    QObject::connect(&viewer, &Viewer::startPlayback, &previewer, &Previewer::startPlayback);
    QObject::connect(&viewer, &Viewer::setPlaybackSpeed, &previewer, &Previewer::setPlaybackSpeed);
}
void Connecter::connectViewToSpriteEditor(){
    //frame setting
    QObject::connect(&viewer, &Viewer::addFrame, &spriteEditor, &SpriteEditor::addFrame);
    QObject::connect(&viewer, &Viewer::deleteFrame, &spriteEditor, &SpriteEditor::deleteFrame);
    QObject::connect(&viewer, &Viewer::moveFrame, &spriteEditor, &SpriteEditor::moveFrame);
    QObject::connect(&viewer, &Viewer::setEditingFrame, &spriteEditor, &SpriteEditor::setEditingFrame);
    //tool setting
    QObject::connect(&viewer, &Viewer::useToolOn, &spriteEditor, &SpriteEditor::useToolOn);
    QObject::connect(&viewer, &Viewer::switchToolTo, &spriteEditor, &SpriteEditor::switchToolTo);
    QObject::connect(&viewer, &Viewer::setBrushColor, &spriteEditor, &SpriteEditor::setBrushColor);
}

void Connecter::connectSpriteEditorToPreviewer(){
    QObject::connect(&spriteEditor, &SpriteEditor::updatePreviewer, &previewer, &Previewer::updatePreviewer);
}
