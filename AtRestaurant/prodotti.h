#ifndef PRODOTTI_H
#define PRODOTTI_H

#include <iostream>
#include <string>
#include<math.h>
using namespace std;

class Prodotti
{
friend class Menu;
private:
    double costo;
    string nome;
public:
    Prodotti(double,string);
    double getCosto() const;
    string getNome() const;
    virtual ~Prodotti() {}
    virtual double prezzo() const =0;
};

#endif // PRODOTTI_H
