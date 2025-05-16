#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    float media;
}Aluno;

int main(){
    int n;
    printf("Quantos alunos deseja cadastrar? \n");
    scanf("%d", &n);

    Aluno alunos[n];
    for(int i = 0; i < n; i++){
        printf("Nome do aluno: \n");
        scanf("%s", alunos[i].nome);
        printf("Matricula do aluno: \n");
        scanf("%d", &alunos[i].matricula);
        printf("Media do aluno: \n");
        scanf("%f", &alunos[i].media);
    }

    printf("Alunos Aprovados:\n");
    for(int i = 0; i < n; i++){
        if(alunos[i].media >= 7){
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Media: %.2f\n", alunos[i].media);
        }
    }
}
