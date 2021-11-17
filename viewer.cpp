#include "viewer.h"
#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Viewer)
{
    ui->setupUi(this);
    drawingPivot = QPoint(40,40);
    pixelSize = 20;
    pixelOffset = 1;

    QListWidgetItem *item = new QListWidgetItem;
    item->setText("test");
    item->setData(0, frameList.size());
    ui->listWidget->addItem(item);
    ui->listWidget->setIconSize(QSize(16,16));
    frameList.append(item);

    connect(ui->addFrame, &QPushButton::released, this, &Viewer::on_addFrameButton_Clicked);

    connect(ui->pencilButton, &QPushButton::released, this, [this](){
        emit switchToolTo(0);});
    connect(ui->eraserButton, &QPushButton::released, this, [this](){
        emit switchToolTo(1);});
    connect(ui->colorPickerButton, &QPushButton::released, this, [this](){
        emit switchToolTo(2);});
    connect(ui->bucketButton, &QPushButton::released, this, [this](){
        emit switchToolTo(3);});
}

Viewer::~Viewer()
{
    delete ui;
}

void Viewer::playback(const QImage &frameImage){

}
void Viewer::updateEditor(const QImage &frameImage, int editingTarget){
    image = frameImage;
    QPixmap p = QPixmap::fromImage(frameImage);
    p.scaled(10, 10);
    frameList[editingTarget]->setIcon(QIcon(p));
    update();

}
void Viewer::saveCallback(bool success){

}
void Viewer::loadCallback(bool success){

}


void Viewer::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){//if mouse left button clicked
        QPoint screenPos = event -> pos();
        pixelPos = QPoint((screenPos.x()-drawingPivot.x())/(pixelSize+pixelOffset), (screenPos.y()-drawingPivot.y())/(pixelSize+pixelOffset));
        emit useToolOn(pixelPos);//get mouse position as start point
    }else if(event->button() == Qt::RightButton){
        movePivot = event->pos();
    }

}



void Viewer::mouseMoveEvent(QMouseEvent * event){
    if(event->buttons()&Qt::LeftButton){//if mouse left button clicked and move at same time
        QPoint screenPos = event -> pos();
        if(pixelPos != QPoint((screenPos.x()-drawingPivot.x())/(pixelSize+pixelOffset), (screenPos.y()-drawingPivot.y())/(pixelSize+pixelOffset))){
            pixelPos = QPoint((screenPos.x()-drawingPivot.x())/(pixelSize+pixelOffset), (screenPos.y()-drawingPivot.y())/(pixelSize+pixelOffset));
            emit useToolOn(pixelPos);
        }
    }else{
        drawingPivot += event->pos() - movePivot;
        movePivot = event->pos();
        repaint();
    }


}

void Viewer::wheelEvent(QWheelEvent * event){
    //scale function
    pixelSize += event->angleDelta().y()/120;
    repaint();
}


void Viewer::paintEvent(QPaintEvent *){


    QPainter painter(this);
    int pos = pixelSize+pixelOffset;
    for(int i = 0; i < image.width(); i++){
        for(int j = 0; j < image.height(); j++){
            painter.fillRect(i * pos + drawingPivot.x(), j * pos + drawingPivot.y(), pixelSize, pixelSize, image.pixelColor(i, j));
        }
    }

}

void Viewer::on_colorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white);
    emit setBrushColor(color);
}

void Viewer::on_addFrameButton_Clicked(){
    QListWidgetItem *item = new QListWidgetItem;
    item->setText("test");
    item->setData(0, frameList.size());
    ui->listWidget->addItem(item);
    ui->listWidget->setIconSize(QSize(16,16));
    frameList.append(item);
    emit addFrame();
}

