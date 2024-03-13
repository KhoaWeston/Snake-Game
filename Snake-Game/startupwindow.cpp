#include "startupwindow.h"
#include "ui_startupwindow.h"
#include <QLabel>
#include <QBoxLayout>
#include <QFontDatabase>
#include <QDebug>
#include <gamewindow.h>

StartupWindow::StartupWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartupWindow)
{
    ui->setupUi(this);

//Fonts setup
    QFontDatabase::addApplicationFont(":/fonts/PressStart2P-vaV7.ttf");
    QFont PressStart2P_9 = QFont("Press Start 2P", 9, 0);
    QFont PressStart2P_15 = QFont("Press Start 2P", 15, 0);
    QFont PressStart2P_20 = QFont("Press Start 2P", 20, 0);
    QFont PressStart2P_40 = QFont("Press Start 2P", 40, 0);

    QHBoxLayout *H9Layout = new QHBoxLayout();
    QHBoxLayout *H8Layout = new QHBoxLayout();
    QHBoxLayout *H7Layout = new QHBoxLayout();
    QHBoxLayout *H6Layout = new QHBoxLayout();
    QHBoxLayout *H5Layout = new QHBoxLayout();
    QHBoxLayout *H4Layout = new QHBoxLayout();
    QHBoxLayout *H3Layout = new QHBoxLayout();
    QHBoxLayout *H2Layout = new QHBoxLayout();
    QHBoxLayout *H1Layout = new QHBoxLayout();
    QHBoxLayout *H0Layout = new QHBoxLayout();

    QVBoxLayout *VLayout = new QVBoxLayout();

    int size_button_diff_H = 164, size_button_diff_V = 40;
    int size_button_sg_H = 320, size_button_sg_V = 50;
    int size_label_Hline_H = 450;
    int size_label_pic_H = 512, size_label_pic_V = 512;
    int size_mainWindow_H = 532, size_mainWindow_V = 922;

//Snake big name label
    bigName_label = new QLabel("~SNAKE~", this);
    bigName_label->setAlignment(Qt::AlignCenter);
    bigName_label->setFont(PressStart2P_40);

//Image label
    pic_label = new QLabel(this);
    QPixmap pixmap(":/images/2.png");
    pic_label->setPixmap(pixmap);
    pic_label->setFixedSize(size_label_pic_H, size_label_pic_V);

//Instructions label
    info_label = new QLabel("Use W, A, S, and D, to navigate the snake\n"
                            "around the play area to collect apples, \n"
                            "but don't run into the walls!",this);
    info_label->setStyleSheet("line-height: 10px;");
    info_label->setAlignment(Qt::AlignCenter);
    info_label->setFont(PressStart2P_9);

//Select a difficulty label
    h_label_2 = new QLabel("Select a difficulty", this);
    h_label_2->setFont(PressStart2P_15);

//Difficulty Buttons
    difficulty_slug = new QPushButton("Slug", this);
    connect(difficulty_slug, &QPushButton::released, this, &StartupWindow::on_difficulty_slug_clicked);
    difficulty_slug->setFixedSize(size_button_diff_H, size_button_diff_V);
    difficulty_slug->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }"); //Button Color
    difficulty_slug->setFont(PressStart2P_15);

    difficulty_worm = new QPushButton("Worm", this);
    connect(difficulty_worm, &QPushButton::released, this, &StartupWindow::on_difficulty_worm_clicked);
    difficulty_worm->setFixedSize(size_button_diff_H, size_button_diff_V);
    difficulty_worm->setStyleSheet("background-color: rgb(100, 100, 100);"
                                   "border:6px solid rgb(50, 50, 50);");
    difficulty_worm->setFont(PressStart2P_15);

    difficulty_python = new QPushButton("Python", this);
    connect(difficulty_python, &QPushButton::released, this, &StartupWindow::on_difficulty_python_clicked);
    difficulty_python->setFixedSize(size_button_diff_H, size_button_diff_V);
    difficulty_python->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }");
    difficulty_python->setFont(PressStart2P_15);

//Horizontal line label 1
    h_label_1 = new QLabel(this);
    h_label_1->setFrameShape(QFrame::HLine);
    h_label_1->setFixedWidth(size_label_Hline_H);

//Number of Players
    player_amount_label = new QLabel("Number of Players", this);
    player_amount_label->setFont(PressStart2P_15);

//One Player Button
    one_player = new QPushButton("One", this);
    connect(one_player, &QPushButton::released, this, &StartupWindow::on_one_player_clicked);
    one_player->setFont(PressStart2P_15);
    one_player->setStyleSheet("background-color: rgb(100, 100, 100);"
                              "border:6px solid rgb(50, 50, 50);");
    one_player->setFixedSize(size_button_diff_H, size_button_diff_V);

//Two Player Button
    two_player = new QPushButton("Two", this);
    connect(two_player, &QPushButton::released, this, &StartupWindow::on_two_player_clicked);
    two_player->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }");
    two_player->setFont(PressStart2P_15);
    two_player->setFixedSize(size_button_diff_H, size_button_diff_V);

//Horizontal line label 11
    h_label_11 = new QLabel(this);
    h_label_11->setFrameShape(QFrame::HLine);
    h_label_11->setFixedWidth(size_label_Hline_H);

