#include <stdio.h>

int main(void) {
    int N, L, U, n;
    scanf("%d", &N);
    getchar();

    scanf("%d %d", &L, &U);
    getchar();

    if (L > U) {
        int temp = L;
        L = U;
        U = temp;
    }
    
    int Dados[N];
    for (n = 0; n < N; n++) {
        scanf("%d", &Dados[n]);
        getchar();
    }

    int X, Y, i;
    while (scanf("%d %d", &X, &Y) != EOF) {
        getchar();

        if (X > Y) {
            int temp = X;
            X = Y;
            Y = temp;
        }
        
        int Quantidade = 0;
        for (i = X; i <= Y; i++) {
            if (Dados[i] >= L)
                if (Dados[i] <= U)
                    Quantidade++;
        }
        printf("%d\n", Quantidade);
    }
    return 0;
}