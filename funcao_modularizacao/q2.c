//
// Created by Artur on 25/04/2025.
//
#include <stdio.h>

int potencia(int base, int expoente) {
    int valor;
    for (int i = 0; i < expoente; i++) {
        valor *= base;
    }
    return valor;
}

int main() {
    printf("%d\n", potencia(2, 10));

    return 0;
}