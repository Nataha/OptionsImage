//
//

#include <QtGui>
#include <QApplication>
#include <iostream>
#include <QFile>
#include <QDebug>
/**/
class Widget : public QWidget
{
    /*Widget()
    {
    }*/
public:
//    unsigned char matrix[100][100][3];
    int*** create(int m, int n, int)
    {
        int*** matrix = new int**[m];
        for(int i = 0; i < m; ++i)
        {
            matrix[i] = new int*[n];
            for(int j = 0; j < n; ++j)
            {
                matrix[i][j] = new int[3];
                for(int k = 0; k < 3; ++k)
                    matrix[i][j][k] = 0;
            }
        }
        return matrix;
    }

public:
    void ReadFile()
    {
        QFile file("img.txt");
        file.open(QIODevice::ReadOnly);
        int r, g, b;
        int i = 0, j = 0;
//        QPainter paint;
//        QImage img;
        QString alldata = QString(file.readAll());
        QStringList lines = alldata.split("\n");
        foreach(QString s, lines)
        {
            QStringList pixels = s.split("],[");
            i = 0;
            foreach(QString d, pixels)
            {
                QStringList color = d.split(",");
                QString str = color.at(0);
                r = str.replace("[","").toInt();
                g = color.at(1).toInt();
                str = color.at(2);
                b = str.replace("]","").toInt();

                matrix[i][j][0] = r;
                matrix[i][j][1] = g;
                matrix[i][j][2] = b;
                ++i;

//                img.setPixel(i, j, qRgb(matrix[i][j][0], matrix[i][j][1], matrix[i][j][2]));
//                paint.drawImage(i, j, img);
            }
            ++j;
        }
    }
//public:
    QImage Matrix2Image()
    {
        QImage img/*(matrix, 100, 100, QImage::Format_ARGB32)*/;
//        QImage scaled = img.scaled(100, 100);
//        QPixmap pix = QPixmap::fromImage(img);

        int width, height;
        matrix[width][height][3];
        for(int i = 0; i < width;  ++i)
        {
            for(int j = 0; j < height;  ++j)
            {
                img.setPixel(i, j, qRgb(matrix[i][j][0], matrix[i][j][1], matrix[i][j][2]));
            }
        }
        return img;
    }

    void memfree(int*** matrix, int m, int n){
            for(int i = 0; i < m ; ++i){
                for(int j = 0; j < n; ++j)
                            delete[] matrix[i][j];
                delete[] matrix[i];
              }
        delete[] matrix;
    }
};
/**/

int main(int argc, char** argv )
{
    QApplication a(argc, argv);
    Widget widget;
    widget.ReadFile();
    widget.show();

    return a.exec();

}
/**/
