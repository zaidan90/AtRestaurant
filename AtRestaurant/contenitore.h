#ifndef CONTENITORE_H
#define CONTENITORE_H

#include "prodotti.h"
#include "bevande.h"
#include <iostream>
using namespace std;

class contenitore
{
private:
    Prodotti** a;
    int size;
public:
    contenitore();
    contenitore(const contenitore&);
    ~contenitore();
    contenitore& operator=(const contenitore&);
    const contenitore& aggiungi(Prodotti*);
    int get_size()const;
    Prodotti* & operator[](int)const;
    void cerca(Prodotti*);
    const contenitore& cancella(Prodotti*);
    Prodotti*& fine()const;

};
#endif // CONTENITORE_H
