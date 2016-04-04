#include <QtGui>
#include "dialog.h"


Dialog::Dialog():indice(0)
{
     listino=new Menu;
     createLista();
     createLinEdit();
     QVBoxLayout* mainLayout = new QVBoxLayout;
     setWindowTitle("@Restaurant");
     QLabel *bnv = new QLabel("BENVENUTI");
     bnv->setAlignment(Qt::AlignCenter);
     QFont font = bnv->font();
     font.setPointSize(font.pointSize() + 8);
     bnv->setFont(font);

     mainLayout->addWidget(bnv);
     mainLayout->addWidget(tavolo);
     mainLayout->addWidget(lista_menu);
     if(conferma_tavolo->isEnabled()){lista_menu->setDisabled(true);}
    setLayout(mainLayout);
    bevande();
}


void Dialog::createLinEdit(){
    tavolo = new QGroupBox;
    QGridLayout* layout = new QGridLayout;

    labels[0] = new QLabel(tr("Numero Tavolo:"));
    lineEdits[0] = new QLineEdit;
    layout->addWidget(labels[0],0, 0);
    layout->addWidget(lineEdits[0],0, 1);
    labels[1] = new QLabel(tr("Numero Coperti:"));
    lineEdits[1] = new QLineEdit;
    layout->addWidget(labels[1], 1, 0);
    layout->addWidget(lineEdits[1], 1,1 );
    conferma_tavolo=new QPushButton("Conferma");
    connect(conferma_tavolo, SIGNAL(clicked()), this, SLOT(crea_tavolo()));
    layout->addWidget(conferma_tavolo, 2,2,1,2 );
    tavolo->setLayout(layout);
}


void Dialog::createMenu(){
    menu= new QGroupBox();
    // The QHBoxLayout class lines up widgets horizontally.
    QHBoxLayout* layout = new QHBoxLayout;

    bottoni_menu[0] = new QPushButton("Bevande");
    layout->addWidget(bottoni_menu[0]);
    // connessione signal-slot
    connect(bottoni_menu[0], SIGNAL(clicked()), this, SLOT(bevande()));

    bottoni_menu[1] = new QPushButton("Contorni");
    layout->addWidget(bottoni_menu[1]);
    // connessione signal-slot
    connect(bottoni_menu[1], SIGNAL(clicked()), this, SLOT(contorni()));

    bottoni_menu[2] = new QPushButton("Pizze");
    layout->addWidget(bottoni_menu[2]);
    // connessione signal-slot
    connect(bottoni_menu[2], SIGNAL(clicked()),this, SLOT(pizze()));

    bottoni_menu[3] = new QPushButton("Dolci");
    layout->addWidget(bottoni_menu[3]);
    // connessione signal-slot
    connect(bottoni_menu[3], SIGNAL(clicked()),this, SLOT(dolci()));

    menu->setLayout(layout);

}


void Dialog::createLista(){
     createMenu();
     lista_menu = new QGroupBox;
     QGridLayout* layout = new QGridLayout;

     lista = new QTableWidget;
     lista->setEditTriggers(QAbstractItemView::NoEditTriggers);
     lista->setSelectionBehavior(QAbstractItemView::SelectRows);
     lista->horizontalHeader()->setStretchLastSection(true);

     QLabel *il_menu = new QLabel("Il Menù");
     QFont font = il_menu->font();
     il_menu->setAlignment(Qt::AlignCenter);
     font.setPointSize(font.pointSize() + 8);
     il_menu->setFont(font);
     layout->addWidget(il_menu,0,0,1,3);
     layout->addWidget(menu,1,0,1,3);
     layout->addWidget(lista, 2,0,40,3);

     QVBoxLayout* layout_dx = new QVBoxLayout;
     aggiungi= new QPushButton("Aggiungi");


     connect(aggiungi, SIGNAL(clicked()), this, SLOT(aggiungi_ordine()));
     layout_dx->addWidget(aggiungi);
     layout->addLayout(layout_dx,2,4);


     vedi_ordine= new QPushButton("Vedi Ordine");
     connect(vedi_ordine, SIGNAL(clicked()), this, SLOT(visualizza_ordine()));
     layout_dx->addWidget(vedi_ordine);
     conferma_ordine= new QPushButton("Invia Ordine");
     connect(conferma_ordine, SIGNAL(clicked()), this, SLOT(ordine_confermato()));
     layout_dx->addWidget(conferma_ordine);

     vedi_conto= new QPushButton("Il Conto");
     connect(vedi_conto, SIGNAL(clicked()), this, SLOT(calcola_conto()));
     vedi_ordine->setDisabled(true);
     conferma_ordine->setDisabled(true);
     layout->addWidget(vedi_conto,42,0,1,3);

     lista_menu->setLayout(layout);

}

