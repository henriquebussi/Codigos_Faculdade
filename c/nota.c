#include <stdio.h>
int main(int argc, char *argv[]) {
  float p1;
  float p2;

  printf("Fale a nota da primeira prova: ");
  scanf("%f", &p1);

  printf("Fale a nota da segunda prova: ");
  scanf("%f", &p2);

  float media = (p1 + p2) / 2;

  if (media >= 7) {
    printf("Nota: %.2f, Voce foi aprovado", media);
  } else {
    printf("Nota: %.2f, Voce foi reprovado", media);
  }

  return 0;
}
