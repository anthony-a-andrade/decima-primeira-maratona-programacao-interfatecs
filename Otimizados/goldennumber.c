#include <stdio.h>
#include <math.h>

float golden(double atual, int de, int ate) {
    if (de + 1 == ate) return 2;
    return 1 + pow(golden(atual, de + 1, ate), -1); 
}

int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    printf("%.15f\n", golden(1, 0, N));
    return 0;
}