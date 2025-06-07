#include <stdio.h>
#include <time.h>


int x(int n){
    int a = 1, b = 1, c;

    if (n <= 1){
        return 1;
    }

    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n = 34;
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