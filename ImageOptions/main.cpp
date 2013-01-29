//
//
/*
#include <QtGui>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QLabel plbl;
    QPixmap pix("image.jpg");
    plbl.setPixmap(pix);
    plbl.show();

    return app.exec();
}
/**/

#include <QApplication>
#include <QWidget>
#include <QPainter>

class Widget : public QWidget
{
protected:

  void paintEvent(QPaintEvent*)
  {
    QPainter painter(this);
    QPixmap img("image.jpg");

    painter.drawPixmap(0, 0, img);

    QMatrix m;
    m.rotate(180.0);
    img = img.transformed(m);
    painter.drawPixmap(img.width(), 0, img);

  }
};

int main(int argc, char **argv)
{
  QApplication a(argc, argv);

  Widget widget;
  widget.resize(widget.width(), widget.height());
  widget.show();

  return a.exec();
}
/**/
