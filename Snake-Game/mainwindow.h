#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>
#include <qwidget.h>
#include <QLabel>
#include <QBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_difficulty_slug_clicked();
    void on_difficulty_worm_clicked();
    void on_difficulty_python_clicked();
    void on_one_player_clicked();
    void on_two_player_clicked();
    void on_start_game_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *h_label_1;
    QLabel *h_label_11;
    QLabel *h_label_2;
    QLabel *pic_label;
    QLabel *info_label;
    QLabel *bigName_label;
    QLabel *player_amount_label;
    QPushButton *difficulty_slug;
    QPushButton *difficulty_worm;
    QPushButton *difficulty_python;
    QPushButton *one_player;
    QPushButton *two_player;
    QPushButton *start_game;
};
#endif // MAINWINDOW_H
