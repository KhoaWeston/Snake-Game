#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QPainter>
#include <QRandomGenerator64>
#include <QTimer>
#include <QKeyEvent>
#include <vector>
#include <QMessageBox>
#include <QDebug> // qInfo() <<

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();


enum eDirections{
        START,
        LEFT,
        RIGHT,
        UP,
        DOWN
};

    virtual void paintEvent(QPaintEvent *event);
    void eat(int, int);
    void reset();
    void gameOverMessage(QString);
    void setDirection(bool&, QTimer*, eDirections, eDirections, std::vector<eDirections>&);
    void setCoordinate(std::vector<int>&, std::vector<std::vector<int>>&, int, int );
    void setPosition(std::vector<eDirections>&);
    void switchDirection(std::vector<eDirections>&, int&, int&);

    // Game variables
    std::vector<eDirections> list_dir1;
    std::vector<eDirections> list_dir2;
    bool multi_player;
    int header_height, win_width, board_height;
    int tile_size;
    int score1, score2, highscore;
    bool game_start1;
    bool game_start2;
    int num_cols;
    int num_rows;
    float t_interval;

    // Inital positons for apple and snakes
    int apple_posx;
    int apple_posy;
    int snake1_posX;
    int snake1_posY;
    int snake2_posX;
    int snake2_posY;

    // Stores the positions of the snake's body segments
    std::vector<std::vector<int>> snake1_body;
    std::vector<std::vector<int>> snake2_body;

    bool bounce;
    int bounce_ctr;

    QWidget *start_up_w = new QWidget;

public slots:
    void logic();
    void stop1();
    void stop2();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::GameWindow *ui;
    QTimer * logic_timer;
    QTimer * move_timer1;
    QTimer * move_timer2;
};

#endif // GAMEWINDOW_H
