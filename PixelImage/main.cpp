#include <QtGui>
#include <QApplication>
//#include "ui_mainwindow.h"
#include <iostream>


 class Widget : public QWidget
{
 protected:
     void paintEvent(QPaintEvent *)
 {
     int x,y,z;
     QImage img("pixel100.jpg");
     //QSize size(width(), height());

     QColor color;
     color.getRgb(&x, &y, &z);
     QRgb rgb = qRgb(x, y, z);
     img.setPixel(img.width(), img.height(), rgb);
     char matrix[x][y][z];



     QFile file("img.txt");
     file.open(QIODevice::WriteOnly);
     QTextStream out(&file);
     out << matrix;
     //out.write(matrix);
     file.close();

 }
};

int main(int argc, char** argv )
{
    QApplication a(argc, argv);
    QWidget widget;
    widget.show();

    return a.exec();
}
