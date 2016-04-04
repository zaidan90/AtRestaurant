#ifndef BEVANDE_H
#define BEVANDE_H

#include "prodotti.h"

class Bevande: public Prodotti
{
private:
    double litri;
public:
    Bevande(double,string,double);
    static const double tassaBevande;
    double prezzo() const;
    double getLitri() const;
};

#endif // BEVANDE_H
