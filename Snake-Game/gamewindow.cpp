#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    // Set Game Variables
    multi_player = false;
    enum board_sizes{SMALL=50, MEDIUM=25, LARGE=20};
    tile_size = MEDIUM;
    enum snake_speed{SLUG=40, WORM=20, PYTHON=10}; // milliseconds
    t_interval = WORM;

    // TODO: implement the following
//    int num_fruit = 1;
//    enum fruit_type{APPLE, EGGPLANT, PEACH};
//    enum snake_color{BLUE, RED, YELLOW, ORANGE, GREEN, PURPLE};
//    enum background_color{SUMMER, NIGHT, WINTER, FALL, SPRING};


    // Board Variables
    win_width = width();
    header_height = 75;
    board_height = height()-header_height;
    score1 = 0;
    score2 = 0;
    highscore = 0;
    game_start1 = false;
    game_start2 = false;
    num_cols = (win_width-tile_size)/tile_size;
    num_rows = (board_height-tile_size)/tile_size;

    // Inital positions for apple and snakes
    apple_posx = (multi_player)?(num_cols/2)*tile_size:(3*num_cols/4)*tile_size;
    apple_posy = (num_rows/2)*tile_size+header_height;
    snake1_posX = (num_cols/4)*tile_size;
    snake1_posY = (num_rows/2)*tile_size+header_height;
    snake2_posX = (3*num_cols/4)*tile_size;
    snake2_posY = (num_rows/2)*tile_size+header_height;

    // Stores the positions of the snake's body segments
    snake1_body = { // KEY: [body segment][X/Y]
        {snake1_posX, snake1_posX}
    };
    snake2_body = {
        {snake2_posX, snake2_posX}
    };
    list_dir1 = {START};
    list_dir2 = {START};
    bounce = true;
    bounce_ctr = 0;

    // Logic timer
    logic_timer = new QTimer(this);
    connect(logic_timer, SIGNAL(timeout()), this, SLOT(logic()));
    logic_timer->start(t_interval); // in milliseconds

    // Move timer for snake 1
    move_timer1 = new QTimer(this);
    move_timer1->setInterval(7.5*(t_interval));
    connect(move_timer1,SIGNAL(timeout()), this, SLOT(stop1()));

    // Move timer for snake 2
    move_timer2 = new QTimer(this);
    move_timer2->setInterval(7.5*(t_interval));
    connect(move_timer2,SIGNAL(timeout()), this, SLOT(stop2()));
}

// Destrutor
GameWindow::~GameWindow(){
    delete ui;
}


// Stops snake 1 move timer
void GameWindow::stop1(){
    for(uint i = 1; i < list_dir1.size(); i++){
        list_dir1.pop_back();
    }
    move_timer1->stop();
}


// Stops snake 2 move timer
void GameWindow::stop2(){
    for(uint i = 1; i < list_dir2.size(); i++){
        list_dir2.pop_back();
    }
    move_timer2->stop();
}


