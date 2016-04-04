#include "dolci.h"

Dolci::Dolci(double c, string n, bool a):Prodotti(c,n),artigianale(a)
{}

const double Dolci::tassaDolci=0.05;
const double Dolci::tassaAggiuntiva=0.10;


double Dolci::prezzo() const{
    if(artigianale)
        return floor((getCosto()+getCosto()*tassaDolci)*10)/10;
    else
        return floor((getCosto()+getCosto()*tassaAggiuntiva)*10)/10;
}


bool Dolci::getArtigianale() const{return artigianale;}
