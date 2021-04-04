#include <stdio.h>
#include <stdlib.h>

//X(1..N) abcbdab
//Y(1..M) bcdb

//LCS(x, y) = LCS(x[i+1], y[i+1]) + 1, если x[i] = y[i]
//LCS(x, y) = максимальное из (LCS(x[i], y[i+1]), LCS(x[i+1], y[i])), если x[i] != y[i]
//LCS(x, y) = 0, если х = 0 или у = 0

int lcs_len(char* a, char* b) {
    if (*a == '\0' || *b == '\0')
        return 0;
    else if (*a == *b)
        return 1 + lcs_len(a + 1, b + 1);
    else {
        int x1 = lcs_len(a + 1, b);
        int x2 = lcs_len(a, b + 1);
        return (x1 > x2) ? x1 : x2;
    }
}

//S(m, n) = S(m-1, n) + S(m, n-1);
//S(m, n) = 1, если одна из координат равна нулю
//S(m, n) = 0, если m и n это стартовые координаты

int routes(int x, int y) {
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0 ^ y == 0)
        return 1;
    else
        return routes(x, y - 1) + routes(x - 1, y);
}

void searchesTest() {
    char* x = "abcbdab";
    char* y = "bcdb";
    printf("Длина наибольшей общей подпоследовательности: %d\n", lcs_len(x, y));

    const int sizeX = 5;
    const int sizeY = 5;
    for (int y = 0; y < sizeY; ++y) {
        for (int x = 0; x < sizeX; ++x) {
            printf("%5d", routes(x, y));
        }
        printf("\n");
    }
}