#include "menu.h"

Menu::Menu(){load();}

void Menu::aggiungi_bevanda(QString n,QString c,QString l){
    QDomDocument document;
    QFile file("../AtRestaurant/data/menu.xml");
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"Failed";

    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<<"not load";

        }
        else qDebug()<<"caricato";
            file.close();
     }


    QDomElement root = document.firstChildElement("Menu");
    QDomElement prodotto=document.createElement("Prodotto");

    QDomElement nome=document.createElement("Nome");
    QDomText nn = document.createTextNode(n);
    nome.appendChild(nn);
    prodotto.appendChild(nome);

    QDomElement costo=document.createElement("Costo");
    QDomText cc = document.createTextNode(c);
    costo.appendChild(cc);
    prodotto.appendChild(costo);

    QDomElement litro=document.createElement("Litro");
    QDomText ll = document.createTextNode(l);
    litro.appendChild(ll);
    prodotto.appendChild(litro);
    root.appendChild(prodotto);


    if(!file.open(QIODevice::WriteOnly| QIODevice::Text))
      {
       qDebug()<<"ciao";
      }

      QTextStream ts( &file );

      ts << document.toString();

      file.close();
}



void Menu::aggiungi_contorno(QString n,QString c,QString p){
    QDomDocument document;
    QFile file("../AtRestaurant/data/menu.xml");
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"Failed";

    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<<"not load";

        }
        else qDebug()<<"caricato";
            file.close();
     }


    QDomElement root = document.firstChildElement("Menu");
    QDomElement prodotto=document.createElement("Prodotto");

    QDomElement nome=document.createElement("Nome");
    QDomText nn = document.createTextNode(n);
    nome.appendChild(nn);
    prodotto.appendChild(nome);

    QDomElement costo=document.createElement("Costo");
    QDomText cc = document.createTextNode(c);
    costo.appendChild(cc);
    prodotto.appendChild(costo);

    QDomElement porzione=document.createElement("Porzione");
    QDomText pp = document.createTextNode(p);
    porzione.appendChild(pp);
    prodotto.appendChild(porzione);
    root.appendChild(prodotto);


    if(!file.open(QIODevice::WriteOnly| QIODevice::Text))
      {
       qDebug()<<"ciao";
      }

      QTextStream ts( &file );

      ts << document.toString();

      file.close();
}


void Menu::aggiungi_pizza(QString n,QString c,QString i,QString s){
    QDomDocument document;
    QFile file("../AtRestaurant/data/menu.xml");
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"Failed";

    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<<"not load";

        }
        else qDebug()<<"caricato";
            file.close();
     }


    QDomElement root = document.firstChildElement("Menu");
    QDomElement prodotto=document.createElement("Prodotto");

    QDomElement nome=document.createElement("Nome");
    QDomText nn = document.createTextNode(n);
    nome.appendChild(nn);
    prodotto.appendChild(nome);

    QDomElement costo=document.createElement("Costo");
    QDomText cc = document.createTextNode(c);
    costo.appendChild(cc);
    prodotto.appendChild(costo);

    QDomElement integrale=document.createElement("Integrale");
    QDomText ii = document.createTextNode(i);
    integrale.appendChild(ii);
    prodotto.appendChild(integrale);

    QDomElement surgelati=document.createElement("Surgelati");
    QDomText ss = document.createTextNode(s);
    surgelati.appendChild(ss);
    prodotto.appendChild(surgelati);

    root.appendChild(prodotto);


    if(!file.open(QIODevice::WriteOnly| QIODevice::Text))
      {
       qDebug()<<"ciao";
      }

      QTextStream ts( &file );

      ts << document.toString();

      file.close();
}


