#include "contenitore.h"

contenitore::contenitore():size(0),a(new Prodotti*[0]){}

contenitore::contenitore(const contenitore & c){
    size=c.size;
    a=new Prodotti*[size];
    for(int i=0;i<size;i++){
        a[i]=c.a[i];
    }
}

contenitore::~contenitore(){
    delete[] a;
}


contenitore& contenitore::operator=(const contenitore& c) {
    Prodotti** p = new Prodotti*[c.get_size()];
    for (int i = 0; i < size; i++){
        p[i] = c.a[i];
    }
    delete[] a;
    this->a = p;
    this->size=c.size;
    return *this;
}

const contenitore& contenitore::aggiungi(Prodotti* p){
    Prodotti** temp = new Prodotti*[size + 1];
       for (int i = 0; i < size; i++)
           temp[i] = a[i];
       temp[size] = p;
       delete[] a;
       this->a = temp;
       this->size += 1;
       return *this;
}

int contenitore::get_size() const{return size;}

Prodotti*& contenitore::operator [](int i)const{
    if(i<0 || i>=get_size()) cout<<"errore";
    return a[i];
}


Prodotti *& contenitore::fine()const{
    if(size>0)return a[size-1];
}

const contenitore& contenitore::cancella(Prodotti*p){
    bool trovato=false;
    int indice;
    for(int i=0;i<size && !trovato;i++){
        if(a[i]==p){
            trovato=true;
            indice=i;
        }
    }
    if(!trovato) return *this;
    for(int i=indice;i<size-1;i++){
        a[i]=a[i+1];
    }
    Prodotti** temp = new Prodotti*[size -1];
    for(int i=0;i<size-1;i++){
        temp[i]=a[i];
    }
    delete []a;
    this->a=temp;
    this->size-=1;
}
