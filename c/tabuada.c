
#include <stdio.h>
int main(int argc, char *argv[]) {
  int n;

  printf("Escreva um numero: ");
  scanf("%d", &n);

  for (int i = 0; i <= 10; i++) {
    int current = n * i;
    printf("%d x %d = %d \n", n, i, current);
  }
  return 0;
}
