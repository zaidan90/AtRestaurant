#ifndef PIZZE_H
#define PIZZE_H

#include "prodotti.h"

class Pizze:public Prodotti
{
private:
    bool pastaIntegrale;
    bool surgelati;
public:
    Pizze(double, string, bool, bool );
    static const double tassaPizza;
    bool getIntegrale() const;
    bool getSurgelati() const;
    double prezzo() const;
};

#endif // PIZZE_H
