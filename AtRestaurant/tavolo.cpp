#include "tavolo.h"

Tavolo::Tavolo(int cop, int num):coperti(cop),numeroTavolo(num)
{}

const double Tavolo::prezzoCoperto=1.5;

double Tavolo::getConto(){
    return ordine.conto()+prezzoCoperto*coperti;
}
