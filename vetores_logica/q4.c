#include <stdio.h>

int main(){
    int nums[10];
    int distintos[10][2];
    int qtd_distintos = 0;

    for (int i = 0; i < 10; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < 10; i++) {
    int existe = 0;
    
        for (int j = 0; j < qtd_distintos; j++) {
            if (nums[i] == distintos[j][0]) {
                existe = 1;
                distintos[j][1] += 1;
                break;
            }
        }
        
        if (existe == 0) {
            distintos[qtd_distintos][0] = nums[i];
            distintos[qtd_distintos][1] = 1;
            qtd_distintos += 1;
        }
    }

    printf("Os numeros distintos sao: ");
    for (int i = 0; i < qtd_distintos; i++) {
        printf("%d: %d vezes \n", distintos[i][0], distintos[i][1]);
    }

    
}