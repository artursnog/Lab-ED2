#include <stdio.h>
#include <string.h>

int main(){
    char palavra[50];
    printf("Digite uma palavra para ver se é palindromo: ");
    scanf("%s", &palavra);
    for(int i = 0, j = strlen(palavra) - 1; i < j; i++, j--){
        if(palavra[i] != palavra[j]){
            printf("A palavra %s nao e palindromo\n", palavra);
            return 0;
        }
    }
    printf("A palavra %s e palindromo\n", palavra);
    return 0;
}