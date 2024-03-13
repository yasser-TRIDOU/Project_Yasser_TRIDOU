#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

sudoku::matrix matx;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(N > 9)
    {
        ui->table->setColumnCount(N);
        ui->table->setRowCount(N);
        for(int i=9;i<N;i++)
        {
            QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
            ui->table->setHorizontalHeaderItem(i, __qtablewidgetitem);
            QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
            ui->table->setVerticalHeaderItem(i, __qtablewidgetitem9);
        }

        for(int j=0;j<9;j++)
        {
            for(int k=9;k<N;k++)
            {
                QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
                ui->table->setItem(j, k, __qtablewidgetitem19);
            }
        }
        for(int l=8;l<N;l++)
        {
            for(int m=0;m<N;m++)
            {
                QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
                ui->table->setItem(l, m, __qtablewidgetitem19);
            }
        }

    }
    matx.new_puzzle();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.read(i, j))
            {
                QColor c(250,128,114);
                Cell->setBackgroundColor(c);
            }
        }
    }
    ui->label->setText("sudoku!!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_table_cellClicked(int row, int column)
{
    Row = row;
    Column = column;
    QString str = "";
    str += '0' + row;
    str += ',';
    str += '0' + column;
    const QString cstr = str;
    ui->label->setText(cstr);
}

void MainWindow::click__on_pb(int num)
{
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, num);
    QString str = "";
    str += '0' + matx.read(Row, Column);
    const QString cstr = str;
    Cell->setText(cstr);
    if (matx.you_win())
    {
        ui->label->setText("you win!!");
    }
}

void MainWindow::on_pb00_1_clicked()
{
   click__on_pb(1);
}

void MainWindow::on_pb00_2_clicked()
{
    click__on_pb(2);
}

void MainWindow::on_pb00_3_clicked()
{
    click__on_pb(3);
}

void MainWindow::on_pb00_4_clicked()
{
    click__on_pb(4);
}

void MainWindow::on_pb00_5_clicked()
{
    click__on_pb(5);
}

void MainWindow::on_pb00_6_clicked()
{
    click__on_pb(6);
}

void MainWindow::on_pb00_7_clicked()
{
    click__on_pb(7);
}

void MainWindow::on_pb00_8_clicked()
{
    click__on_pb(8);
}

void MainWindow::on_pb00_9_clicked()
{
    click__on_pb(9);
}

void MainWindow::on_solve_clicked()
{
    matx.reset();

    auto start_time = std::chrono::high_resolution_clock::now();
    matx.solvebacktracking();
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds >(end_time - start_time);
    std::cout << "Temps d'execution : " << duration.count() << " microseconds." << std::endl;

    for (int i = 0; i < N; ++i)
	{
        for (int j = 0; j < N; ++j)
		{
			QTableWidgetItem* Cell = ui->table->item(i, j);
			QString str = "";
            str += '0' + matx.read(i,j);
			const QString cstr = str;
			Cell->setText(cstr);
		}
	}
}

void MainWindow::on_actionNew_game_triggered()
{
    matx.new_puzzle();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.read(i, j))
            {
                QColor c(250,128,114);
                Cell->setBackgroundColor(c);
            }
            else
            {
                QColor c(255,255,255);
                Cell->setBackgroundColor(c);
            }
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    matx.reset();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}
