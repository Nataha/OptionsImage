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
<<<<<<< HEAD
        img.load("pixel100.jpg");
        width = img.width();
        height = img.height();

=======
        QImage img("pixel100.jpg");
        width = img.width();
        height = img.height();
>>>>>>> c084c0c2c6f94701e997a5fa08f4f6486a6f6e1f
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
<<<<<<< HEAD
    QImage img;
    //matrix transposition
public:
    void TranMatrix()
    {
        for (int i = 0; i < width; i++)
        {
            for(int j = i; j < height; j++)
            {
                char r, g, b;
                r = matrix[i][j][0];
                g = matrix[i][j][1];
                b = matrix[i][j][2];
                matrix[i][j][0] = matrix[j][i][0];
                matrix[i][j][1] = matrix[j][i][1];
                matrix[i][j][2] = matrix[j][i][2];
                matrix[j][i][0] = r;
                matrix[j][i][1] = g;
                matrix[j][i][2] = b;
                //img.setPixel(i, j, QColor::fromRgb(matrix[j][i][0],matrix[j][i][1],matrix[j][i][2]).argb);
                ///ошибка: 'class QColor' has no member named 'argb'
                img.setPixel(i, j, qRgb(matrix[j][i][0],matrix[j][i][1],matrix[j][i][2]));//QImage::Format_ARGB32
                //img.fill(qRgb(matrix[j][i][0],matrix[j][i][1],matrix[j][i][2]));
            }
        }
    }

=======
>>>>>>> c084c0c2c6f94701e997a5fa08f4f6486a6f6e1f
public:
    void WriteFile()
    {
        QFile file("img.txt");
        file.open(QIODevice::WriteOnly);
        bool f;
<<<<<<< HEAD

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
=======
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
>>>>>>> c084c0c2c6f94701e997a5fa08f4f6486a6f6e1f
            }
            file.write("\n");
        }
        file.close();
    }
};



/**/
int main(int argc, char** argv )
{
<<<<<<< HEAD
=======
    /*QFile file;
    file.open(stdin, QFile::ReadOnly);

    ReadFile();

    return 0;*/
>>>>>>> c084c0c2c6f94701e997a5fa08f4f6486a6f6e1f
    QApplication a(argc, argv);
    Widget widget;

    widget.show();
    widget.TranMatrix();
    widget.WriteFile();

    return a.exec();
}
