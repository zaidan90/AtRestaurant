#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QFont>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QListWidget>
#include "menu.h"
#include <typeinfo>
#include <QTableWidget>
#include <iostream>
#include "tavolo.h"
#include "prodotti.h"
#include <QHeaderView>
#include <QMessageBox>
#include "avvisi.h"

using namespace std;

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog();
    int indice;
    void create_ordine();
public slots:
    void bevande();
    void contorni();
    void pizze();
    void dolci();
    void aggiungi_ordine();
    void crea_tavolo();
    void calcola_conto();
    void visualizza_ordine();
    void ordine_confermato();
    void ordine_cancellato();
    void chiudi_ordine();
    void paga_ordine();
private:
    void createLinEdit();
    void createMenu();
    void createLista();
    Menu* listino;
    Tavolo* nuovo_tavolo;
    QLineEdit* lineEdits[2];
    QGroupBox* tavolo;
    QGroupBox* menu;
    QGroupBox* lista_menu;
    QPushButton* bottoni_menu[4];
    QLabel* labels[2];
    QMenuBar* menuBar;
    QMenu* fileMenu;
    QTableWidget *lista;
    QPushButton *aggiungi;
    QPushButton *conferma_tavolo;
    QPushButton *vedi_ordine;
    QPushButton *vedi_conto;
    QPushButton *conferma_ordine;
    QDialog *q;
    QTableWidget * lista_tuo_ordine;
    QTableWidget * lista_tuo_conto;
    QDialog *q_conto;


};

#endif // DIALOG_H
