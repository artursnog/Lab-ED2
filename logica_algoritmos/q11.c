#include <stdio.h>

int buscaBinaria(int *v, int n, int x){
    int esquerda = 0;
    int direita = n - 1;
    while (esquerda <= direita){
        int meio = (direita+esquerda)/2;
        if(v[meio] == x){
            return meio;
        }
        else if (v[meio] < x){
            esquerda = meio + 1;
        }
        else{
            esquerda = meio - 1;
        }
        
    }
    return -1;
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 9;
    int result = buscaBinaria(v, n, x);
    if (result != -1){
        printf("Elemento encontrado na posicao: %d\n", result+1);
    } else {
        printf("Elemento nao encontrado\n");
    }
    return 0;
}