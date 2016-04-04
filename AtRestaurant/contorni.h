#ifndef CONTORNI_H
#define CONTORNI_H

#include "prodotti.h"

class Contorni:public Prodotti
{
private:
    int porzione;
public:
    Contorni(double,string,int);
    static const double tassaContorni;
    double prezzo() const;
    int getPorzione() const;
};

#endif // CONTORNI_H