void Dialog::bevande() {

    lista->setRowCount(0);
    lista->setColumnCount(3);
    lista->setColumnWidth(0,200);
    lista->setColumnWidth(1,50);

    QStringList list;
    list << "Nome" << "Litri" << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<listino->prodotti.get_size();i++){

        const Bevande* b=dynamic_cast<const Bevande*>(listino->prodotti[i]);

        if(b)
            {
            lista->insertRow( lista->rowCount() );
            QString n=QString::fromStdString(b->getNome());
            QString p = QString::number(b->prezzo());
            p=p+" €";
            QString l = QString::number(b->getLitri());
            l=l+" L";
            QTableWidgetItem *newItem1 = new QTableWidgetItem(n);
            QTableWidgetItem *newItem2 = new QTableWidgetItem(l);
            QTableWidgetItem *newItem3 = new QTableWidgetItem(p);
            newItem1->setTextAlignment(Qt::AlignCenter);
            newItem2->setTextAlignment(Qt::AlignCenter);
            newItem3->setTextAlignment(Qt::AlignCenter);
            lista->setItem(cont, 0, newItem1);
            lista->setItem(cont, 1, newItem2);
            lista->setItem(cont, 2, newItem3);
            cont++;
        }
    }
}

// slot
void Dialog::contorni() {
    lista->setRowCount(0);
    lista->setColumnCount(3);
    lista->setColumnWidth(0,200);
    lista->setColumnWidth(1,70);
    QStringList list;
    list << "Nome" << "Porzione" << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<listino->prodotti.get_size();i++){

        const Contorni* b=dynamic_cast<const Contorni*>(listino->prodotti[i]);

        if(b)
            {
            lista->insertRow( lista->rowCount() );
            QString n=QString::fromStdString(b->getNome());
            QString p = QString::number(b->prezzo());
            p=p+" €";
            QString l = QString::number(b->getPorzione());
            l="x"+l;
            QTableWidgetItem *newItem1 = new QTableWidgetItem(n);
            QTableWidgetItem *newItem2 = new QTableWidgetItem(l);
            QTableWidgetItem *newItem3 = new QTableWidgetItem(p);
            newItem1->setTextAlignment(Qt::AlignCenter);
            newItem2->setTextAlignment(Qt::AlignCenter);
            newItem3->setTextAlignment(Qt::AlignCenter);
            lista->setItem(cont, 0, newItem1);
            lista->setItem(cont, 1, newItem2);
            lista->setItem(cont, 2, newItem3);
            cont++;
        }
    }
}

// slot
void Dialog::pizze() {
    lista->setRowCount(0);
    lista->setColumnCount(4);
    lista->setColumnWidth(0,160);
    lista->setColumnWidth(1,70);
    lista->setColumnWidth(2,70);

    QStringList list;
    list << "Nome" << "Integrale" << "Surgelati" << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<listino->prodotti.get_size();i++){

        const Pizze* b=dynamic_cast<const Pizze*>(listino->prodotti[i]);

        if(b)
            {
            lista->insertRow( lista->rowCount() );
            QString n=QString::fromStdString(b->getNome());
            QString p = QString::number(b->prezzo());
            QString i,s;
            p=p+" €";
            if(b->getIntegrale())
               i ="*";
            if(b->getSurgelati())
               s="*";

            QTableWidgetItem *newItem1 = new QTableWidgetItem(n);
            QTableWidgetItem *newItem2 = new QTableWidgetItem(i);
            QTableWidgetItem *newItem3 = new QTableWidgetItem(s);
            QTableWidgetItem *newItem4 = new QTableWidgetItem(p);
            newItem1->setTextAlignment(Qt::AlignCenter);
            newItem2->setTextAlignment(Qt::AlignCenter);
            newItem3->setTextAlignment(Qt::AlignCenter);
            newItem4->setTextAlignment(Qt::AlignCenter);
            lista->setItem(cont, 0, newItem1);
            lista->setItem(cont, 1, newItem2);
            lista->setItem(cont, 2, newItem3);
            lista->setItem(cont, 3, newItem4);
            cont++;
        }
    }
}

