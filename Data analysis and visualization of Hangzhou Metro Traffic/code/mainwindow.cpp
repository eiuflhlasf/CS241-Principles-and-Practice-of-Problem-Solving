#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QFileDialog>
#include <QTextStream>
#include <QTableWidget>
#include <QDebug>
#include<QTableWidgetItem>

#include<iostream>
#include <stack>


// 包含line chart需要的头文件
#include <QChartView>
#include <QLineSeries>
// 引用命名空间
QT_CHARTS_USE_NAMESPACE

using namespace std;

QString  s[75500],s1[75500], s2[75500], s3[75500], s4[75500], s5[75500], s6[75500];


QString str1, str2,str3,str4,str5,str6,str7,str8;

QString ss[75500];

int step=1;

//int s7[75500];



int a[7]={0};













#define  NUM 82
#define MAX_PATH 100

QString M[NUM][NUM];


struct Node
{
    int key;
    int flag;
    Node()
    {
        flag=0;
    }
};



        //stack<int> searchStack;
        int resultPath[MAX_PATH][NUM];
        int result[NUM+1];//将result设为NUM+1，主要是为了避免发生B->D->B的事情

        Node headNode;//起始节点
        Node endNode;//终止节点
        stack<Node> tempStack;
        int pathNum;
        int nPos;
        bool Mark[NUM];





        int f(const QString s){
            int hour, min;
            hour=(s[11].unicode()-'0')*10+s[12].unicode()-'0';
            min=(s[14].unicode()-'0')*10+s[15].unicode()-'0';

            cout<<hour*60+min<<endl;

            return hour*60+min;


        }





        void FindAllPath(int Matrix[NUM][NUM],Node startNodeKey,Node endNodeKey)
        {
            result[nPos]=startNodeKey.key;  //将当前元素放入结果集中
            Mark[startNodeKey.key-1]=true;  //将访问标记为已访问
            nPos++;  //结果集索引加1
            while(nPos!=0)
            {
                int tempVal=result[nPos-1];//获取到最前面的元素
                if (tempVal==endNodeKey.key)  //若当前元素为目标节点
                {
                    for (int j=0;j<nPos;j++)
                    {
                        resultPath[pathNum][j]=result[j];  //将结果集复制于最后的路径矩阵中
                    }
                    nPos--;  //回溯至上一个节点
                    result[nPos]=0;  //结果集对应索引置为空
                    pathNum++;  //路径数目加1
                    Mark[endNodeKey.key-1]=false;
                    break;
                }
                while(startNodeKey.flag<NUM-1)//利用flag来指示每次的元素的索引
                {
                    if (Matrix[tempVal-1][startNodeKey.flag]==1)
                    {
                        if (Mark[startNodeKey.flag]==false)//利用Mark来判断是否已经访问过该节点
                        {
                            Node tempNode;
                            tempNode.key=startNodeKey.flag+1;
                            FindAllPath(Matrix,tempNode,endNodeKey);//深度优先遍历算法，
                        }
                    }
                    startNodeKey.flag++;//索引值相应的加一
                }

                if (startNodeKey.flag==NUM-1)//如果已经是到最后的邻居，说明访问结束，
                {                           //将对应的值置为空
                    nPos--;  //再次向上回溯
                    startNodeKey.flag=0;  //将节点的索引置为空
                    result[nPos]=0;  //将结果集中对应的索引置为空
                    Mark[startNodeKey.key-1]=false;  //访问之后标记为未访问。因为下面的元素已经访问结束，便于下次的访问
                    break;
                }
            }
        }










    void test()
    {
        //对应无向图的矩阵
        /*int Matrix[NUM][NUM]={
            {0,1,0,1,0}, //A
            {1,0,1,0,1}, //B
            {0,1,0,1,1}, //C
            {1,0,1,0,0}, //D
            {0,1,1,0,0}  //E
        };*/


        int Matrix[NUM][NUM];

        int i, j;
        for (i=0; i<NUM-1; i++)
            for (j=0; j<NUM-1; j++)
                Matrix[i][j]=M[i+1][j+1].toInt();




        //开始节点
        headNode.key=str6.toInt();
        headNode.flag=1;

        //结束节点
        endNode.key=str7.toInt();

        FindAllPath(Matrix,headNode,endNode);





        cout<<"顶点"<<headNode.key<<"到顶点"<<endNode.key<<"路径数目为："<<pathNum<<endl;
        for (int i=0;i<pathNum;i++)
        {
            cout<<"第"<<i+1<<"条: ";
            for(int j=0;j<NUM;j++)
            {
                if (resultPath[i][j]==0)
                {
                    break;
                }
                cout<<resultPath[i][j]<<"  ";
            }
            cout<<endl;
        }
        //int i=0;
    }



























































