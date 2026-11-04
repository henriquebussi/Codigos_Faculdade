#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
  int itens[MAX_SIZE];
  int frente;
  int fim;
  int count;
} Fila;

void iniciarFila(Fila *q) {
  q->frente = 0;
  q->fim = -1;
  q->count = 0;
  printf("Fila Iniciada com Sucesso!");
}

int isEmpty(Fila *q) { return q->count == 0; }

int isFull(Fila *q) { return q->count == MAX_SIZE; }

void enqueue(Fila *q, int item) {
  if (isFull(q)) {
    printf("ERRO: Fila cheia");
    return;
  }
  q->fim = (q->fim + 1) % MAX_SIZE;
  q->itens[q->fim] = item;
  q->count++;
  printf("%d adicionado a fila \n", item);
}

int dequeue(Fila *q) {
  if (isEmpty(q)) {
    printf("Erro: Fila Vazia!");
    return -1;
  }
  int itemRemovido = q->itens[q->frente];
  q->frente = (q->frente + 1) % MAX_SIZE;
  q->count--;
  printf("%d Removido da familia", itemRemovido);
}

int front(Fila *q) {
  if (isEmpty(q)) {
    printf("ERRO: Fila Vazia");
    return -1;
  }
  return q->itens[q->frente];
}

void exibirFila(Fila *q) {
  if (isEmpty(q)) {
    printf("Fila [vazia]");
    return;
  }
  printf("Fila: [");
  int i;
  for (i = 0; i < q->count; i++) {
    int index = (q->frente + i) % MAX_SIZE;
    printf("%d", q->itens[index]);
    if (i < q->count - 1) {
      printf(",");
    }
  }
  printf("] \n");
}
int main() {
  Fila minhaFila;
  iniciarFila(&minhaFila);

  printf("\n Testando");
  enqueue(&minhaFila, 10);
  enqueue(&minhaFila, 20);
  enqueue(&minhaFila, 30);
  exibirFila(&minhaFila);
  dequeue(&minhaFila);
  exibirFila(&minhaFila);
  enqueue(&minhaFila, 40);
  enqueue(&minhaFila, 50);
  exibirFila(&minhaFila);
  dequeue(&minhaFila);
  exibirFila(&minhaFila);
}
