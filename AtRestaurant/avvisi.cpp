#include "avvisi.h"

Avvisi::Avvisi(QString q)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("@Restaurant-Attenzione");
    msgBox.setText(q);
    msgBox.addButton(QMessageBox::Ok);
    msgBox.exec();
}
