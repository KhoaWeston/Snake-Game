#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QBoxLayout>
#include <QFontDatabase>

int difficulty = 0; //0 = unpicked, 1 = slug, 2 = worm, 3 = python

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//Fonts setup
    QFontDatabase::addApplicationFont(":/fonts/PressStart2P-vaV7.ttf");
    QFont PressStart2P_9 = QFont("Press Start 2P", 9, 0);
    QFont PressStart2P_15 = QFont("Press Start 2P", 15, 0);
    QFont PressStart2P_20 = QFont("Press Start 2P", 20, 0);
    QFont PressStart2P_40 = QFont("Press Start 2P", 40, 0);

    QWidget *start_up_w = new QWidget;
    QHBoxLayout *H0Layout = new QHBoxLayout();
    QHBoxLayout *H1Layout = new QHBoxLayout();
    QHBoxLayout *H2Layout = new QHBoxLayout();
    QHBoxLayout *H3Layout = new QHBoxLayout();
    QHBoxLayout *H4Layout = new QHBoxLayout();
    QHBoxLayout *H5Layout = new QHBoxLayout();
    QHBoxLayout *H6Layout = new QHBoxLayout();
    QVBoxLayout *VLayout = new QVBoxLayout();

    int size_button_diff_H = 164, size_button_diff_V = 40;
    int size_button_sg_H = 320, size_button_sg_V = 60;
    int size_label_Hline_H = 450;
    int size_label_pic_H = 512, size_label_pic_V = 512;
    int size_mainWindow_H = 532, size_mainWindow_V = 832;

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
    connect(difficulty_slug, &QPushButton::released, this, &MainWindow::on_difficulty_slug_clicked);
    difficulty_slug->setFixedSize(size_button_diff_H, size_button_diff_V);
    difficulty_slug->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }"); //Button Color
    difficulty_slug->setFont(PressStart2P_15);

    difficulty_worm = new QPushButton("Worm", this);
    connect(difficulty_worm, &QPushButton::released, this, &MainWindow::on_difficulty_worm_clicked);
    difficulty_worm->setFixedSize(size_button_diff_H, size_button_diff_V);
    difficulty_worm->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }");
    difficulty_worm->setFont(PressStart2P_15);

    difficulty_python = new QPushButton("Python", this);
    connect(difficulty_python, &QPushButton::released, this, &MainWindow::on_difficulty_python_clicked);
    difficulty_python->setFixedSize(size_button_diff_H, size_button_diff_V);
    difficulty_python->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }");
    difficulty_python->setFont(PressStart2P_15);

//Horizontal line label
    h_label_1 = new QLabel(this);
    h_label_1->setFrameShape(QFrame::HLine);
    h_label_1->setMaximumWidth(size_label_Hline_H);

//Start Game Button
    start_game = new QPushButton("Start Game!", this);
    connect(start_game, &QPushButton::released, this, &MainWindow::on_start_game_clicked);
    start_game->setFixedSize(size_button_sg_H, size_button_sg_V);
    start_game->setStyleSheet("QPushButton { background-color: rgb(100, 100, 100); }");
    start_game->setFont(PressStart2P_20);

///////////////////////////////////////////////////////////////////////////////////////

    H6Layout->addStretch();
    H6Layout->addWidget(bigName_label); //Big name label
    H6Layout->addStretch();

    H5Layout->addStretch();
    H5Layout->addWidget(pic_label); //image
    H5Layout->addStretch();

    H4Layout->addStretch();
    H4Layout->addWidget(info_label); //Instructions on how to play
    H4Layout->addStretch();

    H3Layout->addStretch();
    H3Layout->addWidget(h_label_2); //"Select a Difficulty"
    H3Layout->addStretch();

    H2Layout->addStretch();
    H2Layout->addWidget(difficulty_slug);
    H2Layout->addSpacing(10);
    H2Layout->addWidget(difficulty_worm); //Difficulties
    H2Layout->addSpacing(10);
    H2Layout->addWidget(difficulty_python);
    H2Layout->addStretch();
    H2Layout->setSpacing(0);

    H1Layout->insertSpacing(0, 5);
    H1Layout->addWidget(h_label_1); //Horizontal Line
    H1Layout->insertSpacing(2, 5);

    H0Layout->insertStretch(0);
    H0Layout->addWidget(start_game); //Start Game
    H0Layout->insertStretch(2);

///////////////////////////////////////////////////////////////////////////////////////

    VLayout->addStretch();
    VLayout->addSpacing(2);
    VLayout->addLayout(H6Layout); //Snake big name
    VLayout->addLayout(H5Layout); //image
    VLayout->addSpacing(20);
    VLayout->addLayout(H4Layout); //Instructions on how to play
    VLayout->addSpacing(5);
    VLayout->addLayout(H3Layout); //"Select Difficulty"
    VLayout->addSpacing(10);
    VLayout->addLayout(H2Layout); // Difficulties
    VLayout->addSpacing(0);
    VLayout->addLayout(H1Layout); //Horizontal Line
    VLayout->addSpacing(0);
    VLayout->addLayout(H0Layout); //Start Game
    VLayout->addStretch();

///////////////////////////////////////////////////////////////////////////////////////

    start_up_w->setLayout(VLayout);
    start_up_w->setStyleSheet("background-color: rgb(118,178,78);");
    start_up_w->show();
    setCentralWidget(start_up_w);
    QMainWindow::setFixedSize(size_mainWindow_H, size_mainWindow_V); //Fixes size of main window
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_difficulty_slug_clicked()
{
    difficulty = 1;
    difficulty_slug->setStyleSheet("background-color: rgb(100, 100, 100);"
                                   "border:6px solid rgb(50, 50, 50);");
    difficulty_worm->setStyleSheet("background-color: rgb(100, 100, 100);");
    difficulty_python->setStyleSheet("background-color: rgb(100, 100, 100);");
}

void MainWindow::on_difficulty_worm_clicked()
{
    difficulty = 2;
    difficulty_worm->setStyleSheet("background-color: rgb(100, 100, 100);"
                                   "border:6px solid rgb(50, 50, 50);");
    difficulty_slug->setStyleSheet("background-color: rgb(100, 100, 100);");
    difficulty_python->setStyleSheet("background-color: rgb(100, 100, 100);");
}

void MainWindow::on_difficulty_python_clicked()
{
    difficulty = 3;
    difficulty_python->setStyleSheet("background-color: rgb(100, 100, 100);"
                                   "border:6px solid rgb(50, 50, 50);");
    difficulty_slug->setStyleSheet("background-color: rgb(100, 100, 100);");
    difficulty_worm->setStyleSheet("background-color: rgb(100, 100, 100);");
}

void MainWindow::on_start_game_clicked()
{
    QMainWindow::close();
    //start_up_w->hide();
}