// Creates game board, snake, and apple
void GameWindow::paintEvent(QPaintEvent *){
    // Sets the background green
    QPalette p(palette());
    p.setColor(QPalette::Window, QColor::fromRgb(87, 138, 52));
    setPalette(p);

    // Creates dark green header
    QPainter painter(this);
    painter.fillRect(0, 0, win_width, header_height, QColor::fromRgb(74, 117, 44));

    // Creates green checkerboard background
    for(int i = 1; i < num_cols; i++){
        for(int j = 1; j < num_rows; j++){
            if((i%2 == 0 && j%2 == 0) || (i%2 != 0 && j%2 != 0)){
                painter.fillRect(tile_size*i, tile_size*j+header_height, tile_size, tile_size, QColor::fromRgb(162, 209, 73));
            }else{
                painter.fillRect(tile_size*i, tile_size*j+header_height, tile_size, tile_size, QColor::fromRgb(170, 215, 81));
            }
        }
    }

    // Displays apple
    painter.setBrush(Qt::red);
    painter.drawEllipse(10, 10, 40, 40);                                // Header apple
    painter.drawEllipse(apple_posx, apple_posy, tile_size, tile_size);  // Game apple
    if(bounce){
        painter.drawEllipse(apple_posx-0.5*(tile_size*0.2), apple_posy-0.5*(tile_size*0.2), tile_size*1.2, tile_size*1.2);  // bounce apple
    }

    // Displays snake 1 with blue gradient body
    int snake1_col_r = 0, snake1_col_g = 0, snake1_col_b = 100, seg_ctr=0;
    for(uint i = 0; i < snake1_body.size(); i++){
        if(seg_ctr%5==0 && snake1_col_b < 250){
            snake1_col_b += 5;
        }else if(seg_ctr%5==0){
            snake1_col_r += 5;
            snake1_col_g += 5;
        }
        painter.fillRect(snake1_body[i][0], snake1_body[i][1], tile_size, tile_size, QColor::fromRgb(snake1_col_r, snake1_col_g, snake1_col_b));
        seg_ctr++;
    }

    // Displays snake 2 with orange gradient body
    if(multi_player){
        int snake2_col_r = 100, snake2_col_g = 0, snake2_col_b = 0;
        for(uint i = 0; i < snake2_body.size(); i++){
            if(snake2_col_r < 250){
                snake2_col_r += 5;
            }else{
                snake2_col_g += 5;
                snake2_col_b += 5;
            }
            painter.fillRect(snake2_body[i][0], snake2_body[i][1], tile_size, tile_size, QColor::fromRgb(snake2_col_r, snake2_col_g, snake2_col_b));
        }
    }
}


// Senses keys and sets direction accordingly
void GameWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        // Player 1 (WASD)
        case Qt::Key_A:
            setDirection(game_start1, move_timer1, LEFT, RIGHT, list_dir1);
            break;
        case Qt::Key_D:
            setDirection(game_start1, move_timer1, RIGHT, LEFT, list_dir1);
            break;
        case Qt::Key_W:
            setDirection(game_start1, move_timer1, UP, DOWN, list_dir1);
            break;
        case Qt::Key_S:
            setDirection(game_start1, move_timer1, DOWN, UP, list_dir1);
            break;

        // Player 2 (arrow keys)
        case Qt::Key_Left:
            setDirection(game_start2, move_timer2, LEFT, RIGHT, list_dir2);
            break;
        case Qt::Key_Right:
            setDirection(game_start2, move_timer2, RIGHT, LEFT, list_dir2);
            break;
        case Qt::Key_Up:
            setDirection(game_start2, move_timer2, UP, DOWN, list_dir2);
            break;
        case Qt::Key_Down:
            setDirection(game_start2, move_timer2, DOWN, UP, list_dir2);
            break;

        // Pause game
        case Qt::Key_P:
            list_dir1={START};
            list_dir2={START};
            game_start1 = false;
            game_start2 = false;
    }
}


void GameWindow::setDirection(bool &game_start, QTimer *move_timer, eDirections dir, eDirections opp_dir, std::vector<eDirections> &list_dir){
    game_start = true;
    move_timer->start();
    if(list_dir.back() != opp_dir){
        list_dir.push_back(dir);
    }
}


