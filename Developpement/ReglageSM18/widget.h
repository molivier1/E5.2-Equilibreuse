#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mcculdaq.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonLancerMesure_clicked();

    void onTimer_timeout();

private:
    Ui::Widget *ui;

    MccUldaq laCarte;
    QTimer timer;
};
#endif // WIDGET_H
