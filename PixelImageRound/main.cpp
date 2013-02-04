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
    QString line;
    unsigned char matrix[100][100][3];
    int width, height;
public:
    void ReadFile()
    {
        QFile file("new.txt");
        file.open(QIODevice::ReadOnly);

        QString line = file.readAll();
        QStringList result;
        while (!line.isNull()) {
            line.remove(QRegExp("[],"));
            result.append(line);
            line = file.readAll();
        }
        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                QImage img;
                img.setPixel(i, j, qRgb(matrix[i][j][0], matrix[i][j][1], matrix[i][j][2]));
            }
        }
        qDebug() << result;
        /*QString alldata = QString(file.readAll());
        QStringList lines = alldata.split("\n");
        foreach(QString s, lines)
        {
            QStringList pixels = s.split(",");
        }*/
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
