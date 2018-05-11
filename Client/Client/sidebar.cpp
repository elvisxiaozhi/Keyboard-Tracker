#include "sidebar.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QIcon>

Sidebar::Sidebar() : checkedAct(NULL)
{
    //hide dock widget title bar
    QWidget *titleBarWidget = new QWidget(this);
    setTitleBarWidget(titleBarWidget);
    this->titleBarWidget()->hide();
    setMinimumSize(200, 100);

    setMouseTracking(true);

    this->addAction(tr("Overview"), QIcon(":/Resources/Icons/home_24px.png"));
    this->addAction(tr("Dashboard"), QIcon(":/Resources/Icons/dashboard_24px.png"));
    this->addAction(tr("Users"), QIcon(":/Resources/Icons/users_24px.png"));
    this->addAction(tr("Settings"), QIcon(":/Resources/Icons/settings_24px.png"));
}

QAction *Sidebar::addAction(const QString &text, const QIcon &icon)
{
    QAction *action = new QAction(icon, text, this);
    action->setCheckable(true);
    actList.push_back(action);
    return action;
}

QAction *Sidebar::actionAt(const QPoint &point)
{
    int posY = 10;
    for(auto action : actList) {
        QRect actRect(0, posY, rect().width(), 30);
        if(actRect.contains(point)) {
            qDebug() << "True";
            return action;
        }
        posY += 50;
    }
    qDebug() << "False;";
    return NULL;
}

void Sidebar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), QColor(240, 248, 255)); //set background color
    int posY = 10;
    for(auto action : actList) {
        if(action == checkedAct) {
            QPen checkedPen;  // creates a default pen
            checkedPen.setWidth(5);
            checkedPen.setBrush(Qt::red);
            painter.setPen(checkedPen);
            painter.drawLine(0, posY, 0, posY + 30);

            QFont checkedFont("Times", 10, QFont::Bold);
            painter.setFont(checkedFont);
            painter.setPen(QColor(102,102,102));

            QRect textRect(50, posY + 10, event->rect().width(), event->rect().height());
            painter.drawText(textRect, action->text());
        }
        else {
            QFont uncheckedFont("Times", 10);
            painter.setFont(uncheckedFont);

            QPen uncheckedPen;
            uncheckedPen.setBrush(QColor(204,204,204));
            painter.setPen(uncheckedPen);

            QRect textRect(50, posY + 10, event->rect().width(), event->rect().height());
            painter.drawText(textRect, action->text());

        }

        QIcon icon(action->icon());
        QRect iconRect(10, posY, 30, 30);
        icon.paint(&painter, iconRect);

        posY += 50;
    }
}

void Sidebar::mousePressEvent(QMouseEvent *event)
{
    QAction *action = actionAt(event->pos());
    checkedAct = action;
    update();
}
