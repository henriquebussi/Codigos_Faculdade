#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int matricula;
    char nome[50];
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int matricula, const char *nome) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo->matricula = matricula;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int matricula, const char *nome) {
    if (raiz == NULL) {
        return criarNo(matricula, nome);
    }

    if (matricula < raiz->matricula) {
        raiz->esq = inserir(raiz->esq, matricula, nome);
    } else if (matricula > raiz->matricula) {
        raiz->dir = inserir(raiz->dir, matricula, nome);
    } else {
        printf("Erro: Matricula %d ja cadastrada!\n", matricula);
    }

    return raiz;
}

No* buscar(No *raiz, int matricula) {
    if (raiz == NULL || raiz->matricula == matricula) {
        return raiz;
    }

    if (matricula < raiz->matricula) {
        return buscar(raiz->esq, matricula);
    } else {
        return buscar(raiz->dir, matricula);
    }
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("Matricula: %d | Nome: %s\n", raiz->matricula, raiz->nome);
        emOrdem(raiz->dir);
    }
}

void preOrdem(No *raiz) { 
    if (raiz != NULL) {
        printf("Matricula: %d | Nome: %s\n", raiz->matricula, raiz->nome);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(No *raiz) { 
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("Matricula: %d | Nome: %s\n", raiz->matricula, raiz->nome);
    }
}

int contarNos(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

int contarFolhas(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

int altura(No *raiz) { 
    if (raiz == NULL) {
        return 0;
    }
    int altEsq = altura(raiz->esq);
    int altDir = altura(raiz->dir);
    
    return 1 + (altEsq > altDir ? altEsq : altDir);
}

No* menorNo(No *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    No *atual = raiz;
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

No* maiorNo(No *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    No *atual = raiz;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

void liberar(No *raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main(void) {
    No *raiz = NULL;
    int opcao, matricula;
    char nome[50];

    do {
        printf("\n===== CADASTRO DE ALUNOS (ABB) =====\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Buscar aluno\n");
        printf("3 - Listar (em ordem)\n");
        printf("4 - Mostrar pre-ordem e pos-ordem\n");
        printf("5 - Estatisticas (nos, folhas, altura)\n");
        printf("6 - Menor e maior matricula\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Matricula: ");
                scanf("%d", &matricula);
                printf("Nome: ");
                scanf(" %49[^\n]", nome);
                raiz = inserir(raiz, matricula, nome);
                break;
            case 2:
                printf("Digite a matricula para buscar: ");
                scanf("%d", &matricula);
                {
                    No *encontrado = buscar(raiz, matricula);
                    if (encontrado != NULL) {
                        printf("Aluno encontrado -> Matricula: %d | Nome: %s\n", encontrado->matricula, encontrado->nome);
                    } else {
                        printf("Aluno com matricula %d nao encontrado.\n", matricula);
                    }
                }
                break;
            case 3:
                if (raiz == NULL) {
                    printf("Arvore vazia!\n");
                } else {
                    printf("\n--- Listagem Em Ordem ---\n");
                    emOrdem(raiz);
                }
                break;
            case 4:
                if (raiz == NULL) {
                    printf("Arvore vazia!\n");
                } else {
                    printf("\n--- Pre-Ordem ---\n");
                    preOrdem(raiz);
                    printf("\n--- Pos-Ordem ---\n");
                    posOrdem(raiz);
                }
                break;
            case 5:
                printf("\n--- Estatisticas da Arvore ---\n");
                printf("Total de nos: %d\n", contarNos(raiz));
                printf("Total de folhas: %d\n", contarFolhas(raiz));
                printf("Altura da arvore: %d\n", altura(raiz));
                break;
            case 6:
                if (raiz == NULL) {
                    printf("Arvore vazia!\n");
                } else {
                    No *menor = menorNo(raiz);
                    No *maior = maiorNo(raiz);
                    printf("Menor matricula: %d (%s)\n", menor->matricula, menor->nome);
                    printf("Maior matricula: %d (%s)\n", maior->matricula, maior->nome);
                }
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    liberar(raiz);
    return 0;
}