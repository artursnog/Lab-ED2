#include <stdio.h>
#include <string.h>


typedef struct{
    char nome[50];
    int numero;
}Contato;

int main(){
    Contato contatos[10];
    int opcao;
    int totalContatos = 0;
    char nomeBusca[50];

    while(1){
        printf("Digite o que deseja fazer:\n");
        printf("1 - Cadastrar contato\n");
        printf("2 - Buscar contato\n");
        printf("3 - Listar contatos\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if(totalContatos >= 10){
                    printf("Limite de contatos atingido!\n");
                    break;
                }
                printf("Digite o nome do contato: ");
                scanf("%s", contatos[totalContatos].nome);
                printf("Digite o numero do contato: ");
                scanf("%d", &contatos[totalContatos].numero);
                printf("Contato cadastrado com sucesso!\n");
                totalContatos++;
                break;
            case 2:
                printf("Busca de contatos\n");
                printf("Digite o nome do contato: ");
                scanf("%s", nomeBusca);
                for(int i = 0; i < totalContatos; i++){
                    if(strcmp(contatos[i].nome, nomeBusca) == 0){
                        printf("Contato encontrado:\n");
                        printf("Nome: %s\n", contatos[i].nome);
                        printf("Numero: %d\n", contatos[i].numero);
                        break;
                    }
                    else{
                        printf("Contato nao encontrado!\n");
                    }
                }
                
                break;

            case 3:
                printf("Lista de contatos:\n");
                for(int i = 0; i < totalContatos; i++){
                    printf("\nNome: %s\n", contatos[i].nome);
                    printf("Numero: %d\n", contatos[i].numero);
                }
                break;
            
            case 4:
                printf("Saindo...\n");
                return 0;
            
            default:
                printf("Opcao invalida!\n");
                break;
        }

    }
    return 0;
}