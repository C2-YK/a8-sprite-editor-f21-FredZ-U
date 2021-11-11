#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>
#include <QImage>
#include <QColor>
#include <QVector2D>

QT_BEGIN_NAMESPACE
namespace Ui { class Viewer; }
QT_END_NAMESPACE

class Viewer : public QMainWindow
{
    Q_OBJECT

public:
    Viewer(QWidget *parent = nullptr);
    ~Viewer();
public slots:
    void playback(const QImage &frameImage);
    void updateEditor(const QImage &frameImage);
signals:
    void setPlaybackSpeed(int speed);
    void startPlayback(bool);
    void addFrame(int index);
    void moveFrame(int from, int to);
    void setEditingFrame(int);
    void setMaxFramesSize(int size);
    void resize(int height, int width);
    void setBrushColor(QColor);
    void setBrushSize(int size);
    void drawValueOn(QVector2D position);
    void saveSprite(QString filename);
    void loadJason(QString filepath);
private:
    Ui::Viewer *ui;
};
#endif // VIEWER_H
