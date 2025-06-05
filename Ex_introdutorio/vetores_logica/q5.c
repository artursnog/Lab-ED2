#include <stdio.h>

int main(){
    int vetor1[10], vetor2[10];

    for (int i = 0; i < 10; i++){
        printf("Insira o valor do primeiro vetor:");
        scanf("%d", &vetor1[i]);

        printf("Insira o valor do segundo vetor:");
        scanf("%d", &vetor2[i]);
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(vetor1[i] == vetor2[j]){
                printf("%d e um elemento comum\n", vetor1[i]);
                break;
            }
        }
        
    }

    
    
}