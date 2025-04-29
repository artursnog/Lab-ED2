//
// Created by Artur on 25/04/2025.
//
#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int x, int y) {

    for ( int i = x; i <= y; i++) {
        if (i == 0 || i == 1) {
            continue;
        }
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
            if (j == i - 1) {
                printf("%d ", i);
            }
        }
    }
    return 0;
}

int main() {
    int x, y;

    printf("Digite um intervalo de dois numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("Os numeros primos entre %d e %d sao: ", x, y);
    ehPrimo(x, y);

    return 0;
}