void Menu::aggiungi_dolce(QString n,QString c,QString a){
    QDomDocument document;
    QFile file("../AtRestaurant/data/menu.xml");
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"Failed";

    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<<"not load";

        }
        else qDebug()<<"caricato";
            file.close();
     }


    QDomElement root = document.firstChildElement("Menu");
    QDomElement prodotto=document.createElement("Prodotto");

    QDomElement nome=document.createElement("Nome");
    QDomText nn = document.createTextNode(n);
    nome.appendChild(nn);
    prodotto.appendChild(nome);

    QDomElement costo=document.createElement("Costo");
    QDomText cc = document.createTextNode(c);
    costo.appendChild(cc);
    prodotto.appendChild(costo);

    QDomElement artigianale=document.createElement("Artigianale");
    QDomText aa = document.createTextNode(a);
    artigianale.appendChild(aa);
    prodotto.appendChild(artigianale);
    root.appendChild(prodotto);


    if(!file.open(QIODevice::WriteOnly| QIODevice::Text))
      {
       qDebug()<<"ciao";
      }

      QTextStream ts( &file );

      ts << document.toString();

      file.close();
}



Prodotti* Menu::trova(string n){

    for(int i=0;i<prodotti.get_size(); i++){

      if(prodotti[i]->getNome()==n)
          return prodotti[i];
    }

}

void Menu::elimina(string p){
    QDomDocument document;
    QFile file("../AtRestaurant/data/menu.xml");
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"Failed";

    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<<"not load";

        }
        else qDebug()<<"caricato";
            file.close();
     }


    QDomElement root = document.firstChildElement("Menu");
    QDomNodeList prodotti=root.elementsByTagName("Prodotto");
    bool trovato=false;
    for(int i=0;i<prodotti.count() && !trovato;i++){
        QDomNode singolo_prodotto=prodotti.item(i);
        QDomElement Nome=singolo_prodotto.firstChildElement("Nome");
        QString nome=Nome.text();
        if(nome.toStdString()==p){
            trovato=true;
            document.documentElement().removeChild(singolo_prodotto);

        }
    }
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text))
      {
       qDebug()<<"ciao";
      }

      QTextStream ts( &file );

      ts << document.toString();

      file.close();

}

void Menu::load(){
    //apertura del file e verifica
    QDomDocument document;
    QFile file("../AtRestaurant/data/menu.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Failed";

    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<<"not load";

        }
        else qDebug()<<"caricato";
            file.close();
     }
    //fine verifica file

    //inizio creazione del DB
    QDomElement root=document.firstChildElement("Menu");
    QDomNodeList lista_prodotti =root.elementsByTagName("Prodotto");
    for(int i=0;i<lista_prodotti.count();i++){

         QDomNode singolo_prodotto=lista_prodotti.at(i);
         //singolo_prodotto.toElement();

         QDomElement Nome=singolo_prodotto.firstChildElement("Nome");
         QDomElement Costo=singolo_prodotto.firstChildElement("Costo");
         QDomElement Litro=singolo_prodotto.firstChildElement("Litro");
         QDomElement Porzione=singolo_prodotto.firstChildElement("Porzione");
         QDomElement Artigianale=singolo_prodotto.firstChildElement("Artigianale");
         QDomElement Integrale=singolo_prodotto.firstChildElement("Integrale");
         QDomElement Surgelati=singolo_prodotto.firstChildElement("Surgelati");

         QString nome=Nome.text();
         QString costo=Costo.text();
         string n=nome.toStdString();
         double c=costo.toDouble();


         if(!Litro.isNull()){
             QString litro=Litro.text();
             double l=litro.toDouble();
             Prodotti* np=new Bevande(c,n,l);
             prodotti.aggiungi(np);
                    }
         if(!Porzione.isNull()){
             QString porzione=Porzione.text();
             int p=porzione.toInt();
             Prodotti* np=new Contorni(c,n,p);
             prodotti.aggiungi(np);
         }

         if(!Artigianale.isNull()){
             QString artigianale=Artigianale.text();

             bool art;
             if(artigianale.toStdString()=="No"){art=false;}
             else art=true;
             Prodotti* np=new Dolci(c,n,art);
             prodotti.aggiungi(np);
         }

         if(!Integrale.isNull() && !Surgelati.isNull()){
             QString surgelati=Surgelati.text();

             bool surg;
             if(surgelati.toStdString()=="No"){surg=false;}
             else surg=true;
             QString integrale=Integrale.text();

             bool integ;
             if(integrale.toStdString()=="No"){integ=false;}
             else integ=true;
             Prodotti* np=new Pizze(c,n,integ,surg);
             prodotti.aggiungi(np);
         }

         }



}
