#include <stdio.h>

float soma(float n1, float n2) { return n1 + n2; }

float sub(float n1, float n2) { return n1 - n2; }

float mult(float n1, float n2) { return n1 * n2; }
float div(float n1, float n2) { return n1 / n2; }
float resto(int n1, int n2) { return n1 % n2; }

int main() {

  float n1;
  float n2;

  printf("Digite um Numero: ");
  scanf("%f", &n1);
  printf("Digite um segundo Numero: ");
  scanf("%f", &n2);

  float soma = n1 + n2;
  float sub = n1 - n2;
  float mult = n1 * n2;
  float div = n1 / n2;
  //  float resto = n1 % n2;

  printf("Soma: %.2f \n", soma);
  printf("Subtração: \n %.2f", sub);
  printf("Multiplicação: \n %.2f", mult);
  printf("Divisão: \n %.2f", div);
  printf("Resto: \n %.2f", sub);
  return 0;
}
