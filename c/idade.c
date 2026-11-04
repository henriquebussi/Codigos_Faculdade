#include <stdio.h>
int main(int argc, char *argv[]) {
  int ano;
  const int ano_atual = 2025;

  printf("Digite o Ano que voce nasceu: ");
  scanf("%d", &ano);

  printf("Voce nasceu aproximadamente em: %d", ano_atual - ano);
  return 0;
}
