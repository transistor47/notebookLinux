#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFontDialog>
#include <QColorDialog>

//Tutorial de la url: https://www.youtube.com/watch?v=fh7PdWCw_C4&list=PL54fdmMKYUJvn4dAvziRopztp47tBRNum&index=39

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->texto);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    QFile arch;
    QTextStream io;
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getOpenFileName(this, "Abrir");
    if (nombreArchivo.isEmpty())
        return;
    arch.setFileName(nombreArchivo);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!arch.isOpen()){
        QMessageBox::critical(this, "Error", arch.errorString());
        return;
       }

    io.setDevice(&arch);
    ui->texto->setText(io.readAll());

    arch.close();


}

void MainWindow::on_actionGuardar_como_triggered()
{
    QFile arch;
    QTextStream io;
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getSaveFileName(this, "Guardar");
    if (nombreArchivo.isEmpty())
        return;
    arch.setFileName(nombreArchivo);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!arch.isOpen()){
        QMessageBox::critical(this, "Error", arch.errorString());
        return;
       }

    io.setDevice(&arch);
    io << ui->texto->toPlainText();
    arch.flush();
    arch.close();

}

void MainWindow::on_actionCopiar_triggered()
{
    ui->texto->copy();
}

void MainWindow::on_actionCortar_triggered()
{
    ui->texto->cut();
}

void MainWindow::on_actionPegar_triggered()
{
    ui->texto->paste();
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QString mensaje;
    mensaje = "Autor: transistor47\n";
    mensaje += "Editor de textos simple";
    QMessageBox::about(this, "NotebookLinux", mensaje);
}

void MainWindow::on_actionColor_triggered()
{
    ui->texto->setTextColor(QColorDialog::getColor(Qt::white, this));
}

void MainWindow::on_actionTipo_triggered()
{
    bool ok;
    QFont fuente;
    fuente = QFontDialog::getFont(&ok, this);
    if (!ok)
        return;
    ui->texto->setFont(fuente);
}

void MainWindow::on_actionColor_2_triggered()
{
  ui->texto->setPalette(QPalette(QColorDialog::getColor(Qt::white, this)));
}
