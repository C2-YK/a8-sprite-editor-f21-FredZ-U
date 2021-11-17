#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>
#include <QImage>
#include <QColor>
#include <QVector2D>
#include <QPainter>
#include <QMouseEvent>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class Viewer; }
QT_END_NAMESPACE

class Viewer : public QMainWindow
{
    Q_OBJECT

public:
    Viewer(QWidget *parent = nullptr);
    ~Viewer();
    void paintEvent(QPaintEvent *);
public slots:
    void playback(const QImage &frameImage);
    void updateEditor(const QImage &frameImage);
    void saveCallback(bool success);
    void loadCallback(bool success);
signals:
    void setPlaybackSpeed(int speed);
    void startPlayback(bool);
    void addFrame();
    void moveFrame(int from, int to);
    void deleteFrame();
    void setEditingFrame(int);
    void setMaxFramesSize(int size);
    void resize(int height, int width);
    void setBrushColor(QColor);
    void setBrushSize(int size);
    void useToolOn(QPoint position);
    void switchToolTo(int toolIndex);
    void saveSprite(QString filename);
    void loadJason(QString filepath);
private:
    Ui::Viewer *ui;
    QPixmap canvas;
    QImage image;
    QPoint drawingPivot;
    int pixelSize;
    int pixelOffset;
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};
#endif // VIEWER_H
