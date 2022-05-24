#include <QtWidgets>
#include <QWebEngineProfile>
#include <QWebEngineSettings>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QMainWindow(parent)
{
  QSize s = screen()->size();
  resize(s.width() * 0.8, s.height() * 0.8);
  _ev = new QWebEngineView(this);
  connect(_ev->page(), &QWebEnginePage::fullScreenRequested, this, &MainWidget::fullScreenRequested);
  _ev->settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);
  _ev->page()->profile()->setHttpUserAgent("Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0");
  _ev->load(QUrl("http://myanimelist.net"));
  //_ev->load(QUrl("https://youtube.com"));
  setCentralWidget(_ev);
  _ev->show();
}

// Destructor
MainWidget::~MainWidget()
{
  delete _ev;
}

void MainWidget::fullScreenRequested(QWebEngineFullScreenRequest request) {
  if (request.toggleOn()) {
    if (_fw)
      return;
    request.accept();
    _fw.reset(new FullScreenWindow(_ev));
  } 
  else {
    if (!_fw)
      return;
    request.accept();
    _fw.reset();
  }
}
