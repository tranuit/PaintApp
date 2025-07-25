
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

class TriangleWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);

        // Tạo tam giác bằng QPolygon
        QPolygon triangle;
        triangle << QPoint(width() / 2, 10)              // đỉnh trên
                 << QPoint(10, height() - 10)            // đáy trái
                 << QPoint(width() - 10, height() - 10); // đáy phải

        // Vẽ tam giác
        painter.setBrush(Qt::yellow);  // màu nền tam giác
        painter.setPen(Qt::black);     // viền
        painter.drawPolygon(triangle);
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
    TriangleWidget *triangle;

};

#endif // MAINWINDOW_H
