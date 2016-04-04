#ifndef ADMIN_DIALOG_H
#define ADMIN_DIALOG_H

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
#include "avvisi.h"


using namespace std;

class admin_dialog : public QDialog
{
    Q_OBJECT
public:
    admin_dialog();
public slots:
    void aggiungi_menu();
    void elimina_menu();
    void bevande();
    void contorni();
    void pizze();
    void dolci();
    void aggiunta_bevanda();
    void aggiunta_contorno();
    void aggiunta_pizza();
    void aggiunta_dolce();
    void conferma_inserimento();

private:
    Menu* il_menu;
    QTableWidget *lista;
    QGroupBox *menu;
    QPushButton* bottoni_menu[4];
    QGroupBox *lista_menu;
    QDialog* dialog_aggiunta;
    QVBoxLayout* mainLayout_aggiunta;
    QVBoxLayout* aggiunta_campi;
    QLineEdit *inserisci_campo[7];
    QPushButton* b[4];
    QGridLayout* grid_aggiunta_campi;
    QHBoxLayout* h[7];
    QPushButton*conferma_aggiunta;
};

#endif // ADMIN_DIALOG_H
