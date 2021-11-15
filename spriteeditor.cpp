#include "spriteeditor.h"
#include <QtDebug>

SpriteEditor::SpriteEditor()
{
    toolSwitch = 0;
    brushSize = 1;
    brushColor = QColor(255,255,255,255);
}

void SpriteEditor::setSprite(Sprite *target){
    this->target = target;
}

void SpriteEditor::setEditingFrame(int editing){
    target->setEditingTarget(editing);
}

void SpriteEditor::addFrame(){
    target->addFrame();
}

void SpriteEditor::deleteFrame(){
    target->deleteFrame();
}

void SpriteEditor::moveFrame(int from, int to){
    target->moveFrame(from, to);
}

void SpriteEditor::setBrushColor(QColor color){
    brushColor = color;
}

void SpriteEditor::setBrushSize(int size){
    brushSize = size;
}

void SpriteEditor::useToolOn(QPoint position){
    if(toolSwitch == 0){
        paintOn(position);
    }else if(toolSwitch == 1){
        eraseOn(position);
    }else{
        colorPickOn(position);
    }
    emit updatePreviewer();
}

void SpriteEditor::switchToolTo(int tool){
    toolSwitch = tool;
}
/*
 * private helper
 */
void SpriteEditor::paintOn(QPoint position){
    target->getCurrentFrame().paintOn(position, brushColor, brushSize);
}
void SpriteEditor::eraseOn(QPoint position){
    target->getCurrentFrame().eraseOn(position, brushSize);
}
void SpriteEditor::colorPickOn(QPoint position){
    brushColor = target->getCurrentFrame().colorPickOn(position);
}
