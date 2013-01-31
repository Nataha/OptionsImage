#include <QtGui>
#include <QApplication>

#include <QtCore/QFile>
#include <QtCore/QTextStream>


//#include "ui_mainwindow.h"
#include <iostream>

/**/

class Widget : public QWidget
{
public:
    Widget(QImage &img)
    {
        this->img = img;
    }

private:
    char matrix[100][100][3];
    QImage img;
protected:
    void paintEvent(QPaintEvent *)
    {
        QColor color;
        img.load("pixel100.jpg");
        for(int i = 0; i < img.width(); ++i)
        {
            for(int j = 0; j < img.height(); ++j)
            {
                img.pixel(i, j);
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

    }
public:
    void WriteFile()
    {
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
    QImage img("pixel100.jpg");
    QApplication a(argc, argv);
    Widget widget(img);

    //widget.show();
    widget.WriteFile();

    return a.exec();
}
/**/