// slot
void Dialog::dolci() {
    lista->setRowCount(0);
    lista->setColumnCount(3);
    lista->setColumnWidth(0,200);
    lista->setColumnWidth(1,80);
    QStringList list;
    list << "Nome" << "Artig." << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<listino->prodotti.get_size();i++){

        const Dolci* b=dynamic_cast<const Dolci*>(listino->prodotti[i]);

        if(b)
            {
            lista->insertRow( lista->rowCount() );
            QString n=QString::fromStdString(b->getNome());
            QString p = QString::number(b->prezzo());
            p=p+" €";
            QString a;
            if(b->getArtigianale())
               a ="*";
            QTableWidgetItem *newItem1 = new QTableWidgetItem(n);
            QTableWidgetItem *newItem2 = new QTableWidgetItem(a);
            QTableWidgetItem *newItem3 = new QTableWidgetItem(p);
            newItem1->setTextAlignment(Qt::AlignCenter);
            newItem2->setTextAlignment(Qt::AlignCenter);
            newItem3->setTextAlignment(Qt::AlignCenter);
            lista->setItem(cont, 0, newItem1);
            lista->setItem(cont, 1, newItem2);
            lista->setItem(cont, 2, newItem3);
            cont++;
        }
    }
}

void Dialog::aggiungi_ordine(){
    if(lista->rowCount()==0) {
            Avvisi msgBox("Non hai selezionato alcuna voce");
        }
        else{
            if(lista->currentIndex().row()==-1)
                Avvisi msgBox("Non hai selezionato alcuna voce");
            else{
            string n=lista->item(lista->currentRow(),0)->text().toStdString();
            nuovo_tavolo->ordine.aggiungi(listino->trova(n));
            vedi_ordine->setEnabled(true);
            conferma_ordine->setDisabled(false);
                }
          }
}

void Dialog::crea_tavolo(){
    if(!lineEdits[0]->text().toInt() || !lineEdits[1]->text().toInt())
        {Avvisi msg("Non hai inserito i campi correttamente!");}
    else{
    int numero=lineEdits[0]->text().toInt();
    int coperti=lineEdits[1]->text().toInt();
    nuovo_tavolo=new Tavolo(coperti,numero);
    lineEdits[0]->setDisabled(true);
    lineEdits[1]->setDisabled(true);
    conferma_tavolo->setDisabled(true);
    lista_menu->setEnabled(true);
    }
}

void Dialog::calcola_conto(){
    q_conto=new QDialog;

    q_conto->resize(500, 500);
    QVBoxLayout* layout = new QVBoxLayout;

    QLabel *tuo_conto = new QLabel("IL CONTO");
       tuo_conto->setAlignment(Qt::AlignCenter);
       QFont font = tuo_conto->font();
       font.setPointSize(font.pointSize() + 8);
       tuo_conto->setFont(font);

    lista_tuo_conto = new QTableWidget;
       lista_tuo_conto->setEditTriggers(QAbstractItemView::NoEditTriggers);
       lista_tuo_conto->setSelectionBehavior(QAbstractItemView::SelectRows);
       lista_tuo_conto->horizontalHeader()->setStretchLastSection(true);
       lista_tuo_conto->setColumnCount(2);
       lista_tuo_conto->setColumnWidth(0,180);
       QStringList list;
       list << "Nome" << "Prezzo";
       lista_tuo_conto->setHorizontalHeaderLabels(list);
       int i;
       for(i=0;i<nuovo_tavolo->ordine.order.get_size();i++){
           lista_tuo_conto->insertRow( lista_tuo_conto->rowCount() );
           QString n=QString::fromStdString(nuovo_tavolo->ordine.order[i]->getNome());
           QString p = QString::number(nuovo_tavolo->ordine.order[i]->prezzo());
           p=p+" €";
           QTableWidgetItem *newItem1 = new QTableWidgetItem(n);
           newItem1->setTextAlignment(Qt::AlignCenter);
           QTableWidgetItem *newItem2 = new QTableWidgetItem(p);
           newItem2->setTextAlignment(Qt::AlignCenter);
           lista_tuo_conto->setItem(i, 0, newItem1);
           lista_tuo_conto->setItem(i, 1, newItem2);
       }

            lista_tuo_conto->insertRow( lista_tuo_conto->rowCount() );
            QString coperti="Coperto x"+QString::number(nuovo_tavolo->coperti);
            QTableWidgetItem *newItem3 = new QTableWidgetItem(coperti);
            newItem3->setTextAlignment(Qt::AlignCenter);
            lista_tuo_conto->setItem(i,0,newItem3);
            QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::number(nuovo_tavolo->coperti*nuovo_tavolo->prezzoCoperto)+" €");
            newItem4->setTextAlignment(Qt::AlignCenter);
            lista_tuo_conto->setItem(i,1,newItem4);
            lista_tuo_conto->insertRow( lista_tuo_conto->rowCount() );
            lista_tuo_conto->insertRow( lista_tuo_conto->rowCount() );
            QTableWidgetItem *totale= new QTableWidgetItem("Totale");
            totale->setTextAlignment(Qt::AlignCenter);
            lista_tuo_conto->setItem(i+2,0,totale);
            QTableWidgetItem *totale_conto= new QTableWidgetItem(QString::number(nuovo_tavolo->getConto())+" €");
            totale_conto->setTextAlignment(Qt::AlignCenter);
            lista_tuo_conto->setItem(i+2,1,totale_conto);


            QPushButton *paga_ordine= new QPushButton("Paga");
            connect(paga_ordine, SIGNAL(clicked()), this, SLOT(paga_ordine()));



    layout->addWidget(tuo_conto);
    layout->addWidget(lista_tuo_conto);
    layout->addWidget(paga_ordine);
    q_conto->setLayout(layout);
    q_conto->exec();

}

