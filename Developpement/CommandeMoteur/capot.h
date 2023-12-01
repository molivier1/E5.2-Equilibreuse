#ifndef CAPOT_H
#define CAPOT_H

#include "mcculdaq.h"
#include <QTimer>
#include <QObject>

class Capot : public QObject
{
    Q_OBJECT
public:
    Capot(MccUldaq &_laCarte, const int _numDio, QObject *parent = nullptr);
    void onTimerCapot_timeout();
private:
    bool etatCapot;
    bool etatCourant;
    int numDio;
    MccUldaq &laCarte;
    QTimer timerCapot;

signals:
    void EtatCapotChange(const bool _etat);
};

#endif // CAPOT_H
