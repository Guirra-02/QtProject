#ifndef AXWIDGET_H
#define AXWIDGET_H
#include <ActiveQt/QAxWidget>
#include "windows.h"
#include "mainwindow.h"
class WebAxWidget : public QAxWidget
{
public:

    WebAxWidget(QWidget *parent = nullptr, Qt::WindowFlags f = 0)
        : QAxWidget(parent, f)
    {
    }
protected:
    bool translateKeyEvent(int message, int keycode) const Q_DECL_OVERRIDE
    {
        if (message >= WM_KEYFIRST && message <= WM_KEYLAST)
            return true;
        return QAxWidget::translateKeyEvent(message, keycode);
    }

};


#endif // AXWIDGET_H
