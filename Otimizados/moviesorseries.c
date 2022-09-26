#include <stdio.h>

int main(void) {
    int ian = 29, hellen = 26;

    while (1) {
        int A, B;
        scanf("%d", &A);
        getchar();

        if (A == 0) break;
        else if (A == 98) {
            ian++;
            printf("IAN BIRTHDAY, GO OUT FOR DINNER\n");
            continue;
        }
        else if (A == 99) {
            hellen++;
            printf("HELLEN BIRTHDAY, GO OUT FOR DANCING\n");
            continue;
        }

        scanf("%d", &B);
        getchar();

        int soma = A + B + ian + hellen;
        if (soma % 2 == 0) printf("WATCH SERIES\n");
        else printf("WATCH MOVIE\n");
    }
    return 0;
}