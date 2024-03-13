#ifndef STARTUPWINDOW_H
#define STARTUPWINDOW_H

#include <QDialog>
#include "qpushbutton.h"
#include <qwidget.h>
#include <QLabel>
#include <QBoxLayout>
#include <gamewindow.h>

namespace Ui {
class StartupWindow;
}

class StartupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartupWindow(QWidget *parent = nullptr);
    ~StartupWindow();
    void on_difficulty_slug_clicked();
    void on_difficulty_worm_clicked();
    void on_difficulty_python_clicked();
    void on_one_player_clicked();
    void on_two_player_clicked();
    void on_start_game_clicked();

private:
    Ui::StartupWindow *ui;
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
    GameWindow *gameWindow;
};

#endif // STARTUPWINDOW_H
