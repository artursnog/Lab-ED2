#include <stdio.h>
#include <time.h>

int x(int n) {
    if (n <= 1) {
        return 1;
    }
    return x(n - 1) + x(n - 2);
}

int main(){
    int n = 20;
    int N_max = 1000;
    double total_time = 0;

    for (int i = 0; i < N_max; i++){
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    
    printf("Tempo médio em %.6f segundos\n", total_time / N_max);
    return 0;
}

/*n = 36, valor medio 0.097567 segundos.
n = 35, valor medio 0.060314 segundos.
n = 34, valor medio 0.037596 segundos.
n = 30, valor medio 0.005467 segundos.
n = 20, valor medio 0.000055 segundos.
n = 10, valor medio 0.000001 segundos.

Podemos reparar que para valores pequenos a
função age rapido, porém com o aumento
de processos pela repetição recorrente
de calculos ja feitos ele aumenta
cada vez mais o tempo.
O tempo ir aumentando dessa forma é
esperado já que a complexidade da 
função x é de O(2^n)*/