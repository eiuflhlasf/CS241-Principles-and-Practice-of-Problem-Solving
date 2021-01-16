#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QFileDialog>
#include <QTextStream>
#include <QTableWidget>
#include <QDebug>
#include<QTableWidgetItem>

#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("人口统计");

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Excel file"), qApp->applicationDirPath (),

                                                       tr("Files (*.csv)"));




      //QString file_name=QFileDialog :: getOpenFileName();

      QFile file(fileName);

      if (!file.open(QIODevice::ReadOnly))
          return;

      else{
          QStringList list;

                  list.clear();

                  QTextStream in(&file);

                  int i =0;

                  QTableWidget *tableWidget = new QTableWidget(5,2); // 构造了一个QTableWidget的对象，并且设置为10行，5列

                  while(!in.atEnd())

                  {
                      QString fileLine = in.readLine();

                                  list = fileLine.split(",", QString::SkipEmptyParts);






                      if(i == 0) {
                          tableWidget->setHorizontalHeaderLabels(QStringList() << list.at(0) << list.at(1));
                          tableWidget->show();
                      }

                      if (i==1){
                          for(int a = 0; a < 2; a++)

                                          {

                                              tableWidget->setItem(0, a, new QTableWidgetItem(list.at(a)));
                                              tableWidget->show();

                                          }

                      }

                      if (i==2){
                          for(int a = 0; a < 2; a++)

                                          {

                                              tableWidget->setItem(1, a, new QTableWidgetItem(list.at(a)));
                                              tableWidget->show();

                                          }

                      }

                      if (i==3){
                          for(int a = 0; a < 2; a++)

                                          {

                                              tableWidget->setItem(2, a, new QTableWidgetItem(list.at(a)));
                                              tableWidget->show();

                                          }

                      }

                      if (i==4){
                          for(int a = 0; a < 2; a++)

                                          {

                                              tableWidget->setItem(3, a, new QTableWidgetItem(list.at(a)));
                                              tableWidget->show();

                                          }

                      }

                      if (i==5){
                          for(int a = 0; a < 2; a++)

                                          {

                                              tableWidget->setItem(4, a, new QTableWidgetItem(list.at(a)));
                                              tableWidget->show();

                                          }

                      }

                      if (i==6){
                          for(int a = 0; a < 2; a++)

                                          {

                                              tableWidget->setItem(5, a, new QTableWidgetItem(list.at(a)));
                                              tableWidget->show();

                                          }

                      }



                      i++;








      }
      }

      file.close();
      return;

}


