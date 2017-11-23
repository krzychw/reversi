#include <stdio.h>
#include <cstdlib>

#define WIERSZE 8
#define KOLUMNY 8

int generujPlansze(char plansza[WIERSZE][KOLUMNY], int wiersz[]) {
    int w = 0;
    while (w < 8) {
        wiersz[w] = 0;
        while (wiersz[w] < 8) {
            plansza[w][wiersz[w]] = '-';
            ++wiersz[w];
        }
        ++w;
    }
    plansza[3][3] = 'B';
    plansza[3][4] = 'C';
    plansza[4][4] = 'B';
    plansza[4][3] = 'C';
    return w;
}

int wczytajRuch(char ruch[][2], int wiersz[]) {
    int w = 0;
    int c;

    c = getchar();
    while (c != EOF && w < 1) {
        wiersz[w] = 0;
        while (c != '\n' && c != EOF && wiersz[w] < 2) {
            ruch[w][wiersz[w]] = c;
            ++wiersz[w];
            c = getchar();
        }
        while (c != '\n' && c != EOF) {
            c = getchar();
        }
        if (c != EOF) {
            c = getchar();
        }
        ++w;
    }
    return w;
}

int convertXToInt(char character) {
    char str[2] = { character };
    return strtol( str, NULL, 36 ) - 10;
}

int convertYToInt(char character) {
    char str[2] = { character };
    return strtol( str, NULL, 36 ) - 1;
}

void interpretujRuch(char plansza[][8], char ruch[1][2], char kolor) {
    int ruchX = convertXToInt(ruch[0][0]);
    int ruchY = convertYToInt(ruch[0][1]);
    plansza[ruchY][ruchX] = kolor;
}

void piszPlansze(char plansza[][8], int d[], int n) {
    int w;

    for (w = 0; w < n; ++w) {
        int k;

        for (k = 0; k < KOLUMNY; ++k) {
            putchar(plansza[w][k]);
        }
        putchar('\n');
    }
}

int main(void) {
    char plansza[8][8];
    int wiersz[8];
    int n;

    n = generujPlansze(plansza, wiersz);
    printf("plansza wczytana");
    putchar('\n');
    printf("wczytaj ruch");
    putchar('\n');

    char ruch[1][2];
    int c[1];
    wczytajRuch(ruch, c);
    interpretujRuch(plansza,ruch,'C');
    piszPlansze(plansza, wiersz, n);

    return 0;
}