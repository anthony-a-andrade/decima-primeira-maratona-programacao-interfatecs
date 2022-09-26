#include <stdio.h>
#include <string.h>

int indexOf(char arr[], char chr) {
    int size = strlen(arr), i;
    for (i = 0; i < size; i++) if (arr[i] == chr) return i;
    return -1;
}

int main(void) {
    char alfa[] = "-abcdefghijklmnopqrstuvwxyz.";

    while (1) {
        int K;
        scanf(" %d", &K);
        
        if (K == 0) break;

        char cifra[71];
        scanf(" %s", &cifra);
        getchar();

        int N = strlen(cifra), n;
        int indexes_codigo[N];
        for (n = 0; n < N; n++) {
            int index_cifra = indexOf(alfa, cifra[n]);
            int ki_n = (K * n) % N;
            
            indexes_codigo[ki_n] = (index_cifra + n) % 28;
        }

        for (n = 0; n < N; n++) printf("%c", alfa[indexes_codigo[n]]);
        
        printf("\n");
    }
    return 0;
}