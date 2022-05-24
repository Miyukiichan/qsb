#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWebEngineView>
#include <QMainWindow>
#include <QWebEngineFullScreenRequest>
#include "fullscreenwindow.h"

class MainWidget : public QMainWindow {
  Q_OBJECT;

  public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

  private:
    QWebEngineView * _ev;
    QScopedPointer<FullScreenWindow> _fw;

  private slots:
    void fullScreenRequested(QWebEngineFullScreenRequest request);
};

#endif //MAINWIDGET_H
