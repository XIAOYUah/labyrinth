#include <stdio.h>
#define WIDTH 12
#define HEIGHT 10

char maze[HEIGHT][WIDTH] = {
    "############",
    "#S#        #",
    "# ######## #",
    "# #        #",
    "# ##########",
    "#          #",
    "##### ######",
    "#          #",
    "# ######## #",
    "#E#        #"
};

int playerX = 1;
int playerY = 1;

void displayMaze() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (y == playerY && x == playerX) {
                putchar('P'); // 用P表示玩家的位置
            } else {
                putchar(maze[y][x]);
            }
        }
        putchar('\n');
    }
}

void movePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;

    switch(direction) {
        case 'w': // 上
            newY--;
            break;
        case 's': // 下
            newY++;
            break;
        case 'a': // 左
            newX--;
            break;
        case 'd': // 右
            newX++;
            break;
    }

    // 检查新位置是否可以移动
    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newY][newX] != '#') {
        playerX = newX;
        playerY = newY;
    }
}

int checkWin() {
    return maze[playerY][playerX] == 'E';
}

int main() {
    char input;
    while (1) {
        displayMaze();
        input = getchar();
        movePlayer(input);
        if (checkWin()) {
            displayMaze();
            putchar('\n');
            putchar('Y'); putchar('O'); putchar('U'); putchar(' '); putchar('W'); putchar('I'); putchar('N'); 
            putchar('!'); putchar('\n');
            break;
        }
    }
    return 0;
}
