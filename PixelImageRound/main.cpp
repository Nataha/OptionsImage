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
private:
    unsigned char matrix[100][100][3];
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
        QImage img;
//        int width, height;
        img.width();
        img.height();
        for(int i = 0; i < img.width();  ++i)
        {
            for(int j = 0; j < img.height();  ++j)
            {
                img.setPixel(i, j, qRgb(matrix[i][j][0], matrix[i][j][1], matrix[i][j][2]));
            }
        }
        return img;
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
