#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "money.h"
#include <QStandardItemModel>

QStandardItemModel *model;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

int value;
Array<Money> *mon;


void MainWindow::on_set_clicked()
{
    value = ui->element->text().toInt();
    model = new QStandardItemModel(2, value+1, this);
    ui->tableView->setModel(model);
    model->setData(model->index(0, 0), "Grvn");
    model->setData(model->index(1, 0), "Coins");
}

void MainWindow::on_show_clicked()
{
    QVariant myData;
    QModelIndex myIndex;
    Money arr[100];
    int realNum[100], imagNum[100];
    for(int i = 1; i<=value; i++)
   {
        myIndex = model->index(0, i);
        myData = model->data(myIndex, Qt::DisplayRole);
        realNum[i-1] = myData.toInt();
        myIndex = model->index(1, i);
        myData = model->data(myIndex, Qt::DisplayRole);
       imagNum[i-1] = myData.toInt();
        arr[i-1] = Money(realNum[i-1], imagNum[i-1]);
   }

    mon = new Array<Money>(arr, value);
    mon->printing(ui->textEdit);

}

void MainWindow::on_add_clicked()
{
    ui->add_show->setNum(mon->adding().get_grvn());
    ui->add_show_2->setNum(mon->adding().get_coins());
}

void MainWindow::on_mul_clicked()
{

    ui->mul_show->setNum(mon->multiply().get_grvn());
    ui->mul_show_2->setNum(mon->multiply().get_coins());
}

void MainWindow::on_min_clicked()
{
    QString minimum = QString::number(mon->min_finding().get_grvn()) + " . " +
            QString::number(mon->min_finding().get_coins());
    ui->min_show->setText(minimum);
}

void MainWindow::on_sub_clicked()
{
    ui->sub_show_1->setNum(mon->sub().get_grvn());
    ui->sub_show_2->setNum(mon->sub().get_coins());
}
