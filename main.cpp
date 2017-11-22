#include <stdio.h>

#define WIERSZE 9
#define KOLUMNY 9

int czytaj(char a[][KOLUMNY], int d[], int n) {
    int w = 0;
    int c;

    c = getchar();
    while (c != EOF && w < n) {
        d[w] = 0;
        while (c != '\n' && c != EOF && d[w] < KOLUMNY) {
            a[w][d[w]] = c;
            ++d[w];
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

void pisz(char a[][KOLUMNY], int d[], int n) {
    int w;

    for (w = n - 1; w >= 0; --w) {
        int k;

        for (k = KOLUMNY - 1; k >= d[w]; --k) {
            putchar(' ');
        }
        for (; k >= 0; --k) {
            putchar(a[w][k]);
        }
        putchar('\n');
    }
}

int main(void) {
    char a[WIERSZE][KOLUMNY];
    int d[WIERSZE];
    int n;

    n = czytaj(a, d, WIERSZE);
    pisz(a, d, n);
    return 0;
}