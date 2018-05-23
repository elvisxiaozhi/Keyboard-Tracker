#ifndef STACKEDBARCHART_H
#define STACKEDBARCHART_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE

class StackedBarChart : public QWidget
{
    Q_OBJECT
public:
    explicit StackedBarChart(QWidget *parent = nullptr);

private:
    QChart *chart;
    QBarSet *leftSet, *rightSet;
    QStackedBarSeries *series;
    QStringList categories;
    QBarCategoryAxis *barAxisX;

signals:

public slots:
};

#endif // STACKEDBARCHART_H
