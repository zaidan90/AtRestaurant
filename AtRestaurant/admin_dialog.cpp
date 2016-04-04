#include "admin_dialog.h"

admin_dialog::admin_dialog()
{
  il_menu=new Menu;

  menu= new QGroupBox();
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


  QGridLayout* grid_layout = new QGridLayout;

  lista = new QTableWidget;
  lista->setEditTriggers(QAbstractItemView::NoEditTriggers);
  lista->setSelectionBehavior(QAbstractItemView::SelectRows);
  lista->horizontalHeader()->setStretchLastSection(true);

  QLabel *label_il_menu = new QLabel("Il Menù");
  QFont font = label_il_menu->font();
  label_il_menu->setAlignment(Qt::AlignCenter);
  font.setPointSize(font.pointSize() + 8);
  label_il_menu->setFont(font);
  grid_layout->addWidget(label_il_menu,0,0,1,3);
  grid_layout->addWidget(menu,1,0,1,3);
  grid_layout->addWidget(lista, 2,0,40,3);

  QHBoxLayout* bottom_layout=new QHBoxLayout;
  QPushButton* aggiungi_voce=new QPushButton("Nuova Voce");
  connect(aggiungi_voce, SIGNAL(clicked()), this, SLOT(aggiungi_menu()));
  QPushButton* elimina_voce=new QPushButton("Elimina Voce");
  connect(elimina_voce, SIGNAL(clicked()), this, SLOT(elimina_menu()));
  bottom_layout->addWidget(aggiungi_voce);
  bottom_layout->addWidget(elimina_voce);
  grid_layout->addLayout(bottom_layout,42,0,1,3);

  setLayout(grid_layout);

bevande();

}


