#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    werteDefinieren();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ziegenZaehmen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::ziegenZaehmen(){
    rundenZaehler++;

    rundenAnzahl = ui->spinBoxRunden->value();

    if (rundenZaehler <= rundenAnzahl){

        ui->torZaehler1->setText("(verdeckt)");
        ui->torZaehler2->setText("(verdeckt)");
        ui->torZaehler3->setText("(verdeckt)");


        //In welcher Runde sind wir überhaupt?
        ui->labelRunden->setText(QString::number(rundenZaehler));

        //Zufallszahlen generieren
        std::random_device generator;
        std::mt19937 engine(generator());
        std::uniform_int_distribution<int> distribution(1, 3);

        //hinter welchem Tor befindet sich der Gewinn?
        torErgebnis = distribution(engine);

        if (torErgebnis == 1){
            ui->torZaehler1->setText("Gewinn");
            ui->torZaehler2->setText("Ziege");
            ui->torZaehler3->setText("Ziege");
        }

        if (torErgebnis == 2){
            ui->torZaehler1->setText("Ziege");
            ui->torZaehler2->setText("Gewinn");
            ui->torZaehler3->setText("Ziege");
        }

        if (torErgebnis == 3){
            ui->torZaehler1->setText("Ziege");
            ui->torZaehler2->setText("Ziege");
            ui->torZaehler3->setText("Gewinn");
        }

        //welches Tor will der Spieler aufdecken?
        torWahl = distribution(engine);

        //Ziege aussortieren. Generiere, bis ziegeAussortieren != unerwünschtes Ergebnis.
        do{
            ziegeAussortieren = distribution(engine);
        } while ((ziegeAussortieren == 0) || (ziegeAussortieren == torWahl) || (ziegeAussortieren == torErgebnis));


        //hätte Spieler im ersten Zug gewonnen?
        if (torWahl == torErgebnis){
            zaehlerNG++;
        } else{
            zaehlerNV++;
        }


        //Fall: Spieler wechselt Tor
        do{
            torWahl2 = distribution(engine);
        } while ((torWahl2 == 0) || (torWahl2 == ziegeAussortieren) || (torWahl2 == torWahl));


        //hätte Spieler im zweiten Zug gewonnen?
            if (torWahl2 == torErgebnis){
            zaehlerGG++;
        } else{
            zaehlerGV++;
        }

        //labels aktualisieren
        ui->nGewonnen->setText(QString::number(zaehlerNG));
        ui->nVerloren->setText(QString::number(zaehlerNV));
        ui->gGewonnen->setText(QString::number(zaehlerGG));
        ui->gVerloren->setText(QString::number(zaehlerGV));


    } else {
        timer->stop();
        werteDefinieren();
    }


}


void MainWindow::on_pushButtonStart_clicked()
{
    timer->stop();
    werteDefinieren();
    delay = ui->spinBoxDelay->value();
    timer->start(delay);

}

void MainWindow::werteDefinieren(){
    rundenZaehler = 0;
    ziegeAussortieren = 0;
    delay = 0;
    torWahl = 0;
    torWahl2 = 0;
    torErgebnis = 0;
    rundenZaehler = 0;
    ziegeAussortieren = 0;
    zaehlerNG = 0;
    zaehlerNV = 0;
    zaehlerGG = 0;
    zaehlerGV = 0;
    rundenAnzahl = 0;
}


void MainWindow::on_pushButtonStop_clicked()
{
    timer->stop();
}

