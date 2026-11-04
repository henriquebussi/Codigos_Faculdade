
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5
#define TAM_STRING 50

typedef struct {
  int id_pedido;
  int tempo_chegada;
  float valor_total;
  char itens[MAX_SIZE][TAM_STRING];
} Pedido;

typedef struct {
  Pedido itens[MAX_SIZE];
  int frente;
  int fim;
  int count;
} Fila;

void iniciarFila(Fila *q) {
  q->frente = 0;
  q->fim = -1;
  q->count = 0;
  printf("Fila Iniciada com Sucesso!\n");
}

int isEmpty(Fila *q) { return q->count == 0; }

int isFull(Fila *q) { return q->count == MAX_SIZE; }

void enqueue(Fila *q, Pedido p) {
  if (isFull(q)) {
    printf("ERRO: Fila cheia. Nao foi possivel adicionar o pedido %d\n",
           p.id_pedido);
    return;
  }
  q->fim = (q->fim + 1) % MAX_SIZE;
  q->itens[q->fim] = p;
  q->count++;
  printf("Pedido %d adicionado a fila (Chegada: %d min)\n", p.id_pedido,
         p.tempo_chegada);
}

int dequeue(Fila *q) {
  if (isEmpty(q)) {
    printf("Erro: Fila Vazia!\n");
    return 0;
  }

  Pedido itemRemovido = q->itens[q->frente];
  q->frente = (q->frente + 1) % MAX_SIZE;
  q->count--;

  printf("Pedido %d removido da fila\n", itemRemovido.id_pedido);
  return 1;
}

void exibirFila(Fila *q) {
  if (isEmpty(q)) {
    printf("Fila [vazia]\n");
    return;
  }
  printf("Fila: [");
  int i;
  for (i = 0; i < q->count; i++) {
    int index = (q->frente + i) % MAX_SIZE;
    printf("Pedido %d", q->itens[index].id_pedido);
    if (i < q->count - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

void exibirProximoPedido(Fila *q) {
  if (isEmpty(q)) {
    printf("Aviso: A fila esta vazia. Nenhum pedido para exibir.\n");
    return;
  }

  Pedido proximo = q->itens[q->frente];
  printf("--- Proximo Pedido ---\n");
  printf("ID: %d\n", proximo.id_pedido);
  printf("Tempo de Chegada: %d min\n", proximo.tempo_chegada);
  printf("Valor Total: R$ %.2f\n", proximo.valor_total);
  printf("----------------------\n");
}

void processarPedido(Fila *q) {
  if (isEmpty(q)) {
    printf("Erro: Nao ha pedidos para processar. Fila vazia!\n");
    return;
  }

  Pedido pedidoProcessado = q->itens[q->frente];
  q->frente = (q->frente + 1) % MAX_SIZE;
  q->count--;

  printf("Pedido %d processado. Valor: R$ %.2f\n", pedidoProcessado.id_pedido,
         pedidoProcessado.valor_total);
}

int main() {
  Fila minhaFila;
  iniciarFila(&minhaFila);
  printf("\n");

  Pedido p1 = {.id_pedido = 101, .tempo_chegada = 5, .valor_total = 25.50};
  Pedido p2 = {.id_pedido = 102, .tempo_chegada = 8, .valor_total = 40.00};
  Pedido p3 = {.id_pedido = 103, .tempo_chegada = 12, .valor_total = 15.75};
  Pedido p4 = {.id_pedido = 104, .tempo_chegada = 15, .valor_total = 89.90};
  Pedido p5 = {.id_pedido = 105, .tempo_chegada = 22, .valor_total = 110.00};

  enqueue(&minhaFila, p1);
  enqueue(&minhaFila, p2);
  enqueue(&minhaFila, p3);
  enqueue(&minhaFila, p4);
  enqueue(&minhaFila, p5);

  printf("\n>> Exibindo a fila completa:\n");
  exibirFila(&minhaFila);

  printf("\n>> Exibindo o proximo pedido da fila:\n");
  exibirProximoPedido(&minhaFila);

  printf("\n>> Processando 2 pedidos:\n");
  processarPedido(&minhaFila);
  processarPedido(&minhaFila);

  printf("\n>> Exibindo a fila apos processar 2 pedidos:\n");
  exibirFila(&minhaFila);

  printf("\n>> Esvaziando a fila para testar erro...\n");
  processarPedido(&minhaFila);
  processarPedido(&minhaFila);
  processarPedido(&minhaFila);

  printf("\n>> Tentando processar com a fila vazia:\n");
  processarPedido(&minhaFila);

  return 0;
}