// Game logic
void GameWindow::logic(){
    // Bounces the apple every 0.5 seconds
    (bounce_ctr==(500/t_interval))?(bounce_ctr=0,bounce = !bounce):bounce_ctr++;

    // Set the coordinates of each section of the body
    std::vector<int> snake1_prev_pos = snake1_body[0];
    if(game_start1){
        setCoordinate(snake1_prev_pos, snake1_body, snake1_posX, snake1_posY);
    }
    std::vector<int> snake2_prev_pos = snake2_body[0];
    if(game_start2){
        setCoordinate(snake2_prev_pos, snake2_body, snake2_posX, snake2_posY);
    }

    // Changes snake position according to user-specified direction
    switchDirection(list_dir1, snake1_posX, snake1_posY);
    switchDirection(list_dir2, snake2_posX, snake2_posY);

    // Losing conditions for snake 1
    if(game_start1){
        // Checks if snake 1 head hits its tail
        for (uint i = 0; i < snake1_body.size(); i++){
            if (snake1_body[i][0] == snake1_posX && snake1_body[i][1] == snake1_posY){
                if(!multi_player){
                    gameOverMessage("You hit your tail! ", game_start1);
                }else{
                    gameOverMessage("Snake 1 hit your tail. Snake 2 wins! ", game_start1);
                }
            }

        }

        // Checks if snake 1 hits the wall
        if ((snake1_posX >= tile_size*num_cols ||            // Right wall
        snake1_posX <= 0) ||                                 // Left wall
        (snake1_posY >= tile_size*num_rows+header_height ||  // Floor
        snake1_posY <= header_height)){                      // Ceiling
            game_start1=false;
            if(!multi_player){
                gameOverMessage("You hit the wall! ", game_start1);
            }else{
                gameOverMessage("Snake 1 hit the wall. Snake 2 wins! ", game_start1);
            }

        }

        // Checks if snake 1 head hits snake 2 body
        if(multi_player){
            for (uint i = 0; i < snake2_body.size(); i++){
                if (snake1_posX == snake2_body[i][0] && snake1_posY == snake2_body[i][1]){
                    gameOverMessage("Snake 1 hit Snake 2. Snake 2 wins! ", game_start1);
                }
            }
        }

    }

    // Losing conditions for snake 2
    if(game_start2 && multi_player){
        // Checks if snake 2 head hits its tail
        for (uint i = 0; i < snake2_body.size(); i++){
            if (snake2_body[i][0] == snake2_posX && snake2_body[i][1] == snake2_posY){
                gameOverMessage("Snake 2 hit your tail. Snake 1 wins! ", game_start2);
            }
        }

        // Checks if snake 2 hits the wall
        if ((snake2_posX >= tile_size*num_cols ||            // Right wall
        snake2_posX <= 0) ||                                 // Left wall
        (snake2_posY >= tile_size*num_rows+header_height ||  // Floor
        snake2_posY <= header_height)){                      // Ceiling
            gameOverMessage("Snake 2 hit the wall. Snake 1 wins! ", game_start2);
        }

        // Checks if snake 2 head hits snake 1 body
        for (uint i = 0; i < snake1_body.size(); i++){
            if (snake2_posX == snake1_body[i][0] && snake2_posY == snake1_body[i][1]){
                gameOverMessage("Snake 2 hit Snake 1. Snake 1 wins! ", game_start2);
            }
        }
    }

    // Checks if snake 1 eats an apple
    if(snake1_body[0][0] == apple_posx && snake1_body[0][1] == apple_posy){
        eatApple(snake1_body, snake1_prev_pos);

        // Changes score
        score1++;
        ui->lcdNumber->display(score1);
        if(!multi_player){
            if(score1 > highscore){
                highscore = score1;
                ui->lcdNumber_2->display(highscore);
            }
        }
    }

    // Checks if snake 2 eats an apple
    if(multi_player && snake2_body[0][0] == apple_posx && snake2_body[0][1] == apple_posy){
        eatApple(snake2_body, snake2_prev_pos);

        // Changes score
        score2++;
        ui->lcdNumber_2->display(score2);
    }

    update();
}


void GameWindow::eatApple(std::vector<std::vector<int>> &body, std::vector<int> prev_pos){
    bool collision_flag;
    // Moves apple to random position not on snake body
    do{
        collision_flag = false;
        apple_posx = round((rand()%(tile_size*(num_cols-2))+tile_size)/float(tile_size))*tile_size;
        apple_posy = round((rand()%(tile_size*(num_rows-2))+tile_size)/float(tile_size))*tile_size+header_height;
        for(uint i = 0; i < snake1_body.size(); i++){
            if(snake1_body[i][0] == apple_posx && snake1_body[i][1] == apple_posy){
                collision_flag=true;
            }
        }
        for(uint j = 0; j < snake2_body.size(); j++){
            if(snake2_body[j][0] == apple_posx && snake2_body[j][1] == apple_posy){
                collision_flag=true;
            }
        }
    }while(collision_flag);

    // Adds 5 segments to the snake body
    for(int i=0;i<5;i++){
        body.push_back(prev_pos);
    }
}