//Start Game Button
    start_game = new QPushButton("Start Game!", this);
    connect(start_game, &QPushButton::released, this, &StartupWindow::on_start_game_clicked);
    start_game->setFixedSize(size_button_sg_H, size_button_sg_V);
    start_game->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }");
    start_game->setFont(PressStart2P_20);


///////////////////////////////////////////////////////////////////////////////////////

    H9Layout->addStretch();
    H9Layout->addWidget(bigName_label); //Big name label
    H9Layout->addStretch();

    H8Layout->addStretch();
    H8Layout->addWidget(pic_label); //image
    H8Layout->addStretch();

    H7Layout->addStretch();
    H7Layout->addWidget(info_label); //Instructions on how to play
    H7Layout->addStretch();

    H6Layout->addStretch();
    H6Layout->addWidget(h_label_2); //"Select a Difficulty"
    H6Layout->addStretch();

    H5Layout->addStretch();
    H5Layout->addWidget(difficulty_slug);
    H5Layout->addSpacing(10);
    H5Layout->addWidget(difficulty_worm); //Difficulties
    H5Layout->addSpacing(10);
    H5Layout->addWidget(difficulty_python);
    H5Layout->addStretch();
    H5Layout->setSpacing(0);

    H4Layout->addStretch();
    H4Layout->addWidget(h_label_1); //Horizontal Line
    H4Layout->addStretch();

    H3Layout->addStretch();
    H3Layout->addWidget(player_amount_label); //Player Amount Label
    H3Layout->addStretch();

    H2Layout->addStretch();
    H2Layout->addWidget(one_player); //Player Amount Buttons
    H2Layout->addWidget(two_player);
    H2Layout->addStretch();

    H1Layout->addStretch();
    H1Layout->addWidget(h_label_11); //Horizontal Line
    H1Layout->addStretch();

    H0Layout->addStretch();
    H0Layout->addWidget(start_game); //Start Game
    H0Layout->addStretch();

///////////////////////////////////////////////////////////////////////////////////////

    VLayout->addStretch();
    VLayout->addSpacing(2);
    VLayout->addLayout(H9Layout); //Snake big name
    VLayout->addLayout(H8Layout); //image
    VLayout->addSpacing(5);
    VLayout->addLayout(H7Layout); //Instructions on how to play
    VLayout->addSpacing(5);
    VLayout->addLayout(H6Layout); //"Select Difficulty"
    VLayout->addSpacing(2);
    VLayout->addLayout(H5Layout); // Difficulties
    VLayout->addSpacing(0);
    VLayout->addLayout(H4Layout); //Horizontal Line
    VLayout->addSpacing(0);
    VLayout->addLayout(H3Layout); //Player Amount Label
    VLayout->addSpacing(0);
    VLayout->addLayout(H2Layout); //Player Amount Buttons
    VLayout->addSpacing(0);
    VLayout->addLayout(H1Layout); //Horizontal Line
    VLayout->addSpacing(0);
    VLayout->addLayout(H0Layout); //Start Game
    VLayout->addStretch();

///////////////////////////////////////////////////////////////////////////////////////

    setLayout(VLayout);
    setStyleSheet("background-color: rgb(118,178,78);");
    show();
    setFixedSize(size_mainWindow_H, size_mainWindow_V); //Fixes size of main window
}

void StartupWindow::on_difficulty_slug_clicked()
{
//    t_interval = VALUE;
    difficulty_slug->setStyleSheet("background-color: rgb(100, 100, 100);"
                                   "border:6px solid rgb(50, 50, 50);");
    difficulty_worm->setStyleSheet("background-color: rgb(100, 100, 100);");
    difficulty_python->setStyleSheet("background-color: rgb(100, 100, 100);");
    qInfo() << "slug";
}

void StartupWindow::on_difficulty_worm_clicked()
{
//    t_interval = VALUE;
    difficulty_worm->setStyleSheet("background-color: rgb(100, 100, 100);"
                                   "border:6px solid rgb(50, 50, 50);");
    difficulty_slug->setStyleSheet("background-color: rgb(100, 100, 100);");
    difficulty_python->setStyleSheet("background-color: rgb(100, 100, 100);");
    qInfo() << "worm";
}

void StartupWindow::on_difficulty_python_clicked()
{
//    t_interval = VALUE;
    difficulty_python->setStyleSheet("background-color: rgb(100, 100, 100);"
                                   "border:6px solid rgb(50, 50, 50);");
    difficulty_slug->setStyleSheet("background-color: rgb(100, 100, 100);");
    difficulty_worm->setStyleSheet("background-color: rgb(100, 100, 100);");
    qInfo() << "python";
}

void StartupWindow::on_one_player_clicked()
{
//    two_player = FALSE;
    one_player->setStyleSheet("background-color: rgb(100, 100, 100);"
                              "border:6px solid rgb(50, 50, 50);");
    two_player->setStyleSheet("background-color: rgb(100, 100, 100);");
    qInfo() << "one player";
}

void StartupWindow::on_two_player_clicked()
{
//    two_player = TRUE;
    two_player->setStyleSheet("background-color: rgb(100, 100, 100);"
                              "border:6px solid rgb(50, 50, 50);");
    one_player->setStyleSheet("background-color: rgb(100, 100, 100);");
    qInfo() << "two player";
}

void StartupWindow::on_start_game_clicked()
{
    hide();
    gameWindow = new GameWindow(this);
    gameWindow->show();
}

StartupWindow::~StartupWindow()
{
    delete ui;
}