void Dialog::visualizza_ordine(){
 q=new QDialog;
 q->resize(500, 500);
 QGridLayout* layout = new QGridLayout;

 QLabel *tuo_ordine = new QLabel("IL TUO ORDINE");
    tuo_ordine->setAlignment(Qt::AlignCenter);
    QFont font = tuo_ordine->font();
    font.setPointSize(font.pointSize() + 8);
    tuo_ordine->setFont(font);

 lista_tuo_ordine = new QTableWidget;
    lista_tuo_ordine->setEditTriggers(QAbstractItemView::NoEditTriggers);
    lista_tuo_ordine->setSelectionBehavior(QAbstractItemView::SelectRows);
    lista_tuo_ordine->horizontalHeader()->setStretchLastSection(true);
    lista_tuo_ordine->setColumnCount(2);
    lista_tuo_ordine->setColumnWidth(0,180);
    QStringList list;
    list << "Nome" << "Prezzo";
    lista_tuo_ordine->setHorizontalHeaderLabels(list);
    create_ordine();

 QVBoxLayout* layout_dx = new QVBoxLayout;
 QPushButton*cancella_ordine= new QPushButton("Rimuovi");
 connect(cancella_ordine, SIGNAL(clicked()), this, SLOT(ordine_cancellato()));

 layout_dx->addWidget(cancella_ordine);


 QPushButton *ok_ordine= new QPushButton("Ok");
 connect(ok_ordine, SIGNAL(clicked()), this, SLOT(chiudi_ordine()));
 layout_dx->addWidget(ok_ordine);

 layout->addWidget(tuo_ordine,0,0,1,3);
 layout->addWidget(lista_tuo_ordine,1,0,30,3);
 layout->addLayout(layout_dx,1,4);
 q->setLayout(layout);
 q->exec();

}

void Dialog::create_ordine(){
    int i;
    for(i=0;i<nuovo_tavolo->ordine.order.get_size();i++){
        lista_tuo_ordine->insertRow( lista_tuo_ordine->rowCount() );
        QString n=QString::fromStdString(nuovo_tavolo->ordine.order[i]->getNome());
        QString p = QString::number(nuovo_tavolo->ordine.order[i]->prezzo());
        p=p+" €";
        QTableWidgetItem *newItem1 = new QTableWidgetItem(n);
        newItem1->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *newItem2 = new QTableWidgetItem(p);
        newItem2->setTextAlignment(Qt::AlignCenter);
        lista_tuo_ordine->setItem(i, 0, newItem1);
        lista_tuo_ordine->setItem(i, 1, newItem2);
        if(i<indice){
            lista_tuo_ordine->setRowHidden(i,true);
                }
    }
}

void Dialog::ordine_confermato(){
    Avvisi msgbox("Ordine confermato.\nPuoi effettuare altri ordini fino alla richiesta del conto.");
    indice=nuovo_tavolo->ordine.order.get_size();

}

void Dialog::ordine_cancellato(){

            if(lista_tuo_ordine->rowCount()==0)
                Avvisi msgBox("Ordine vuoto! Non c'è niente da eliminare");
            else{
            if(lista_tuo_ordine->currentIndex().row()==-1)
                Avvisi msgBox("Non hai selezionato alcuna voce");
            else{
                string n=lista_tuo_ordine->item(lista_tuo_ordine->currentRow(),0)->text().toStdString();
                nuovo_tavolo->ordine.rimuovi(listino->trova(n));
                lista_tuo_ordine->setRowCount(0);
                create_ordine();
                if(nuovo_tavolo->ordine.order.get_size()==0){conferma_ordine->setDisabled(true);}
            }
    }
}

void Dialog::chiudi_ordine(){
    q->close();
}

void Dialog::paga_ordine(){
    q_conto->close();
    close();
}
