#include "equilibreuse.h"
#include "ui_equilibreuse.h"

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)
{
    ui->setupUi(this);

    leCapot = new Capot(laCarte, 0, dynamic_cast<QObject *>(this));

    connect(leCapot, &Capot::EtatCapotChange, this, &Equilibreuse::onCapot_EtatCapotChange);
}

Equilibreuse::~Equilibreuse()
{
    delete leCapot;
    delete leMoteur;
    delete ui;
}

void Equilibreuse::onCapot_EtatCapotChange(const bool _etat)
{
    qDebug() << "onCapot_EtatCapotChange";
}

