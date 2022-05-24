#include "fullscreenwindow.h"
#include <QAction>

FullScreenWindow::FullScreenWindow(QWebEngineView *oldView, QWidget *parent)
    : QWidget(parent)
    , m_view(new QWebEngineView(this))
    , m_oldView(oldView)
    , m_oldGeometry(oldView->window()->geometry())
{

    auto exitAction = new QAction(this);
    exitAction->setShortcut(Qt::Key_Escape);
    connect(exitAction, &QAction::triggered, [this]() {
        m_view->triggerPageAction(QWebEnginePage::ExitFullScreen);
    });
    addAction(exitAction);

    m_view->setPage(m_oldView->page());
    setGeometry(m_oldGeometry);
    showFullScreen();
    m_oldView->window()->hide();
}

FullScreenWindow::~FullScreenWindow()
{
    m_oldView->setPage(m_view->page());
    m_oldView->window()->setGeometry(m_oldGeometry);
    m_oldView->window()->show();
    hide();
}

void FullScreenWindow::resizeEvent(QResizeEvent *event)
{
    QRect viewGeometry(QPoint(0, 0), size());
    m_view->setGeometry(viewGeometry);
    QWidget::resizeEvent(event);
}
