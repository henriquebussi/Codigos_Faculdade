#include <stdio.h>
int main(int argc, char *argv[]) {
  float peso;
  float altura;

  printf("Digite seu Peso em Kg: ");
  scanf("%f", &peso);
  printf("Digite sua altura em m: ");
  scanf("%f", &altura);

  float imc = peso / (altura * altura);

  if (imc <= 18.5) {
    printf("%f - Abaixo do peso", imc);
  } else if (imc <= 24.9) {
    printf("%f - Peso Normal", imc);
  } else if (imc <= 29.9) {
    printf("%f - Sobrepeso", imc);
  } else {
    printf("%f - Obesidade", imc);
  }

  return 0;
}
