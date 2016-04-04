#include "prodotti.h"

Prodotti::Prodotti(double c, string s):costo(c),nome(s)
{}

double Prodotti::getCosto() const{return costo;}

string Prodotti::getNome() const{return nome;}


