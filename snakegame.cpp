#include<iostream>
#include <cstdlib>   // for rand()
#include <fstream>   // for file handling
#include <conio.h>   // for _kbhit() and _getch()
#include <windows.h> // for Sleep() and system("cls")

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 17;

class Food {
public:
    int x, y;
    Food() { generate(); }
    void generate() {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
    }
};

class Snake {
public:
    int x, y, tailX[100], tailY[100], nTail;
    enum Direction {STOP=0, LEFT, RIGHT, UP, DOWN };
    Direction dir;

    Snake() : x(WIDTH / 2), y(HEIGHT / 2), nTail(2), dir(RIGHT) { // Set initial direction to RIGHT
        for(int i = 0; i < nTail; i++) {
            tailX[i] = x - (i + 1);
            tailY[i] = y;
        }
    }
    void move() {
        int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default:    break;
        }
    }
};

class Grid {
public:
    bool gameOver;
    int score, highScore;
    Snake snake;
    Food food;

    Grid() : gameOver(false), score(0) { loadHighScore(); }

    void loadHighScore() {
        ifstream file("highscore.txt");
        if (file.is_open()) {
            file >> highScore;
            file.close();
        } else {
            highScore = 0;
        }
    }

    void saveHighScore() {
        if (score > highScore) {
            highScore = score;
            ofstream file("highscore.txt");
            file << highScore;
            file.close();
        }
    }

    void draw() {
        system("cls");  // Clear the screen (Windows-specific)
        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;

        for (int i = 0; i < HEIGHT; i++) {
            cout<<"#";
            for (int j = 0; j < WIDTH; j++) {
                
                if (i == snake.y && j == snake.x){
                    if(snake.dir==snake.LEFT){
                         cout<<"<";
                    }
                    else if(snake.dir==snake.RIGHT){
                         cout<<">";
                    }
                    else if(snake.dir==snake.UP){
                         cout<<"^";
                    }
                    else if(snake.dir==snake.DOWN){
                         cout<<"V";
                    }
                }
                    
                else if (i == food.y && j == food.x)
                    cout << "F";
                else {
                    bool print = false;
                    for (int k = 0; k < snake.nTail; k++) {
                        if (snake.tailX[k] == j && snake.tailY[k] == i) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }
                
            }
            cout<<"#";
            cout << endl;
        }

        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << "\nScore: " << score << "  |  High Score: " << highScore << endl;
    }

    void input() {
       if(_kbhit()) {
            switch (_getch()) {
            case 'd':   snake.dir = Snake::RIGHT; break;
            case 'w':   snake.dir = Snake::UP; break;
            case 'a':   snake.dir = Snake::LEFT; break;
            case 's':   snake.dir = Snake::DOWN; break;
            case 'x':   gameOver = true; break;
            }
        }
    }

    void logic() {
        snake.move();
        if (snake.x < 0 || snake.x >= WIDTH || snake.y < 0 || snake.y >= HEIGHT)
            gameOver = true;
        for (int i = 0; i < snake.nTail; i++)
            if (snake.tailX[i] == snake.x && snake.tailY[i] == snake.y)
                gameOver = true;
        if (snake.x == food.x && snake.y == food.y) {
            score += 10;
            food.generate();
            snake.nTail++;
        }
    }
};

int main() {
    restart:
    char response;
    Grid game;
    while (!game.gameOver) {
        game.draw();
        game.input();
        game.logic();
        Sleep(200); // Sleep for 100 milliseconds to control game speed (Windows-specific)
    }
    game.saveHighScore();
    system("cls");
    cout << "\n\n===== GAME OVER =====\n";
    
    cout << "Final Score: " << game.score << "\n";
    cout << "Highest Score: " << game.highScore << "\n";
    cout << "Thanks for playing!\n\n";
    cout << "Do you want to restart? Press \"r\" to do so else press any other key....\n\n";
    cin>>response;
    if(response=='r'){
        goto restart;
    }else {
        ofstream file("highscore.txt");
     
          game.highScore=0;
            file << game.highScore;
            file.close();
    
            
    return 0;
    }
}     