void sort (){
    int flag=1;
    int i;
    QString tmp;
    while (flag){
        flag=0;
        for (i=0; i<5000; i++){
            if (s[i]>s[i+1]) {
                tmp=s[i+1];
                s[i+1]=s[i];
                s[i]=tmp;

                //f(s[i]);

               /* tmp=s1[i+1];
                s1[i+1]=s1[i];
                s1[i]=tmp;

                tmp=s2[i+1];
                s2[i+1]=s2[i];
                s2[i]=tmp;

                tmp=s3[i+1];
                s3[i+1]=s3[i];
                s3[i]=tmp;

                tmp=s4[i+1];
                s4[i+1]=s4[i];
                s4[i]=tmp;

                tmp=s5[i+1];
                s5[i+1]=s5[i];
                s5[i]=tmp;

                tmp=s6[i+1];
                s6[i+1]=s6[i];
                s6[i]=tmp;*/

                flag=1;

            }
        }
    }
}






























MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Hangzhou Metro Managing System");
}

MainWindow::~MainWindow()
{
    delete ui;
}


//按行过滤
void MainWindow::ScreenInfo(QTableWidget *source, QString &text)
{

    int rC = source->rowCount();//获得行数
    if ("" == text) {//判断输入是否为空
        for (int i = 0; i < rC; i++) {
            source->setRowHidden(i, false);//显示所有行
        }
    } else {
        //获取符合条件的cell索引
        QList <QTableWidgetItem *> item = source->findItems(text, Qt::MatchContains);

        for (int i = 0; i < rC; i++) {
            source->setRowHidden(i, true);//隐藏所有行
        }

        if (!item.isEmpty()) { //不为空
            for (int i = 0; i < item.count(); i++) {
                source->setRowHidden(item.at(i)->row(),false);//item.at(i).row()输出行号
            }
        }
    }
}









































void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->setRange(0,100); //设置进度条最小值和最大值(取值范围)
    ui->progressBar->setMinimum(0); //设置进度条最小值
    ui->progressBar->setMaximum(100); //设置进度条最大值

    ui->progressBar->setValue(0);
    ui->progressBar->show();


    QString fileName = QFileDialog::getOpenFileName(this, tr("Excel file"), qApp->applicationDirPath (),

                                                       tr("Files (*.csv)"));







    for(int i=1; i<101; i++)
     ui->progressBar->setValue(i);












    QTableWidget *tableWidget = new QTableWidget(75000,7); // 构造了一个QTableWidget的对象，并且设置为10行，5列






      //QString file_name=QFileDialog :: getOpenFileName();

      QFile file(fileName);

      if (!file.open(QIODevice::ReadOnly))
          return;

      else{

          QStringList list;

                  list.clear();

                  QTextStream in(&file);

                  int j=0;


                  int i =0;

                  //QTableWidget *tableWidget = new QTableWidget(75000,7); // 构造了一个QTableWidget的对象，并且设置为10行，5列

                  while(!in.atEnd())

                  {
                      QString fileLine = in.readLine();

                                  list = fileLine.split(",", QString::SkipEmptyParts);








                      if(i == 0) {


                          tableWidget->setHorizontalHeaderLabels(QStringList() << list.at(0) << list.at(1)<< list.at(2) << list.at(3)<< list.at(4) << list.at(5)<< list.at(6) );
                          //tableWidget->show();
                      }


                          for(int a = 0; a < 7; a++)

                                          {



                                              tableWidget->setItem(i-1, a, new QTableWidgetItem(list.at(a)));
                                              //tableWidget->show();

                                          }
                          s[j]=list.at(0);
                          s1[j]=list.at(1);
                          s2[j]=list.at(2);
                          s3[j]=list.at(3);
                          s4[j]=list.at(4);
                          s5[j]=list.at(5);
                          s6[j]=list.at(6);

                          //s7[j]=f(s[j]);
                          //f(s[j]);





                      i++;
                      j++;








      }
      }

      file.close();

      //QString ss="";

      //ScreenInfo(tableWidget,ss);

      //tableWidget->hideColumn(0);



      for (int i=0; i<7; i++){
          if (a[i]==0) tableWidget->hideColumn(i);
      }




      tableWidget->show();






      return;

}

void MainWindow::on_textEdit_textChanged()
{

    str1 = ui->textEdit->toPlainText();

}

void MainWindow::on_textEdit_2_textChanged()
{
    str2 = ui->textEdit_2->toPlainText();
}



void MainWindow::on_textEdit_3_textChanged()
{
    str3 = ui->textEdit_3->toPlainText();
}


void MainWindow::on_textEdit_4_textChanged()
{
    str4 = ui->textEdit_4->toPlainText();
}



