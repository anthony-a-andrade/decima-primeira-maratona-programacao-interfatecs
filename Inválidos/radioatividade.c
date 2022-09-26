#include <stdio.h>
#include <math.h>

int main(void) {
    double ln2 = M_LN2, e = M_E, No, N, t_half;
    scanf("%lf", &No); 
    getchar();
    
    scanf("%lf", &N); 
    getchar();
    
    scanf("%lf", &t_half); 
    getchar();

    long double Y = ln2 / t_half;
    long double x = log(N / No) / log(e);
    long double t = x / Y;

    printf("%llu\n", (unsigned long long int)-t);
    return 0;
}