#include <stdio.h>

int main(){
    int matriz1[3][3], matriz2[3][3], soma[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Matriz 1. Coloque o valor da linha  %d, coluna %d:", i, j);
            scanf("%d", &matriz1[i][j]);
            printf("Matriz 2. Coloque o valor da linha  %d, coluna %d:", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            soma[i][j] = matriz1[i][j]+matriz2[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", soma[i][j]);
            if (j == 2){
                printf("\n");
            }
            
        }
    }
}