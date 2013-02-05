#include <QtGui>
#include <QApplication>
#include <QRgb>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include <iostream>

/**/

class Widget : public QWidget
{
public:
    Widget()
    {
        img.load("pixel100.jpg");
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
    QImage img;
    //matrix transposition
public:
    void TranMatrix()
    {
        for (int i = 0; i < width; i++)
        {
            for(int j = i; j < height; j++)
            {
                unsigned char matrix2[100][100][3];
                char r, g, b;
                r = matrix[i][j][0];
                g = matrix[i][j][1];
                b = matrix[i][j][2];
                matrix[i][j][0] = matrix[j][i][0];
                matrix[i][j][1] = matrix[j][i][1];
                matrix[i][j][2] = matrix[j][i][2];
                /*matrix[j][i][0] = r;
                matrix[j][i][1] = g;
                matrix[j][i][2] = b;*/

                matrix2[j][i][0] = r;
                matrix2[j][i][1] = g;
                matrix2[j][i][2] = b;

                matrix[j][i][0] = matrix2[j][i][0];
                matrix[j][i][1] = matrix2[j][i][1];
                matrix[j][i][2] = matrix2[j][i][2];

                //img.setPixel(i, j, QColor::fromRgb(matrix[j][i][0],matrix[j][i][1],matrix[j][i][2]).argb);
                ///ошибка: 'class QColor' has no member named 'argb'
                img.setPixel(i, j, qRgb(matrix[j][i][0],matrix[j][i][1],matrix[j][i][2]));
            }
        }
    }

public:
    void WriteFile()
    {
        QFile file("img.txt");
        file.open(QIODevice::WriteOnly);
        bool f;

        for (int i = 0; i < width; i++)
        {
            f = false;
            for (int j = 0; j < height; j++)
            {
                if (f)
                {
                    file.write(",");
                }
                else
                {
                    f = true;
                }
                file.write(QString("[" + QString::number(
                                       (int)matrix[i][j][0]) + "," + QString::number(
                                       (int)matrix[i][j][1]) + "," + QString::number(
                                       (int)matrix[i][j][2]) + "]").toUtf8());
            }
            file.write("\n");
        }
        file.close();
    }
};



/**/
int main(int argc, char** argv )
{
    QApplication a(argc, argv);
    Widget widget;

    widget.show();
    widget.TranMatrix();
    widget.WriteFile();

    return a.exec();
}
/**/
