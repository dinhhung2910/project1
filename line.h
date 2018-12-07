#ifndef LINE_H
#define LINE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Line : public QWidget
{
public:
    Line(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
};

#endif // LINE_H