void GameWindow::gameOverMessage(QString message, bool &game_start){
    game_start = false;
    QMessageBox msgbox(QMessageBox::NoIcon, "Game Over", message + "Do you want to play again? ");
    msgbox.setStandardButtons(QMessageBox::Yes);
    msgbox.addButton(QMessageBox::No);
    if(msgbox.exec() == QMessageBox::Yes){
        reset();
    }else{
        close();
    }
}


void GameWindow::setCoordinate(std::vector<int> &prev_pos, std::vector<std::vector<int>>&body, int posX, int posY){
    std::vector<int> prev_pos2;
    body[0][0] = posX;
    body[0][1] = posY;
    for (uint i = 1; i < body.size(); i++){
        prev_pos2 = body[i];
        body[i] = prev_pos;
        prev_pos = prev_pos2;
    }
}


void GameWindow::setPosition(std::vector<eDirections> &list_dir, bool turn_good){
    if(turn_good && list_dir.size()>1){
        list_dir.erase(list_dir.begin());
    }
}


void GameWindow::switchDirection(std::vector<eDirections> &list_dir, int &snake_posX, int &snake_posY){
    eDirections current_dir=list_dir[0];
    bool turn_good=false;

    if(list_dir.size()>1){
        switch (list_dir[1]){
            case LEFT:
                if((snake_posY-header_height)%tile_size == 0){
                    current_dir=list_dir[1];
                    turn_good = true;
                }
                break;
            case RIGHT:
                if((snake_posY-header_height)%tile_size == 0){
                    current_dir=list_dir[1];
                    turn_good = true;
                }
                break;
            case UP:
                if(snake_posX%tile_size == 0){
                    current_dir=list_dir[1];
                    turn_good = true;
                }
                break;
            case DOWN:
                if(snake_posX%tile_size == 0){
                    current_dir=list_dir[1];
                    turn_good = true;
                }
                break;
            case START:
                // At start, snake doesn't move until button is pressed
                break;
        }
    }

    switch (dir){
        case LEFT:
            snake_posX -= 5;
            break;
        case RIGHT:
            snake_posX += tile_size/5;
            setPosition(list_dir, turn_good);
            break;
        case UP:
            snake_posY -= tile_size/5;
            setPosition(list_dir, turn_good);
            break;
        case DOWN:
            snake_posY += tile_size/5;
            setPosition(list_dir, turn_good);
            break;
        case START:
            // At start, snake doesn't move until button is pressed
    }
}


// Resets the game
void GameWindow::reset(){
    // Sets snake and apple to initial positions
    apple_posx = (multi_player)?(num_cols/2)*tile_size:(3*num_cols/4)*tile_size;
    apple_posy = (num_rows/2)*tile_size+header_height;
    snake1_posX = (num_cols/4)*tile_size;
    snake1_posY = (num_rows/2)*tile_size+header_height;
    snake2_posX = (3*num_cols/4)*tile_size;
    snake2_posY = (num_rows/2)*tile_size+header_height;

    // Sets snake to only have its head
    snake1_body.clear();
    snake1_body = {{snake1_posX, snake1_posY}};
    snake2_body.clear();
    snake2_body = {{snake2_posX, snake2_posY}};

    // Set score back to 0
    score1 = 0;
    score2 = 0;
    ui->lcdNumber->display(score1);
    if(multi_player){
        ui->lcdNumber_2->display(score2);
    }

    game_start1=false;
    game_start2=false;
    list_dir1={START};
    list_dir2={START};
    update();
}
