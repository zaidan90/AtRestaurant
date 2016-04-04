#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "contenitore.h"
#include "prodotti.h"
#include "bevande.h"
#include "contorni.h"
#include "pizze.h"
#include "dolci.h"
#include <QtXml>
#include <QMessageBox>
using namespace std;

class Menu
{

public:
    Menu();
    contenitore prodotti;
    Prodotti* trova(string);
    void load();
    void aggiungi_bevanda(QString,QString,QString);
    void aggiungi_contorno(QString, QString, QString );
    void aggiungi_pizza(QString,QString,QString,QString);
    void aggiungi_dolce(QString,QString,QString);
    void elimina(string);
};

#endif // MENU_H
