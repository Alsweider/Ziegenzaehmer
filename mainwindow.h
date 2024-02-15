#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <random>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonStart_clicked();
    void ziegenZaehmen();

    void on_pushButtonStop_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    void werteDefinieren();
    int torWahl, torWahl2, torErgebnis;
    int rundenZaehler; //nur bis 1000
    int delay;
    int ziegeAussortieren;
    int zaehlerNG, zaehlerNV, zaehlerGG, zaehlerGV;
    int rundenAnzahl;

};
#endif // MAINWINDOW_H
