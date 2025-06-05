#include <stdio.h>

typedef struct{
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
}Produto;

int main(){
    Produto produtos[10];
    int opcao;
    int totalProdutos = 0;
    int codigoBusca;

    while(1){
        printf("Digite o que deseja fazer:\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Buscar produtos\n");
        printf("3 - Listar produto\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:

                if(totalProdutos >= 10){
                    printf("Limite de produtos atingido!\n");
                    break;
                }
                printf("Digite o nome do produto: ");
                scanf("%s", produtos[totalProdutos].nome);
                printf("Digite o codigo do produto: ");
                scanf("%d", &produtos[totalProdutos].codigo);
                printf("Digite a quantidade do produto: ");
                scanf("%d", &produtos[totalProdutos].quantidade);
                printf("Digite o preco do produto: ");
                scanf("%f", &produtos[totalProdutos].preco);
                printf("Produto cadastrado com sucesso!\n");
                    
                totalProdutos++;
                break;
            
            case 2:
                
                printf("Busca de produtos\n");
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigoBusca);
                for(int i = 0; i < totalProdutos; i++){
                    if(produtos[i].codigo == codigoBusca){
                        printf("Produto encontrado:\n");
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Quantidade: %d\n", produtos[i].quantidade);
                        printf("Preco: %.2f\n", produtos[i].preco);
                        break;
                    }
                    else{
                        printf("Produto nao encontrado!\n");
                    }
                }
                break;
                

            case 3:
                
                printf("Lista de produtos:\n");
                for(int i = 0; i < totalProdutos; i++){
                    printf("\nProduto %d:\n", i + 1);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("Preco: %.2f\n", produtos[i].preco);
                }
                break;

            case 4:
                printf("Saindo do programa...\n");
                return 0;
            
            default:
                printf("Opcao invalida!\n");
                break;
        }
        
    }
    return 0;
}