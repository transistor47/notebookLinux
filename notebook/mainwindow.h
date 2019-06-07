#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_actionGuardar_como_triggered();

    void on_actionCopiar_triggered();

    void on_actionCortar_triggered();

    void on_actionPegar_triggered();

    void on_actionSalir_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionColor_triggered();

    void on_actionTipo_triggered();

    void on_actionColor_2_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
