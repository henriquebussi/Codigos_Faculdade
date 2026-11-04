// package vetor;

import java.util.Arrays;
import java.util.Scanner;

// public class Vetor {
//
//   public static void main(String[] args) {
//     Scanner entrada = new Scanner(System.in);
//
//     int[] vetorA = new int[5];
//     int[] vetorB = new int[5];
//
//     for (int i = 0; i < vetorA.length; i++) {
//       System.out.println("Digite o numero da posicao " + i + ": ");
//       vetorA[i] = entrada.nextInt();
//       vetorB[i] = vetorA[i] * 2;
//     }
//
//     System.out.println("Vetor A original:" + Arrays.toString(vetorA));
//     System.out.println("Vetor B original:" + Arrays.toString(vetorB));
//
//     entrada.close();
//   }
// }
//

public class Vetor {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);

    int[] vetorA = new int[6];
    int maior = Integer.MIN_VALUE;
    int menor = Integer.MAX_VALUE;

    for (int i = 0; i < vetorA.length; i++) {
      System.out.println("Digite o numero da posicao " + i + ": ");
      vetorA[i] = entrada.nextInt();

      if (maior < vetorA[i]) {
        maior = vetorA[i];
      }
      if (menor > vetorA[i]) {
        menor = vetorA[i];
      }
    }

    System.out.println("Vetor A original:" + Arrays.toString(vetorA));
    System.out.println("Maior Numero: " + maior);
    System.out.println("Menor Numero: " + menor);

    entrada.close();
  }
}
