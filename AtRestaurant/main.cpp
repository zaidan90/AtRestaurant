#include <QApplication>
#include "main_dialog.h"
#include <iostream>
#include "contenitore.h"
using namespace std;

#include "tavolo.h"
#include "menu.h"
#include "bevande.h"
#include "prodotti.h"

int main(int argc, char* argv[]) {


  // La classe QApplication controlla il flusso di esecuzione della GUI
  QApplication app(argc, argv);


  // Finestra Principale
  main_dialog dialog;

  // il main passa il controllo a QT
  return dialog.exec();
}

