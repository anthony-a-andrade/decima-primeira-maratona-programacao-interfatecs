#include <stdio.h>

int main(void) {
    while (1) {
        unsigned long long int N, K;
        scanf("%llu %llu", &N, &K);
        getchar();

        if (N + K == 0) break;

        unsigned long long int total = N, bitucas = N;

        while (bitucas >= K) {
            unsigned long long int temp = bitucas / K;
            unsigned long long int resto = bitucas % K;
            total += temp;
            bitucas = temp + resto;
        }

        printf("%llu\n", total);
    }
    return 0;
}