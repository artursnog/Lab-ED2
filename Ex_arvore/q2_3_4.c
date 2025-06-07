#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno *esquerda;
    struct Aluno *direita;
} Aluno;

Aluno *criarAluno(char *nome, int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo != NULL) {
        strncpy(novo->nome, nome, 49);
        novo->nome[49] = '\0';
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

Aluno *inserirAluno(Aluno *raiz, char *nome, int matricula, float nota) {
    if (raiz == NULL) {
        return criarAluno(nome, matricula, nota);
    }
    int cmp = strcmp(nome, raiz->nome);
    if (cmp < 0) {
        raiz->esquerda = inserirAluno(raiz->esquerda, nome, matricula, nota);
    } else if (cmp > 0) {
        raiz->direita = inserirAluno(raiz->direita, nome, matricula, nota);
    }
    return raiz;
}

Aluno *buscarAlunoPorNome(Aluno *raiz, char *nome) {
    if (raiz == NULL) return NULL;
    int cmp = strcmp(nome, raiz->nome);
    if (cmp == 0) return raiz;
    if (cmp < 0) return buscarAlunoPorNome(raiz->esquerda, nome);
    return buscarAlunoPorNome(raiz->direita, nome);
}

void liberarArvore(Aluno *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void calcularMediaNotas(Aluno *raiz, float *soma, int *qtd) {
    if (raiz != NULL) {
        *soma += raiz->nota;
        (*qtd)++;
        calcularMediaNotas(raiz->esquerda, soma, qtd);
        calcularMediaNotas(raiz->direita, soma, qtd);
    }

}

int main() {
    Aluno *raiz = NULL;
    raiz = inserirAluno(raiz, "Alice", 123, 8.5);
    raiz = inserirAluno(raiz, "Bob", 456, 7.0);
    raiz = inserirAluno(raiz, "Charlie", 789, 9.0);

    char nomeBusca[50];
    printf("Digite o nome do aluno a buscar: ");
    scanf("%s", nomeBusca);
    
    Aluno *alunoEncontrado = buscarAlunoPorNome(raiz, nomeBusca);
    if (alunoEncontrado != NULL) {
        printf("Aluno encontrado: %s, Matricula: %d, Nota: %.2f\n",
               alunoEncontrado->nome, alunoEncontrado->matricula, alunoEncontrado->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }

    float somaNotas = 0;
    int quantidadeAlunos = 0;
    calcularMediaNotas(raiz, &somaNotas, &quantidadeAlunos);
    
    if (quantidadeAlunos > 0) {
        printf("Média das notas: %.2f\n", somaNotas / quantidadeAlunos);
    } else {
        printf("Nenhum aluno cadastrado.\n");
    }

    liberarArvore(raiz);
    return 0;
}

