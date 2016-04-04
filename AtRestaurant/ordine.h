#ifndef ORDINE_H
#define ORDINE_H

#include "prodotti.h"
#include <iostream>
#include "contenitore.h"
using namespace std;

class Ordine
{
public:
    Ordine();
    contenitore order;
    void aggiungi(Prodotti*);
    void rimuovi(Prodotti*);
    double conto();
};

#endif // ORDINE_H
