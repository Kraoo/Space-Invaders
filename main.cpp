#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

const int width = 50;
const int height = 20;
int x, y;
int bulletX, bulletY;
int enemyX, enemyY;
bool gameOver;
int score;

enum Direction { STOP = 0, LEFT, RIGHT };
Direction dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height - 1;
    bulletX = -1;
    bulletY = -1;
    enemyX = rand() % width;
    enemyY = 0;
    score = 0;
}

void Draw() {
    system("clear");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                cout << "#";
            if (i == y && j == x)
                cout << "A";
            else if (i == enemyY && j == enemyX)
                cout << "E";
            else if (i == bulletY && j == bulletX)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

char GetKeyPress() {
    char key;
    struct termios oldT, newT;

    tcgetattr(STDIN_FILENO, &oldT);
    newT = oldT;
    newT.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newT);

    key = cin.get();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldT);

    return key;
}

void Input() {
    char input = GetKeyPress();

    switch (input) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case ' ':
            if (bulletY == -1) {
                bulletX = x;
                bulletY = y - 1;
            }
            break;
        case 'q':
            gameOver = true;
            break;
    }
}

void Logic() {
    switch (dir) {
        case LEFT:
            if (x > 0)
                x--;
            break;
        case RIGHT:
            if (x < width - 1)
                x++;
            break;
        default:
            break;
    }

    enemyY++;
    if (enemyY >= height) {
        enemyX = rand() % width;
        enemyY = 0;
    }

    if (bulletY != -1) {
        bulletY--;
        if (bulletY == enemyY && bulletX == enemyX) {
            score += 10;
            bulletX = -1;
            bulletY = -1;
            enemyX = rand() % width;
            enemyY = 0;
        }
        if (bulletY < 0) {
            bulletX = -1;
            bulletY = -1;
        }
    }
}

int main() {
    srand(time(NULL));
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(50000);
    }
    return 0;
}
