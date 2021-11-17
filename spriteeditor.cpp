#include "spriteeditor.h"
#include <QtDebug>

SpriteEditor::SpriteEditor()
{
    toolSwitch = 0;
    brushColor = QColor(0,0,255,255);
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

void SpriteEditor::useToolOn(QPoint position){
    //if out of range ignore
    if(position.x() >= target->getCurrentFrame().getWidth() || position.x() < 0){
        return;
    }
    if(position.y() >= target->getCurrentFrame().getHeight() || position.y() < 0){
        return;
    }
    //if changed, update
    if(toolSwitch == 0){
        paintOn(position);
    }else if(toolSwitch == 1){
        eraseOn(position);
    }else if(toolSwitch==2){
        colorPickOn(position);
    }else{
        bucketOn(position);
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
    target->getCurrentFrame().paintOn(position, brushColor);
}
void SpriteEditor::eraseOn(QPoint position){
    target->getCurrentFrame().eraseOn(position);
}
void SpriteEditor::colorPickOn(QPoint position){
    brushColor = target->getCurrentFrame().colorPickOn(position);
}
void SpriteEditor::bucketOn(QPoint position){
    target->getCurrentFrame().bucketOn(position, brushColor);
}
