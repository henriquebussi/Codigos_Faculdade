#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int identificador;
    char nome[50];
    float dinheiro;
    struct No *esq;
    struct No *dir;
} No;

// --- Funções Base Fornecidas ---

No* criarNo(int identificador, const char *nome, float dinheiro) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo->identificador = identificador;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->dinheiro = dinheiro;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int identificador, const char *nome, float dinheiro) {
    if (raiz == NULL) {
        return criarNo(identificador, nome, dinheiro);
    }

    if (identificador < raiz->identificador) {
        raiz->esq = inserir(raiz->esq, identificador, nome, dinheiro);
    } else if (identificador > raiz->identificador) {
        raiz->dir = inserir(raiz->dir, identificador, nome, dinheiro);
    } else {
        printf("Erro: Conta %d ja cadastrada!\n", identificador);
    }

    return raiz;
}

// --- Funções Auxiliares de Busca ---

No* buscar(No *raiz, int identificador) {
    if (raiz == NULL || raiz->identificador == identificador) {
        return raiz;
    }
    if (identificador < raiz->identificador) {
        return buscar(raiz->esq, identificador);
    }
    return buscar(raiz->dir, identificador);
}

No* encontrarMinimo(No *raiz) {
    No *atual = raiz;
    while (atual && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

// --- Operações do Banco ---

void depositar(No *raiz, int identificador, float valor) {
    if (valor <= 0) {
        printf("Erro: O valor do deposito deve ser positivo!\n");
        return;
    }
    No *conta = buscar(raiz, identificador);
    if (conta != NULL) {
        conta->dinheiro += valor;
        printf("Deposito de R$ %.2f realizado com sucesso na conta %d!\n", valor, identificador);
    } else {
        printf("Erro: Conta %d nao encontrada!\n", identificador);
    }
}

void sacar(No *raiz, int identificador, float valor) {
    if (valor <= 0) {
        printf("Erro: O valor do saque deve ser positivo!\n");
        return;
    }
    No *conta = buscar(raiz, identificador);
    if (conta != NULL) {
        if (conta->dinheiro >= valor) {
            conta->dinheiro -= valor;
            printf("Saque de R$ %.2f realizado com sucesso na conta %d!\n", valor, identificador);
        } else {
            printf("Erro: Saldo insuficiente! Saldo atual: R$ %.2f\n", conta->dinheiro);
        }
    } else {
        printf("Erro: Conta %d nao encontrada!\n", identificador);
    }
}

void transferir(No *raiz, int idOrigem, int idDestino, float valor) {
    if (valor <= 0) {
        printf("Erro: O valor da transferencia deve ser positivo!\n");
        return;
    }
    if (idOrigem == idDestino) {
        printf("Erro: A conta de origem e destino nao podem ser iguais!\n");
        return;
    }

    No *origem = buscar(raiz, idOrigem);
    No *destino = buscar(raiz, idDestino);

    if (origem == NULL) {
        printf("Erro: Conta de origem %d nao encontrada!\n", idOrigem);
        return;
    }
    if (destino == NULL) {
        printf("Erro: Conta de destino %d nao encontrada!\n", idDestino);
        return;
    }

    if (origem->dinheiro >= valor) {
        origem->dinheiro -= valor;
        destino->dinheiro += valor;
        printf("Transferencia de R$ %.2f da conta %d para a conta %d realizada!\n", valor, idOrigem, idDestino);
    } else {
        printf("Erro: Saldo insuficiente na conta %d!\n", idOrigem);
    }
}

// Listagem em ordem crescente de ID (Percurso em-ordem)
void listarContas(No *raiz) {
    if (raiz != NULL) {
        listarContas(raiz->esq);
        printf("[%d] Titular: %-20s | Saldo: R$ %.2f\n", raiz->identificador, raiz->nome, raiz->dinheiro);
        listarContas(raiz->dir);
    }
}

// --- Estatísticas e Buscas por Saldo ---

void calcularEstatisticasRec(No *raiz, int *totalContas, float *saldoTotal) {
    if (raiz != NULL) {
        (*totalContas)++;
        *saldoTotal += raiz->dinheiro;
        calcularEstatisticasRec(raiz->esq, totalContas, saldoTotal);
        calcularEstatisticasRec(raiz->dir, totalContas, saldoTotal);
    }
}

void exibirEstatisticas(No *raiz) {
    int totalContas = 0;
    float saldoTotal = 0.0f;

    calcularEstatisticasRec(raiz, &totalContas, &saldoTotal);

    if (totalContas == 0) {
        printf("Nenhuma conta cadastrada no sistema.\n");
        return;
    }

    printf("\n=== ESTATISTICAS DO BANCO ===\n");
    printf("Total de contas: %d\n", totalContas);
    printf("Saldo total armazenado: R$ %.2f\n", saldoTotal);
    printf("Saldo medio por conta: R$ %.2f\n", saldoTotal / totalContas);
}

void buscarExtremosSaldoRec(No *raiz, No **maior, No **menor) {
    if (raiz == NULL) return;

    if (*maior == NULL || raiz->dinheiro > (*maior)->dinheiro) {
        *maior = raiz;
    }
    if (*menor == NULL || raiz->dinheiro < (*menor)->dinheiro) {
        *menor = raiz;
    }

    buscarExtremosSaldoRec(raiz->esq, maior, menor);
    buscarExtremosSaldoRec(raiz->dir, maior, menor);
}

void exibirExtremosSaldo(No *raiz) {
    if (raiz == NULL) {
        printf("Nenhuma conta cadastrada no sistema.\n");
        return;
    }

    No *maior = NULL;
    No *menor = NULL;

    buscarExtremosSaldoRec(raiz, &maior, &menor);

    printf("\n=== EXTREMOS DE SALDO ===\n");
    printf("Maior Saldo: [%d] %s - R$ %.2f\n", maior->identificador, maior->nome, maior->dinheiro);
    printf("Menor Saldo: [%d] %s - R$ %.2f\n", menor->identificador, menor->nome, menor->dinheiro);
}

// --- Remoção e Limpeza de Memória ---

No* deletarConta(No *raiz, int identificador) {
    if (raiz == NULL) {
        printf("Erro: Conta %d nao encontrada para remocao!\n", identificador);
        return NULL;
    }

    if (identificador < raiz->identificador) {
        raiz->esq = deletarConta(raiz->esq, identificador);
    } else if (identificador > raiz->identificador) {
        raiz->dir = deletarConta(raiz->dir, identificador);
    } else {
        // Caso 1: Nó sem filhos ou com 1 filho
        if (raiz->esq == NULL) {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 2: Nó com 2 filhos (obtem o sucessor em-ordem)
        No *temp = encontrarMinimo(raiz->dir);
        raiz->identificador = temp->identificador;
        strcpy(raiz->nome, temp->nome);
        raiz->dinheiro = temp->dinheiro;

        // Deleta o sucessor
        raiz->dir = deletarConta(raiz->dir, temp->identificador);
    }
    return raiz;
}

void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

// --- Limpeza de Buffer ---

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal ---

int main(void) {
    No *raiz = NULL;
    int opcao, id, idDestino;
    char nome[50];
    float valor;

    do {
        printf("\n====================================\n");
        printf("       SISTEMA BANCARIO (BST)       \n");
        printf("====================================\n");
        printf("1. Criar Conta\n");
        printf("2. Consultar Saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Transferir\n");
        printf("6. Listar Contas (Ordem Crescente)\n");
        printf("7. Exibir Estatisticas\n");
        printf("8. Buscar Maior e Menor Saldo\n");
        printf("9. Deletar Conta\n");
        printf("0. Fechar Sistema\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Insira um numero.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("ID da Conta: ");
                scanf("%d", &id);
                limparBuffer();
                printf("Nome do Titular: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o \n do final
                printf("Saldo Inicial: R$ ");
                scanf("%f", &valor);
                limparBuffer();

                if (valor < 0) {
                    printf("Erro: O saldo inicial nao pode ser negativo.\n");
                } else {
                    raiz = inserir(raiz, id, nome, valor);
                }
                break;

            case 2:
                printf("Digite o ID da Conta: ");
                scanf("%d", &id);
                limparBuffer();
                {
                    No *c = buscar(raiz, id);
                    if (c != NULL) {
                        printf("Conta: %d | Titular: %s | Saldo: R$ %.2f\n", c->identificador, c->nome, c->dinheiro);
                    } else {
                        printf("Erro: Conta %d nao encontrada!\n", id);
                    }
                }
                break;

            case 3:
                printf("ID da Conta: ");
                scanf("%d", &id);
                printf("Valor do Deposito: R$ ");
                scanf("%f", &valor);
                limparBuffer();
                depositar(raiz, id, valor);
                break;

            case 4:
                printf("ID da Conta: ");
                scanf("%d", &id);
                printf("Valor do Saque: R$ ");
                scanf("%f", &valor);
                limparBuffer();
                sacar(raiz, id, valor);
                break;

            case 5:
                printf("ID da Conta Origem: ");
                scanf("%d", &id);
                printf("ID da Conta Destino: ");
                scanf("%d", &idDestino);
                printf("Valor a Transferir: R$ ");
                scanf("%f", &valor);
                limparBuffer();
                transferir(raiz, id, idDestino, valor);
                break;

            case 6:
                printf("\n=== LISTA DE CONTAS (ORDEM DE ID) ===\n");
                if (raiz == NULL) {
                    printf("Nenhuma conta cadastrada.\n");
                } else {
                    listarContas(raiz);
                }
                break;

            case 7:
                exibirEstatisticas(raiz);
                break;

            case 8:
                exibirExtremosSaldo(raiz);
                break;

            case 9:
                printf("ID da Conta a ser deletada: ");
                scanf("%d", &id);
                limparBuffer();
                if (buscar(raiz, id) != NULL) {
                    raiz = deletarConta(raiz, id);
                    printf("Conta %d removida com sucesso!\n", id);
                } else {
                    printf("Erro: Conta %d nao encontrada!\n", id);
                }
                break;

            case 0:
                printf("Encerrando o sistema e liberando memoria...\n");
                liberarArvore(raiz);
                raiz = NULL;
                printf("Sistema encerrado com sucesso.\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}