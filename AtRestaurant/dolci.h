#ifndef DOLCI_H
#define DOLCI_H

#include "prodotti.h"

class Dolci:public Prodotti
{
private:
    bool artigianale;
public:
    Dolci(double,string,bool);
    static const double tassaDolci;
    static const double tassaAggiuntiva;
    bool getArtigianale() const;
    double prezzo() const;
};

#endif // DOLCI_H
