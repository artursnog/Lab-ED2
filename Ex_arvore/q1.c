#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

Node *criarNo(int valor){
    Node *novoNo = malloc(sizeof(Node));
    if (novoNo != NULL){
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        novoNo->valor = valor;
        return novoNo;
    }
}

void removerNo(Node *no){
    if (no != NULL){
        removerNo(no->esquerda);
        removerNo(no->direita);
        free(no);
    }
}

Node *buscarNo(int valor, Node *no){
    if (no == NULL){
        return NULL;
    }
    else if (no->valor == valor){
        return no;    
    }
    else if (valor < no->valor){
        return buscarNo(valor, no->esquerda);
    }
    else {
        return buscarNo(valor, no->direita);
    }
}

Node *inserirNo(int valor, Node *no){
    if (no == NULL){
        return criarNo(valor);
    }
    else if (valor < no->valor){
        no->esquerda = inserirNo(valor, no->esquerda);
    }
    else if (valor > no->valor){
        no->direita = inserirNo(valor, no->direita);
    }
    return no;
}

void preOrdem(Node *no){
    if (no != NULL){
        printf("%d ", no->valor);
        preOrdem(no->esquerda);
        preOrdem(no->direita);
    }
}
void inOrdem(Node *no){
    if (no != NULL){
        inOrdem(no->esquerda);
        printf("%d ", no->valor);
        inOrdem(no->direita);
    }
}
void posOrdem(Node *no){
    if (no != NULL){
        posOrdem(no->esquerda);
        posOrdem(no->direita);
        printf("%d ", no->valor);
    }
}

int altura(Node *no){
    if (no == NULL){
        return -1;
    }
    int alturaEsquerda = altura(no->esquerda);
    int alturaDireita = altura(no->direita);
    if (alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;
    }
    return alturaDireita + 1;
}

int profundidadeNo(Node *raiz, int valor, int profundidadeAtual) {
    if (raiz == NULL) {
        return -1;
    }
    if (raiz->valor == valor) {
        return profundidadeAtual;
    }

    int profundidadeEsquerda = profundidadeNo(raiz->esquerda, valor, profundidadeAtual + 1);
    if (profundidadeEsquerda != -1) {
        return profundidadeEsquerda;
    }

    return profundidadeNo(raiz->direita, valor, profundidadeAtual + 1);
}


int soma(Node *no){
    if (no == NULL){
        return 0;
    }
    return no->valor + soma(no->esquerda) + soma(no->direita);
}

int nivelNo(Node *no, int valor, int nivelAtual){
    if (no == NULL){
        return -1; 
    }
    if (no->valor == valor){
        return nivelAtual;
    }
    if (valor < no->valor){
        return nivelNo(no->esquerda, valor, nivelAtual + 1);
    }
    return nivelNo(no->direita, valor, nivelAtual + 1);
}

int nos(Node *no){
    if (no == NULL){
        return 0;
    }
    return 1 + nos(no->esquerda) + nos(no->direita);
}

int folhas(Node *no){
    if (no == NULL){
        return 0;
    }
    if (no->esquerda == NULL && no->direita == NULL){
        return 1;
    }
    return folhas(no->esquerda) + folhas(no->direita);
}

int main(){
    Node *raiz = NULL;

    raiz = inserirNo(10, raiz);
    raiz = inserirNo(5, raiz);
    raiz = inserirNo(15, raiz);
    raiz = inserirNo(3, raiz);
    raiz = inserirNo(7, raiz);
    raiz = inserirNo(12, raiz);

    Node *busca = buscarNo(10, raiz);
    if (busca != NULL){
        printf("Valor encontrado: %d\n", busca->valor);
    } else {
        printf("Valor não encontrado.\n");
    }

    printf("Árvore em pré-ordem: ");
    preOrdem(raiz);
    printf("\nÁrvore em in-ordem: ");
    inOrdem(raiz);
    printf("\nÁrvore em pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    printf("Altura da árvore: %d\n", altura(raiz));

    printf("Profundidade do nó com valor 7: %d\n", profundidadeNo(raiz, 7, 0));

    printf("Soma dos valores da árvore: %d\n", soma(raiz));

    printf("Nível do nó com valor 7: %d\n", nivelNo(raiz, 7, 0));

    printf("Número de nós na árvore: %d\n", nos(raiz));

    printf("Número de folhas na árvore: %d\n", folhas(raiz));

    removerNo(raiz);
    raiz = NULL;
    printf("Árvore removida.\n");

    printf("Novo Tamanho da árvore: %d\n", altura(raiz));
    return 0;
}

