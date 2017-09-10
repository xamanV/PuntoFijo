#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double funcion(double c);  //Function that returns the drag function of a parachute//

private:
        Ui::MainWindow *ui;

    public slots:
        void operacion(); //Slot that performs the bisection method
         void borrar(); //Slot that erases the contents of the spinbox and text
        };
#endif // MAINWINDOW_H
