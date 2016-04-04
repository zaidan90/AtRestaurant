#include "contorni.h"

Contorni::Contorni(double c, string n, int p):Prodotti(c,n),porzione(p)
{}

const double Contorni::tassaContorni=0.05;

double Contorni::prezzo() const{
    return floor((getCosto()+getCosto()*tassaContorni)*10)/10;

}

int Contorni::getPorzione() const{return porzione;}
