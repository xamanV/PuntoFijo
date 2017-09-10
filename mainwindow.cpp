#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>  //Bookstore for the use of text strings
#include <cmath>    //Library for use of mathematical functions

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connections
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(operacion()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::funcion(double c){
    return(exp(-c)); //function to evaluate
}
void MainWindow::operacion(){
    QString temp,temp2,temp3,temp4;           //Temporary use text strings
    double dato1=ui->dato1->value();         //Retrieves the data value of the spinbox
    double error=ui->Error->value();     //Retrieve the value of the spinbox error
    double xi=00;                 //initial value of the first iteration
    double ea=100.0;             // 100 error
    double ni=0;
    double no=0;
    while(ea>error){
        xi=funcion(dato1);            //evaluation of the function (fixed point)
       ea=100*std::abs(xi-dato1)/xi; //The error is calculated
        dato1=xi;                   //takes the value of the evaluated function
    no=ni+1;
    ni=no;
    }
    temp.append("Raiz=").append(temp2.setNum(xi)).append("\nError=").append(temp3.setNum(ea)).append("\nIteraciones=").append(temp4.setNum(ni));  //Se prepara el texto para ser presentado
    ui->Texto->setText(temp);  //The text is presented
}

void MainWindow::borrar(){
    ui->dato1->setValue(0.0);    //Spinbox is deleted

    ui->Error->setValue(0.0);
    ui->Texto->clear();      //Text is deleted
}