void MainWindow::on_pushButton_2_clicked()
{
    int i, j;

    int low, high;


    int sum=0;


    int timeStep=str3.toInt();

    int num=0;
    ui->progressBar->setValue(0);



        for(i=1; i<101; i++)
         ui->progressBar->setValue(i);




   sort();


























   // new 一个 QLineSeries实例
   QLineSeries *series = new QLineSeries();
   // 添加实验数据,可以用 append 方法或者 << 操作符
   /*series->append(0,2);
   series->append(QPointF(2,6));
   series->append(3,8);
   series->append(7,9);
   series->append(11,3);*/

   int totalTime = str5.toInt();

   /*for (j=0; j<10000; j++)
       if (s[j]==str1) break;

   low=j;

   for (j=0; j<10000; j++)
       if (s[j]==str2) break;

   high=j;*/





   //cout<<low<<' '<<high<<' '<<timeStep<<' '<<totalTime;

   series->append(f(str1),0);


   if (str8=="1"){





   for (i=f(str1); i<f(str2); i+=timeStep){
       for (j=0; j<5000; j++)
           if (f(s[j])>i && f(s[j])<(i+timeStep)  && s4[j]=="1" && s2[j]==str4)
               num++;

       series->append(i,num);

       num=0;
       //low+=timeStep;
       //if (low>=high) break;
   }
   }

   if (str8=="0"){





   for (i=f(str1); i<f(str2); i+=timeStep){
       for (j=0; j<5000; j++)
           if (f(s[j])>i && f(s[j])<(i+timeStep)  && s4[j]=="0" && s2[j]==str4)
               num++;

       series->append(i,num);

       num=0;
       //low+=timeStep;
       //if (low>=high) break;
   }
   }

   //low-=timeStep;

   //series->append(high,high-low);

   //i-=timeStep;








   QChart *chart = new QChart();
   // 将图例隐藏
   chart->legend()->hide();
   // 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
   chart->addSeries(series);
   // 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
   series->setUseOpenGL(true);
   // 创建默认的坐标系（笛卡尔坐标）
   chart->createDefaultAxes();
   // 设置图表标题
   chart->setTitle(QStringLiteral("Traffic Flow"));
   QChartView *view = new QChartView(chart);
   // 开启抗锯齿，让显示效果更好
   view->setRenderHint(QPainter::Antialiasing);
   view->resize(400,300);
   // 显示图表
   view->show();
   chart->show();


}

void MainWindow::on_textEdit_5_textChanged()
{
    str5 = ui->textEdit_5->toPlainText();
}

void MainWindow::on_textEdit_6_textChanged()
{
    str6 = ui->textEdit_6->toPlainText();
}


void MainWindow::on_textEdit_7_textChanged()
{
    str7 = ui->textEdit_7->toPlainText();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Excel file"), qApp->applicationDirPath (),

                                                       tr("Files (*.csv)"));
    ui->progressBar->setValue(0);
    for(int i=1; i<101; i++)
     ui->progressBar->setValue(i);





      //QString file_name=QFileDialog :: getOpenFileName();

      QFile file(fileName);

      if (!file.open(QIODevice::ReadOnly))
          return;

      else{

          QStringList list;

                  list.clear();

                  QTextStream in(&file);

                  //int j=0;


                  int i =0;

                  //QTableWidget *tableWidget = new QTableWidget(75000,7); // 构造了一个QTableWidget的对象，并且设置为10行，5列

                  while(!in.atEnd())

                  {
                      QString fileLine = in.readLine();

                                  list = fileLine.split(",", QString::SkipEmptyParts);








                      if(i) {
                          for(int a = 1; a < 82; a++)

                                          {
                              M[i][a]=list.at(a);






                                          }



                      }








                      i++;
                      //j++;








      }
      }

      file.close();


        test();

        ui->textBrowser->insertPlainText("The number of routes from Station ");

        QString s = QString::number(headNode.key, 10);

        ui->textBrowser->insertPlainText(s);

          ui->textBrowser->insertPlainText(" to Station ");

          s = QString::number(endNode.key, 10);

          ui->textBrowser->insertPlainText(s);

          ui->textBrowser->insertPlainText(" is：");

          s = QString::number(pathNum, 10);

          ui->textBrowser->insertPlainText(s+"\n");

          for (int i=0;i<pathNum;i++)
          {
              s = QString::number(i+1, 10);
              ui->textBrowser->insertPlainText("Route "+s+": ");
              for(int j=0;j<NUM;j++)
              {
                  if (resultPath[i][j]==0)
                  {
                      break;
                  }
                  s = QString::number(resultPath[i][j], 10);
                  ui->textBrowser->insertPlainText(s+" ");

                  //cout<<resultPath[i][j]<<"  ";
              }
              ui->textBrowser->insertPlainText("\n");
              //cout<<endl;


          }



        //ui->textBrowser->insertPlainText("abcd");












      return;
}

void MainWindow::on_textEdit_8_textChanged()
{
    str8 = ui->textEdit_8->toPlainText();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

    if (a[0]==0){
    a[0]=1;
    }
    else{
    a[0]=0;
    }

    cout<<a[0];
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if (a[1]==0){
    a[1]=1;
    }
    else{
    a[1]=0;
    }
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if (a[2]==0){
    a[2]=1;
    }
    else{
    a[2]=0;
    }
}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    if (a[3]==0){
    a[3]=1;
    }
    else{
    a[3]=0;
    }
}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    if (a[4]==0){
    a[4]=1;
    }
    else{
    a[4]=0;
    }
}


void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    if (a[5]==0){
    a[5]=1;
    }
    else{
    a[5]=0;
    }
}

void MainWindow::on_checkBox_7_stateChanged(int arg1)
{
    if (a[6]==0){
    a[6]=1;
    }
    else{
    a[6]=0;
    }
}
