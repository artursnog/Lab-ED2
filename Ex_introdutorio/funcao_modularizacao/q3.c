//
// Created by Artur on 25/04/2025.
//
#include <stdio.h>

int inverte(int num) {
    int inverso = 0;
    int original = num;

    while (original != 0) {
        inverso = inverso * 10 + original % 10;
        original /= 10;
    }

    num = inverso;
    return num;
}

int main() {
    int num = 1234;
    printf("%d\n", inverte(num));

    int num1 = 6744;
    printf("%d\n", inverte(num1));

    return 0;
}