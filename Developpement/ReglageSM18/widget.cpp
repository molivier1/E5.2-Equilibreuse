#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonLancerMesure_clicked()
{
    if(ui->pushButtonLancerMesure->text() == "Lancer Mesure")
    {
        ui->pushButtonLancerMesure->setText("Arrêter Mesure");

        timer.start(500);

        connect(&timer,&QTimer::timeout,this,&Widget::onTimer_timeout);
    }
    else
    {
        ui->pushButtonLancerMesure->setText("Lancer Mesure");
        timer.stop();
    }
}

void Widget::onTimer_timeout()
{
    double valeur;

    UlError erreur;
    erreur = laCarte.ulAIn(0, valeur, AIN_FF_DEFAULT);
    if(erreur != ERR_NO_ERROR)
    {
        qDebug() << erreur;
    }

    ui->lcdNumberTension->display(valeur);
}

