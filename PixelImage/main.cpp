#include <QtGui>
#include <QApplication>
#include <QRgb>
#include <QtCore/QFile>
#include <QtCore/QTextStream>


//#include "ui_mainwindow.h"
#include <iostream>

/**/

class Widget : public QWidget
{
public:
    Widget()
    {
        QImage img("pixel100.jpg");
        width = img.width();
        height = img.height();
        for(int i = 0; i < width; ++i)
        {
            for(int j = 0; j < height; ++j)
            {
                int x, y, z;
                QRgb rgb = img.pixel(i,j);
                x = qRed(rgb);
                y = qGreen(rgb);
                z = qBlue(rgb);
                matrix[i][j][0] = x;
                matrix[i][j][1] = y;
                matrix[i][j][2] = z;
            }
        }
    }

private:
    unsigned char matrix[100][100][3];
    int width, height;
public:
    void WriteFile()
    {
        QFile file("img.txt");
        file.open(QIODevice::WriteOnly);
        bool f;
        for (int i = 0; i < width; i++)
        {
            f = false;
            for (int j = 0; j < height;j++)
            {
                if (f) {
                    file.write(",");
                } else {
                    f = true;
                }
                file.write(QString("["+QString::number((int)matrix[i][j][0])+","+QString::number((int)matrix[i][j][1])+","+QString::number((int)matrix[i][j][2])+"]").toUtf8());
            }
            file.write("\n");
        }
        file.close();
    }
};
/*
//class Widget : public QWidget
//{
//protected:
    void ReadFile()
    {
        QFile file("img.txt");
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        //QTextStream out(&file);
        QString line = in.readAll();
        QChar ch;
        while(!in.atEnd())
        {
            in >> ch;
        }
        file.close();


    }
//};

/**/
int main(int argc, char** argv )
{
    /*QFile file;
    file.open(stdin, QFile::ReadOnly);

    ReadFile();

    return 0;*/
    QApplication a(argc, argv);
    Widget widget;

    widget.show();
    widget.WriteFile();

    return a.exec();
}
