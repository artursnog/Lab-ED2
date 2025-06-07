#include <stdio.h>
#include <time.h>

int vetor[1000] = {0};

int x(int n) {
    if (n <= 1) {
        return 1;
    }
    if (vetor[n] != 0) {
        return vetor[n];
    }
    vetor[n] = x(n - 1) + x(n - 2);
    return vetor[n];
}

int main() {
    int n = 10;
    int N_max = 1000;
    double total_time = 0;

    for (int i = 0; i < N_max; i++) {
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    
    printf("Tempo médio em %.6f segundos\n", total_time / N_max);
    return 0;
}
