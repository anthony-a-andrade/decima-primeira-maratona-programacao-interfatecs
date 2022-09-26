#include <stdio.h>

int main(void) {
    while (1) {
        int N, K, n;
        scanf("%d %d", &K, &N);
        getchar();

        if (N + K == 0) break;

        int esperando = 0;
        for (n = 0; n < N; n++) {
            int carro;
            scanf(" %d", &carro);
            getchar();

            esperando += carro;
            esperando -= K;
            if (esperando < 0) esperando = 0;
        }

        printf("%d\n", esperando);
    }
    return 0;
}
