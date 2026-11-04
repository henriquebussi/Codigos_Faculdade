import java.util.Scanner; // Importa a classe Scanner

public class Matriz { // Declara a classe pública chamada

  public static void main(String[] args) {

    Scanner entrada = new Scanner(System.in); // Cria o objeto "entrada" para ler os dados digitados.

    int[][] matriz = new int[2][3];

    for (int linha = 0; linha < matriz.length; linha++) { // Preenchimento da matriz.

      for (int coluna = 0; coluna < matriz.length; coluna++) {
        System.out.print("Digite o valor da posição [" + linha + "] [" + coluna + "]:");
        matriz[linha][coluna] = entrada.nextInt();
      }
    }

    System.out.print("\nMatriz preenchida \n");
    for (int linha = 0; linha < matriz.length; linha++) { // Preenchimento da matriz
      for (int coluna = 0; coluna < matriz.length; coluna++) {
        System.out.print(matriz[linha][coluna] + "\t");
      }
      System.out.println();
    }

    entrada.close(); // Encerra o objeto Scanner e libera o recurso utilizado.
  }
}
