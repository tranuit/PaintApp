
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class RectangleWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setPen(Qt::black);             // Set pen color
        painter.setBrush(Qt::red);             // Set brush color
        painter.drawRect(50, 50, 200, 100);    // Draw a rectangle (x, y, width, height)
    }
};

class CircleWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing); // Chống răng cưa
        painter.setPen(Qt::blue);                      // Viền màu xanh dương
        painter.setBrush(Qt::yellow);                  // Tô màu vàng
        painter.drawEllipse(50, 50, 100, 100);         // (x, y, width, height) → hình tròn khi width = height
    }
};

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RectangleWidget *rec;
    CircleWidget *circle;

};

#endif // MAINWINDOW_H
