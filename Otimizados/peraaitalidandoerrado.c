#include <stdio.h>
#include <math.h>

int main(void) {
    while (1) {
        unsigned long long int N;
        scanf("%llu", &N);
        getchar();

        if (N == 0) break;
 
        long double raiz = sqrt(N);
        unsigned long long int raiz_ = (unsigned long long int)raiz;

        if (raiz_ * raiz_ != N) printf("PERA AI... TA LIDANDO ERRADO!\n");
        else {
            unsigned long long int AN = 1 + (raiz - 1) * 2;
            printf("%llu\n", AN);
        }
    }
    return 0;
}