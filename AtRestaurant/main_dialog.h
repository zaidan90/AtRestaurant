#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include "admin_dialog.h"
#include "dialog.h"

#include <iostream>


using namespace std;

class main_dialog : public QDialog
{
    Q_OBJECT
public:
    main_dialog();
public slots:
    void accesso_admin();
    void accesso_user();
    void submit_login();
private:
    QPushButton* bottoni[2];
    QLabel* immagine;
    QLineEdit* benvenuto;
    QLabel* scegli_accesso;
    QDialog* login;
    QLabel* labels;
    QLineEdit* lineEdits;
};

#endif // MAIN_DIALOG_H