void MainWindow::on_pushButton_2_clicked()
{
    //绘制饼图
    QPieSeries *series = new QPieSeries();
    //添加饼图切片的标签和值
    series->append("America", 318892);
    series->append("India", 253609);
    series->append("Brazil", 202657);
    series->append("Pakistan", 196194);
    series->append("Russian", 142470);
    float totalValue =318892+253609+202657+196194+142470;
    series->setHoleSize(0.0);//孔大小0.0-1.0
    series->setHorizontalPosition(0.5);//水平位置，默认0.5，0.0-1.0
    series->setLabelsPosition(QPieSlice::LabelOutside);
    series->setLabelsVisible(true);
    //series->setName("");
    //series->setPieEndAngle(350);
    series->setPieSize(0.7);//饼图尺寸，默认0.7
    series->setPieStartAngle(0);//0度为12点钟方向
    series->setVerticalPosition(0.5);
    series->setVisible(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("人口统计");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
    chart->setAnimationOptions(QChart::AllAnimations);//设置启用或禁用动画
    //chart->setBackgroundBrush(QBrush(QColor(170,170,255)));//设置背景色,主题和背景二选一
    //chart->setDropShadowEnabled(true);//是否背景阴影
    chart->setLocalizeNumbers(true);//数字是否本地化
    //chart->legend()->show();//legend是否显示，show和hide
    //chart->createDefaultAxes();//创建默认轴
    chart->setTitleBrush(QBrush(QColor(255,255,255)));//设置标题Brush
    chart->setTitleFont(QFont("微软雅黑",20));//设置标题字体

    chart->legend()->setAlignment(Qt::AlignLeft);//对齐
    //chart->legend()->detachFromChart();
    //chart->legend()->setBackgroundVisible(true);//设置背景是否可视
    //chart->legend()->setAutoFillBackground(true);//设置背景自动填充
    //chart->legend()->setColor(QColor(255,128,128,128));//设置颜色
    //chart->legend()->setContentsMargins(10,10,10,10);//设置边距left,top,right,bottom
    chart->legend()->setLabelColor(QColor(255,128,255));//设置标签颜色
    chart->legend()->setVisible(true);//设置是否可视
    //chart->legend()->setMaximumHeight(50);
    //chart->legend()->setMaximumWidth(120);
    //chart->legend()->setMaximumSize(10000);
    //chart->legend()->setGeometry(50,50,120,50);//设置几何位置x,y,w,h
    //chart->legend()->setBrush(QBrush(QColor(128,128,128,128)));
    //chart->legend()->setPen(QPen(QColor(192,192, 192,192)));
    chart->legend()->setBorderColor(QColor(255,255,170,185));//设置边框颜色
    QFont font = chart->legend()->font();
    font.setItalic(!font.italic());
    chart->legend()->setFont(font);//设置字体为斜体
    font.setPointSizeF(12);
    chart->legend()->setFont(font);//设置字体大小
    chart->legend()->setFont(QFont("微软雅黑"));//设置字体类型

    //操作单个切片
    QPieSlice *slice1 = series->slices().at(0);
    slice1->setExploded();//切片是否与饼图分离
    slice1->setLabelVisible(true);
    //slice->setPen(QPen(Qt::darkGreen, 2));
    //slice->setBrush(Qt::green);
    slice1->setLabelColor(QColor(255,170,255));
    //slice1->setBorderColor(QColor(0,0,255));
    //slice1->setBorderWidth(2);
    //slice1->setBrush(QColor(255,170,255));
    slice1->setColor(QColor(255,170,255));
    slice1->setLabel(slice1->label()+"-"+QString("%1").arg(slice1->value())+"-"+QString("%1").arg(slice1->value()/totalValue*100)+"%");
    //slice1->setLabelBrush(QColor(255,170,255));
    slice1->setLabelFont(QFont("微软雅黑"));
    //slice->setLabelPosition();
    slice1->setLabelVisible(true);
    //slice1->setValue(5);

    QPieSlice *slice2 = series->slices().at(1);
    //slice2->setExploded();//切片是否与饼图分离
    slice2->setLabelVisible(true);
    //slice2->setPen(QPen(Qt::darkGreen, 2));
    //slice2->setBrush(Qt::green);
    slice2->setLabelColor(QColor(170,170,255));
    //slice2->setBorderColor(QColor(255,0,0));
    //slice2->setBorderWidth(2);
    //slice2->setBrush(QColor(170,170,255));
    slice2->setColor(QColor(170,170,255));
    slice2->setLabel(slice2->label()+"-"+QString("%1").arg(slice2->value())+"-"+QString("%1").arg(slice2->value()/totalValue*100)+"%");
    //slice2->setLabelBrush(QColor(170,170,255));
    slice2->setLabelFont(QFont("微软雅黑"));
    //slice->setLabelPosition();
    slice2->setLabelVisible(true);
    //slice2->setValue(5);

    QPieSlice *slice3 = series->slices().at(2);
    //slice3->setExploded();//切片是否与饼图分离
    slice3->setLabelVisible(true);
    //slice3->setPen(QPen(Qt::darkGreen, 2));
    //slice3->setBrush(Qt::green);
    slice3->setLabelColor(QColor(255,170,170));
    //slice3->setBorderColor(QColor(0,255,0));
    //slice3->setBorderWidth(2);
    //slice3->setBrush(QColor(170,170,255));
    slice3->setColor(QColor(255,170,170));
    slice3->setLabel(slice3->label()+"-"+QString("%1").arg(slice3->value())+"-"+QString("%1").arg(slice3->value()/totalValue*100)+"%");
    //slice3->setLabelBrush(QColor(170,170,255));
    slice3->setLabelFont(QFont("微软雅黑"));
    //slice3->setLabelPosition();
    slice3->setLabelVisible(true);
    //slice3->setValue(5);

    QPieSlice *slice4 = series->slices().at(3);
    //slice4->setExploded();//切片是否与饼图分离
    slice3->setLabelVisible(true);
    //slice4->setPen(QPen(Qt::darkGreen, 2));
    //slice4->setBrush(Qt::green);
    slice4->setLabelColor(QColor(170,255,170));
    //slice4->setBorderColor(QColor(0,0,255));
    //slice4->setBorderWidth(1);
    //slice4->setBrush(QColor(170,170,255));
    slice4->setColor(QColor(170,255,170));
    slice4->setLabel(slice4->label()+"-"+QString("%1").arg(slice4->value())+"-"+QString("%1").arg(slice4->value()/totalValue*100)+"%");
    //slice4->setLabelBrush(QColor(170,170,255));
    slice4->setLabelFont(QFont("微软雅黑"));
    //slice4->setLabelPosition();
    slice4->setLabelVisible(true);
    //slice4->setValue(5);

    QPieSlice *slice5 = series->slices().at(4);
    //slice5->setExploded();//切片是否与饼图分离
    slice5->setLabelVisible(true);
    //slice5->setPen(QPen(Qt::darkGreen, 2));
    //slice5->setBrush(Qt::green);
    slice5->setLabelColor(QColor(255,255,170));
    //slice5->setBorderColor(QColor(0,255,0));
    //slice5->setBorderWidth(1);
    //slice5->setBrush(QColor(170,170,255));
    slice5->setColor(QColor(255,255,170));
    slice5->setLabel(slice5->label()+"-"+QString("%1").arg(slice5->value())+"-"+QString("%1").arg(slice5->value()/totalValue*100)+"%");
    //slice5->setLabelBrush(QColor(170,170,255));
    slice5->setLabelFont(QFont("微软雅黑"));
    //slice5->setLabelPosition();
    slice5->setLabelVisible(true);
    //slice5->setValue(5);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //w.setCentralWidget(chartView);

    series->show();
    chartView->show();

return;
}


