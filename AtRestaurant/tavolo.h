#ifndef TAVOLO_H
#define TAVOLO_H

#include <vector>
#include <iostream>
#include "ordine.h"
using namespace std;

class Tavolo
{
public:
    Tavolo(int,int);
    int coperti;
    int numeroTavolo;
    static const double prezzoCoperto;
    Ordine ordine;
    double getConto();
};

#endif // TAVOLO_H
