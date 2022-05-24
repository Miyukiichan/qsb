#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWidget * w = new MainWidget(NULL);
    try {
      w->show();
      return a.exec();
    }
    catch(int e) {
      delete w;
    }
}


