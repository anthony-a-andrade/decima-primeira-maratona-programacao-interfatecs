#include <stdio.h>
#include <math.h>

int main(void) {
    int t = 1;

    while (1) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        getchar();

        if (A == 0 && B == 0 && C == 0) break;

        printf("Triangle #%d\n", t);
        t++;

        char chr;
        double raiz;

        if (A == -1) {
            chr = 'a';
            raiz = (C * C) - (B * B);
        }
        else if (B == -1) {
            chr = 'b';
            raiz = (C * C) - (A * A);
        }
        else {
            chr = 'c';
            raiz = (A * A) + (B * B);
        }

        if (raiz < 0) printf("Impossible.\n");
        else printf("%c = %.3f\n", chr, sqrt(raiz));
    }
    return 0;
}
