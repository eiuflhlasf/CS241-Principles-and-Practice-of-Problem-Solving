#include "mainwindow.h"

#include <QApplication>


#include "Histogram.h"



#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

QT_CHARTS_USE_NAMESPACE


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;




    //Histogram h;









    //w.resize(960, 720);








    w.show();
    return a.exec();
}
