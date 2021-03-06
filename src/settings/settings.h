#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSettings>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QToolButton>
#include "applimits.h"
#include "reset.h"
#include "about.h"

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainVLayout, *scrollVLayout;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QToolButton *limitsBtn, *aboutBtn;
    QVector<QToolButton *> btnVec;
    AppLimits *appLimits;
    Reset *reset;
    About *about;

    void setWindowStyleSheet();
    void setWindowLayout();
    QToolButton *createToolBtn(QString);
    void createToolBtns();

protected:
    void paintEvent(QPaintEvent *);

signals:
    void resetStarting();

private slots:
    void toolBtnClicked(QString, bool);
};

#endif // SETTINGS_H
