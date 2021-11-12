#include "viewer.h"
#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Viewer)
{
    ui->setupUi(this);
}

Viewer::~Viewer()
{
    delete ui;
}

void Viewer::playback(const QImage &frameImage){

}
void Viewer::updateEditor(const QImage &frameImage){

}
void Viewer::saveCallback(bool success){

}
void Viewer::loadCallback(bool success){

}

