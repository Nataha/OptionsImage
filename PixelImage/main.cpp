#include <QtGui>
#include <QApplication>

#include <QtCore/QFile>
#include <QtCore/QTextStream>


//#include "ui_mainwindow.h"
//#include <iostream>

/**/
class Widget : public QWidget
{
protected:
    void paintEvent(QPaintEvent *)
    {
        char matrix[100][100][3];
        QImage img("pixel100.jpg");

        QColor color;

        for(int i = 0; i < img.width(); ++i)
        {
            for(int j = 0; j < img.height(); ++j)
            {
                //img.pixel(i, j);
                int x, y, z;
                QRgb rgb = img.pixel(i,j);
                x = qRed(rgb);
                y = qGreen(rgb);
                z = qBlue(rgb);
                matrix[i][j][0] = x;
                matrix[i][j][1] = y;
                matrix[i][j][2] = z;
                color.getRgb(&x, &y, &z);
            }
        }

        QFile file("img.txt");
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        for (int i = 0; i < img.width(); i++)
        {
            for (int j = 0; j < img.height();j++)
            {
                out << matrix[i][j][0];
                out << matrix[i][j][1];
                out << matrix[i][j][2];
            }
        }
        //out.flush();

        //file.write(matrix);
        file.close();
    }
};
/**/
int main(int argc, char** argv )
{
    QApplication a(argc, argv);
    QWidget widget;
    widget.show();

    return a.exec();
}
