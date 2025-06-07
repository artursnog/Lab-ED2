#include <stdio.h>
#include <time.h>
#include <math.h>

int x(int n){

    long double sqrt5 = sqrt(5);
    long double phi = (1 + sqrt5) / 2;

    return round(pow(phi, n + 1) / sqrt5);
}

int main(){
    int n = 35;
    int N_max = 1000;
    double total_time = 0;

    for (int i = 0; i < N_max; i++){
        clock_t start = clock();
        int valor = x(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    
    printf("Valor de x(%d): %d\n", n, x(n));
    printf("Tempo médio em %.6f segundos\n", total_time / N_max);
    return 0;
}


