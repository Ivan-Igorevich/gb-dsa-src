#include "../geek.h"

const int WIDTH = 10;
const int HEIGHT = 8;
const int OBSTACLE = -1;
const int BLANK = -2;

int pointX[HEIGHT * WIDTH];
int pointY[HEIGHT * WIDTH];

int len;

int lee(int** grid, int sx, int sy, int ex, int ey) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int x;
    int y;
    int vector;
    int distance = 0;
    int stop;

    if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE)
        return 0;

    grid[sy][sx] = 0;
    do {
        stop = true;
        for (y = 0; y < HEIGHT; ++y) {
            for (x = 0; x < WIDTH; ++x) {
                if (grid[y][x] == distance) {
                    for (vector = 0; vector < 4; ++vector) {
                        int nextX = x + dx[vector];
                        int nextY = y + dy[vector];
                        if (nextX >= 0 && nextX < WIDTH &&
                            nextY >= 0 && nextY < HEIGHT &&
                            grid[nextY][nextX] == BLANK) {
                            stop = false;
                            grid[nextY][nextX] = distance + 1;
                        }
                    }
                }
            }
        }
        distance++;
    } while (!stop && grid[ey][ex] == BLANK);

    if (grid[ey][ex] == BLANK) return 0;

    len = grid[ey][ex];
    x = ex;
    y = ey;
    while (distance > 0) {
        pointX[distance] = x;
        pointY[distance] = y;
        distance--;
        for (vector = 0; vector < 4; ++vector) {
            int nextX = x + dx[vector];
            int nextY = y + dy[vector];
            if (nextX >= 0 && nextX < WIDTH &&
                nextY >= 0 && nextY < HEIGHT &&
                grid[nextY][nextX] == distance) {
                x = nextX;
                y = nextY;
            }
        }
    }
    return len;
}

void waveLeeTest() {
    int** matrix = init2dIntArray(matrix, HEIGHT, WIDTH);
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            set2dInt(matrix, i, j, BLANK);

    set2dInt(matrix, 4, 3, OBSTACLE);
    set2dInt(matrix, 4, 4, OBSTACLE);
    set2dInt(matrix, 4, 5, OBSTACLE);
    set2dInt(matrix, 4, 6, OBSTACLE);

    print2dIntArray(matrix, HEIGHT, WIDTH, 3);
    printf("\n");

    int length = lee(matrix, 2, 2, 7, 5);
    print2dIntArray(matrix, HEIGHT, WIDTH, 3);
    printf("\n");
    printIntArray(pointX, length, 0);
    printIntArray(pointY, length, 0);
}
