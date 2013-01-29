#include <QtGui>
#include <QApplication>

void


int main(int argc, char** argv )
{
    QApplication a(argc, argv);
    QPixmap img;
    img.load("pixel100.jpg");

    return a.exec();
}
