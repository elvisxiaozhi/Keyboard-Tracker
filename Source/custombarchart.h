#ifndef CUSTOMBARCHART_H
#define CUSTOMBARCHART_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QLabel>
#include <QMovie>

QT_CHARTS_USE_NAMESPACE

class CustomBarChart : public QChart
{
public:
    CustomBarChart();
    QBarSet *barSet;
    QBarSeries *barSeries;
    QBarCategoryAxis *axis;
    QStringList barCategories;
    QWidget *barChartWidget;
    QChartView *chartView;
    void updateBarChartData(int, QVector<int>);
    QLabel *loadingLbl;
    QMovie *loadingMovie;
    void showLoadingPage();
};

#endif // CUSTOMBARCHART_H
