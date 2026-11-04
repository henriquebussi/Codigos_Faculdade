#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char nome[50];
  char pedido[50];
} Cliente;

typedef struct No {
  Cliente cliente;
  struct No *proximo;
} No;

typedef struct {
  No *inicio;
  No *fim;
  int tamanho;
} Fila;

void inicializarFila(Fila *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho = 0;
}

int filaVazia(Fila *fila) { return fila->inicio == NULL; }

int filaTamanho(Fila *fila) { return fila->tamanho; }

int enfileirar(Fila *fila, Cliente cliente) {
  No *novo = (No *)malloc(sizeof(No));

  if (novo == NULL) {
    return 0;
  }

  novo->cliente = cliente;
  novo->proximo = NULL;

  if (filaVazia(fila)) {
    fila->inicio = novo;
  } else {
    fila->fim->proximo = novo;
  }

  fila->fim = novo;
  fila->tamanho++;
  return 1;
}

Cliente desenfileirar(Fila *fila) {
  Cliente cliente = {0};

  if (filaVazia(fila)) {
    return cliente;
  }

  No *removido = fila->inicio;
  cliente = removido->cliente;
  fila->inicio = removido->proximo;

  if (fila->inicio == NULL) {
    fila->fim = NULL;
  }

  free(removido);
  fila->tamanho--;
  return cliente;
}

void listarFila(Fila *fila) {
  No *atual = fila->inicio;

  if (filaVazia(fila)) {
    printf("A fila está vazia.\n");
    return;
  }

  printf("\nClientes na ordem de atendimento:\n");
  while (atual != NULL) {
    printf("ID: %d | Nome: %s | Pedido: %s\n", atual->cliente.id,
           atual->cliente.nome, atual->cliente.pedido);
    atual = atual->proximo;
  }
}

int lerInteiro(const char *mensagem) {
  char linha[100];
  char caractereExtra;
  int numero;

  while (1) {
    printf("%s", mensagem);

    if (fgets(linha, sizeof(linha), stdin) == NULL) {
      return 0;
    }

    if (sscanf(linha, " %d %c", &numero, &caractereExtra) == 1) {
      return numero;
    }

    printf("Entrada inválida. Digite um número inteiro.\n");
  }
}

void lerTexto(const char *mensagem, char texto[], int tamanho) {
  while (1) {
    printf("%s", mensagem);

    if (fgets(texto, tamanho, stdin) == NULL) {
      texto[0] = '\0';
      return;
    }

    int quantidade = (int)strlen(texto);
    if (quantidade > 0 && texto[quantidade - 1] == '\n') {
      texto[quantidade - 1] = '\0';
    } else {
      int caractere;
      while ((caractere = getchar()) != '\n' && caractere != EOF) {
      }
    }

    if (texto[0] != '\0') {
      return;
    }

    printf("O campo não pode ficar vazio.\n");
  }
}

void mostrarEstatisticas(int atendidos, Fila *fila, int maiorTamanho) {
  printf("\nEstatísticas da simulação:\n");
  printf("Clientes atendidos: %d\n", atendidos);
  printf("Clientes aguardando: %d\n", filaTamanho(fila));
  printf("Maior tamanho da fila: %d\n", maiorTamanho);
}

void liberarFila(Fila *fila) {
  while (!filaVazia(fila)) {
    desenfileirar(fila);
  }
}

int main() {
  Fila fila;
  int opcao;
  int proximoId = 1;
  int totalAtendidos = 0;
  int maiorTamanho = 0;

  inicializarFila(&fila);

  do {
    printf("\n=== Restaurante: Simulador de Atendimento ===\n");
    printf("1 - Adicionar cliente\n");
    printf("2 - Atender próximo cliente\n");
    printf("3 - Listar fila\n");
    printf("4 - Ver estatísticas\n");
    printf("0 - Sair\n");
    opcao = lerInteiro("Escolha uma opção: ");

    switch (opcao) {
    case 1: {
      Cliente cliente;
      cliente.id = proximoId;

      lerTexto("Nome do cliente: ", cliente.nome, sizeof(cliente.nome));
      lerTexto("Pedido: ", cliente.pedido, sizeof(cliente.pedido));

      if (enfileirar(&fila, cliente)) {
        proximoId++;

        if (filaTamanho(&fila) > maiorTamanho) {
          maiorTamanho = filaTamanho(&fila);
        }

        printf("Cliente adicionado à fila. ID: %d\n", cliente.id);
      } else {
        printf("Não foi possível adicionar o cliente.\n");
      }
      break;
    }

    case 2:
      if (filaVazia(&fila)) {
        printf("Não há clientes aguardando atendimento.\n");
      } else {
        Cliente atendido = desenfileirar(&fila);
        printf("Atendendo cliente %d: %s - Pedido: %s\n", atendido.id,
               atendido.nome, atendido.pedido);
        totalAtendidos++;
      }
      break;

    case 3:
      listarFila(&fila);
      break;

    case 4:
      mostrarEstatisticas(totalAtendidos, &fila, maiorTamanho);
      break;

    case 0:
      printf("\nEncerrando a simulação.\n");
      mostrarEstatisticas(totalAtendidos, &fila, maiorTamanho);
      break;

    default:
      printf("Opção inválida. Escolha uma opção do menu.\n");
    }
  } while (opcao != 0);

  liberarFila(&fila);
  return 0;
}
