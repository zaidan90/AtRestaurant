#include "pizze.h"

Pizze::Pizze(double c, string n, bool p, bool s):Prodotti(c,n),pastaIntegrale(p),surgelati(s)
{}

const double Pizze::tassaPizza=0.10;


double Pizze::prezzo() const{
        return floor((getCosto()+getCosto()*tassaPizza)*10)/10;
}


bool Pizze::getIntegrale() const{return pastaIntegrale;}

bool Pizze::getSurgelati() const{return surgelati;}
