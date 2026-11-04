#include <stdio.h>
int main(int argc, char *argv[]) {
  float c;
  printf("Fale uma temperatura em Celsius: ");
  scanf("%f", &c);

  float f = (c * 9 / 5) + 32;

  printf("%.2f C em Fahrenheit: %.2f", c, f);
  return 0;
}
