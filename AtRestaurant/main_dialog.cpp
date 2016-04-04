#include "main_dialog.h"

main_dialog::main_dialog()
{
 QVBoxLayout* mainLayout=new QVBoxLayout;
 setWindowTitle("@Restaurant");
 scegli_accesso = new QLabel("Scegli la modalità di accesso al programma");
 scegli_accesso->setAlignment(Qt::AlignCenter);

 QFont font = scegli_accesso->font();
 font.setPointSize(font.pointSize() + 6);
 scegli_accesso->setFont(font);
 immagine=new QLabel;
 immagine->setPixmap(QPixmap("../AtRestaurant/data/logo.png"));
 immagine->setAlignment(Qt::AlignCenter);
 QHBoxLayout* hbox=new QHBoxLayout;
 bottoni[0] = new QPushButton("Admin");
 hbox->addWidget(bottoni[0]);
 // connessione signal-slot
 connect(bottoni[0], SIGNAL(clicked()), this, SLOT(accesso_admin()));
 bottoni[1] = new QPushButton("User");
 hbox->addWidget(bottoni[1]);
 // connessione signal-slot
 connect(bottoni[1], SIGNAL(clicked()), this, SLOT(accesso_user()));
 mainLayout->addWidget(immagine);
 mainLayout->addWidget(scegli_accesso);
 mainLayout->addLayout(hbox);
 setLayout(mainLayout);
}


void main_dialog::accesso_admin(){
    login=new QDialog;

    QGridLayout* layout = new QGridLayout;



    labels = new QLabel(tr("Password:"));
    lineEdits = new QLineEdit;
    lineEdits->setEchoMode(QLineEdit::Password);
    layout->addWidget(labels,0, 0);
    layout->addWidget(lineEdits,0, 1);
    QPushButton *pulsante_login=new QPushButton("Login");
    connect(pulsante_login, SIGNAL(clicked()), this, SLOT(submit_login()));
    layout->addWidget(pulsante_login, 2,0,1,2 );
    login->setLayout(layout);
    login->exec();

}


void main_dialog::accesso_user(){
    Dialog dialog;
    close();
    dialog.exec();

}

void main_dialog::submit_login(){
    string password=lineEdits->text().toStdString();

    if(password=="admin"){

        admin_dialog dialog;
        login->close();
        close();
        dialog.exec();
    }
     else
       lineEdits->setText("*non corretto!");

}