void admin_dialog::bevande() {

    lista->setRowCount(0);
    lista->setColumnCount(3);
    lista->setColumnWidth(0,200);
    lista->setColumnWidth(1,50);

    QStringList list;
    list << "Nome" << "Litri" << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<il_menu->prodotti.get_size();i++){

        const Bevande* b=dynamic_cast<const Bevande*>(il_menu->prodotti[i]);

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
void admin_dialog::contorni() {
    lista->setRowCount(0);
    lista->setColumnCount(3);
    lista->setColumnWidth(0,200);
    lista->setColumnWidth(1,70);
    QStringList list;
    list << "Nome" << "Porzione" << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<il_menu->prodotti.get_size();i++){

        const Contorni* b=dynamic_cast<const Contorni*>(il_menu->prodotti[i]);

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
void admin_dialog::pizze() {
    lista->setRowCount(0);
    lista->setColumnCount(4);
    lista->setColumnWidth(0,160);
    lista->setColumnWidth(1,70);
    lista->setColumnWidth(2,70);

    QStringList list;
    list << "Nome" << "Integrale" << "Surgelati" << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<il_menu->prodotti.get_size();i++){

        const Pizze* b=dynamic_cast<const Pizze*>(il_menu->prodotti[i]);

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
void admin_dialog::dolci() {
    lista->setRowCount(0);
    lista->setColumnCount(3);
    lista->setColumnWidth(0,200);
    lista->setColumnWidth(1,80);
    QStringList list;
    list << "Nome" << "Artig." << "Prezzo";
    lista->setHorizontalHeaderLabels(list);
    int cont=0;
    for(int i=0;i<il_menu->prodotti.get_size();i++){

        const Dolci* b=dynamic_cast<const Dolci*>(il_menu->prodotti[i]);

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

void admin_dialog::aggiungi_menu(){
    dialog_aggiunta=new QDialog;
    QLabel* seleziona_cat=new QLabel("Seleziona Categoria");
    QVBoxLayout* mainLayout_aggiunta=new QVBoxLayout;
    mainLayout_aggiunta->addWidget(seleziona_cat);

    QHBoxLayout* menu_categoria=new QHBoxLayout;
    b[0] = new QPushButton("Bevanda");
    menu_categoria->addWidget(b[0]);
    // connessione signal-slot
    connect(b[0], SIGNAL(clicked()), this, SLOT(aggiunta_bevanda()));

    b[1] = new QPushButton("Contorno");
    menu_categoria->addWidget(b[1]);
    // connessione signal-slot
    connect(b[1], SIGNAL(clicked()), this, SLOT(aggiunta_contorno()));

    b[2] = new QPushButton("Pizza");
    menu_categoria->addWidget(b[2]);
    // connessione signal-slot
    connect(b[2], SIGNAL(clicked()), this, SLOT(aggiunta_pizza()));

    b[3] = new QPushButton("Dolce");
    menu_categoria->addWidget(b[3]);
    // connessione signal-slot
    connect(b[3], SIGNAL(clicked()), this, SLOT(aggiunta_dolce()));


    h[0]=new QHBoxLayout;
    QLabel* inserisci_nome=new QLabel("Inserisci Nome:");
    inserisci_campo[0]=new QLineEdit;
    h[0]->addWidget(inserisci_nome);
    h[0]->addWidget(inserisci_campo[0]);
    inserisci_campo[0]->setEnabled(false);

    h[1]=new QHBoxLayout;
    QLabel* inserisci_costo=new QLabel("Inserisci Costo:");
    inserisci_campo[1]=new QLineEdit;
    h[1]->addWidget(inserisci_costo);
    h[1]->addWidget(inserisci_campo[1]);
    inserisci_campo[1]->setEnabled(false);

    h[2]=new QHBoxLayout;
    QLabel* inserisci_litro=new QLabel("Inserisci Litri:");
    inserisci_campo[2]=new QLineEdit;
    h[2]->addWidget(inserisci_litro);
    h[2]->addWidget(inserisci_campo[2]);
    inserisci_campo[2]->setEnabled(false);

    h[3]=new QHBoxLayout;
    QLabel* inserisci_porzione=new QLabel("Inserisci Porzione:");
    inserisci_campo[3]=new QLineEdit;
    h[3]->addWidget(inserisci_porzione);
    h[3]->addWidget(inserisci_campo[3]);
    inserisci_campo[3]->setEnabled(false);

    h[4]=new QHBoxLayout;
    QLabel* inserisci_integrale=new QLabel("Pasta Integrale: (Si/No)");
    inserisci_campo[4]=new QLineEdit;
    h[4]->addWidget(inserisci_integrale);
    h[4]->addWidget(inserisci_campo[4]);
    inserisci_campo[4]->setEnabled(false);

    h[5]=new QHBoxLayout;
    QLabel* inserisci_surgelati=new QLabel("Prodotti Surgelati: (Si/No)");
    inserisci_campo[5]=new QLineEdit;
    h[5]->addWidget(inserisci_surgelati);
    h[5]->addWidget(inserisci_campo[5]);
    inserisci_campo[5]->setEnabled(false);

    h[6]=new QHBoxLayout;
    QLabel* inserisci_artigianale=new QLabel("Prodotto Artigianale: (Si/No)");
    inserisci_campo[6]=new QLineEdit;
    h[6]->addWidget(inserisci_artigianale);
    h[6]->addWidget(inserisci_campo[6]);
    inserisci_campo[6]->setEnabled(false);

    conferma_aggiunta=new QPushButton("Inserisci nel Menù");
    connect(conferma_aggiunta, SIGNAL(clicked()), this, SLOT(conferma_inserimento()));


    mainLayout_aggiunta->addLayout(menu_categoria);
    mainLayout_aggiunta->addLayout(h[0]);
    mainLayout_aggiunta->addLayout(h[1]);
    mainLayout_aggiunta->addLayout(h[2]);
    mainLayout_aggiunta->addLayout(h[3]);
    mainLayout_aggiunta->addLayout(h[4]);
    mainLayout_aggiunta->addLayout(h[5]);
    mainLayout_aggiunta->addLayout(h[6]);
    mainLayout_aggiunta->addWidget(conferma_aggiunta);
    dialog_aggiunta->setLayout(mainLayout_aggiunta);
    dialog_aggiunta->exec();

}

void admin_dialog::elimina_menu() {

    if(lista->rowCount()==0) {
        Avvisi msgBox("Non hai selezionato alcuna voce");
    }
    else{
        if(lista->currentIndex().row()==-1){
            Avvisi msgBox("Non hai selezionato alcuna voce");
        }
         else{
        string n=lista->item(lista->currentRow(),0)->text().toStdString();
    if(dynamic_cast<Bevande*>(il_menu->trova(n))){
        il_menu->elimina(n);delete il_menu;
        il_menu=new Menu();
        bevande();
    }
    if(dynamic_cast<Contorni*>(il_menu->trova(n))){
        il_menu->elimina(n);delete il_menu;
        il_menu=new Menu();
        contorni();
    }
    if(dynamic_cast<Pizze*>(il_menu->trova(n))){
        il_menu->elimina(n);delete il_menu;
        il_menu=new Menu();
        pizze();
    }
    if(dynamic_cast<Dolci*>(il_menu->trova(n))){
        il_menu->elimina(n);delete il_menu;
        il_menu=new Menu();
        dolci();
    }


}
    }

}



void admin_dialog::aggiunta_bevanda(){
    inserisci_campo[0]->setEnabled(true);
    inserisci_campo[1]->setEnabled(true);
    inserisci_campo[2]->setEnabled(true);
    inserisci_campo[3]->setEnabled(false);
    inserisci_campo[4]->setEnabled(false);
    inserisci_campo[5]->setEnabled(false);
    inserisci_campo[6]->setEnabled(false);
    inserisci_campo[0]->setText("");
    inserisci_campo[1]->setText("");
    inserisci_campo[2]->setText("");
    inserisci_campo[3]->setText("");
    inserisci_campo[4]->setText("");
    inserisci_campo[5]->setText("");
    inserisci_campo[6]->setText("");
}

void admin_dialog::aggiunta_contorno(){
    inserisci_campo[0]->setEnabled(true);
    inserisci_campo[1]->setEnabled(true);
    inserisci_campo[2]->setEnabled(false);
    inserisci_campo[3]->setEnabled(true);
    inserisci_campo[4]->setEnabled(false);
    inserisci_campo[5]->setEnabled(false);
    inserisci_campo[6]->setEnabled(false);
    inserisci_campo[0]->setText("");
    inserisci_campo[1]->setText("");
    inserisci_campo[2]->setText("");
    inserisci_campo[3]->setText("");
    inserisci_campo[4]->setText("");
    inserisci_campo[5]->setText("");
    inserisci_campo[6]->setText("");

}

void admin_dialog::aggiunta_pizza(){
    inserisci_campo[0]->setEnabled(true);
    inserisci_campo[1]->setEnabled(true);
    inserisci_campo[2]->setEnabled(false);
    inserisci_campo[3]->setEnabled(false);
    inserisci_campo[4]->setEnabled(true);
    inserisci_campo[5]->setEnabled(true);
    inserisci_campo[6]->setEnabled(false);
    inserisci_campo[0]->setText("");
    inserisci_campo[1]->setText("");
    inserisci_campo[2]->setText("");
    inserisci_campo[3]->setText("");
    inserisci_campo[4]->setText("");
    inserisci_campo[5]->setText("");
    inserisci_campo[6]->setText("");
}

void admin_dialog::aggiunta_dolce(){
    inserisci_campo[0]->setEnabled(true);
    inserisci_campo[1]->setEnabled(true);
    inserisci_campo[2]->setEnabled(false);
    inserisci_campo[3]->setEnabled(false);
    inserisci_campo[4]->setEnabled(false);
    inserisci_campo[5]->setEnabled(false);
    inserisci_campo[6]->setEnabled(true);
    inserisci_campo[0]->setText("");
    inserisci_campo[1]->setText("");
    inserisci_campo[2]->setText("");
    inserisci_campo[3]->setText("");
    inserisci_campo[4]->setText("");
    inserisci_campo[5]->setText("");
    inserisci_campo[6]->setText("");
}

void admin_dialog::conferma_inserimento(){
    QString nome=inserisci_campo[0]->text();
    QString costo=inserisci_campo[1]->text();
    QString litro=inserisci_campo[2]->text();
    QString porzione=inserisci_campo[3]->text();
    QString integrale=inserisci_campo[4]->text();
    QString surgelati=inserisci_campo[5]->text();
    QString artigianale=inserisci_campo[6]->text();
    bool trovato=false;
    if(!litro.isEmpty() && !nome.isEmpty() && !costo.isEmpty())
        {
        trovato=true;
        if(!litro.toDouble() || !costo.toDouble())
            Avvisi msg("Uno o più campi non sono stati inseriti correttamente!");
        if(il_menu->trova(nome.toStdString()))
             Avvisi msg("La voce inserita è già presente nel menù!");
        else{
            il_menu->aggiungi_bevanda(nome,costo,litro);
            dialog_aggiunta->close();delete il_menu;
            il_menu=new Menu();bevande();
            }
        }

    if(!porzione.isEmpty() && !nome.isEmpty() && !costo.isEmpty())
        {
        trovato=true;
        if(!porzione.toInt() || !costo.toDouble())
           Avvisi msg("Uno o più campi non sono stati inseriti correttamente!");
        if(il_menu->trova(nome.toStdString()))
             Avvisi msg("La voce inserita è già presente nel menù!");
        else{
            il_menu->aggiungi_contorno(nome,costo,porzione);
            dialog_aggiunta->close();delete il_menu;
            il_menu=new Menu();contorni();
             }
        }

    if(!integrale.isEmpty() && !surgelati.isEmpty() && !nome.isEmpty() && !costo.isEmpty())
        {
        trovato=true;
        if(!costo.toDouble())
        Avvisi msg("Uno o più campi non sono stati inseriti correttamente!");
        if(il_menu->trova(nome.toStdString()))
             Avvisi msg("La voce inserita è già presente nel menù!");
        else{
            il_menu->aggiungi_pizza(nome,costo,integrale,surgelati);
            dialog_aggiunta->close();delete il_menu;
             il_menu=new Menu();pizze();
            }
        }

    if(!artigianale.isEmpty() && !nome.isEmpty() && !costo.isEmpty())
        {
        trovato=true;
        if(!costo.toDouble())
            Avvisi msg("Uno o più campi non sono stati inseriti correttamente!");
        if(il_menu->trova(nome.toStdString()))
             Avvisi msg("La voce inserita è già presente nel menù!");
        else{
            il_menu->aggiungi_dolce(nome,costo,artigianale);
            dialog_aggiunta->close();delete il_menu;
            il_menu=new Menu();dolci();
            }
        }

    else{
        if(!trovato){
        Avvisi msgBox("Non hai inserito tutti i campi necessari");}
    }




}


