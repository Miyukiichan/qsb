#ifndef FULLSCREENWINDOW_H
#define FULLSCREENWINDOW_H

#include <QWidget>
#include <QWebEngineView>

class FullScreenWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FullScreenWindow(QWebEngineView *oldView, QWidget *parent = nullptr);
    ~FullScreenWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QWebEngineView *m_view;
    QWebEngineView *m_oldView;
    QRect m_oldGeometry;
};

#endif
