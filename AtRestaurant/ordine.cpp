#include "ordine.h"

Ordine::Ordine()
{}

void Ordine::aggiungi(Prodotti *m){order.aggiungi(m);}

void Ordine::rimuovi(Prodotti *m){
    int i;
    bool trovato=false;
    for(i=0;i<order.get_size() && !trovato;i++){
        if(order[i]==m){
            trovato=true;
            order.cancella(order[i]);
        }
        }
    }


double Ordine::conto(){
    double somma=0;
    for(int i=0;i<order.get_size();i++){
        somma=somma+order[i]->prezzo();
    }
    return somma;
}
