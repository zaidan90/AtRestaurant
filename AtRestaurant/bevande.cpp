#include "bevande.h"

Bevande::Bevande(double c, string n, double l):Prodotti(c,n),litri(l)
{}

const double Bevande::tassaBevande=0.20;

double Bevande::prezzo() const{
    return floor((getCosto()+getCosto()*tassaBevande)*10)/10;
}

double Bevande::getLitri() const{return litri;}
