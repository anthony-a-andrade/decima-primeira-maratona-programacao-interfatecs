#include <stdio.h>

int main(void) {
    int N, n;
    scanf("%d", &N);
    getchar();

    for (n = 0; n < N; n++) {
        int A, B;
        scanf("%d %d", &A, &B);
        getchar();

        if ((A * B) % 2 == 0) printf("[:=[primeiro]\n");
        else printf("[segundo]=:]\n");
    }
    return 0;
}