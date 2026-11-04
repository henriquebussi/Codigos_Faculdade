import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class exercicio7 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Random rand = new Random();
    int A[][] = new int[3][5];

    for (int i = 0; i < 3; i++) {
      for (int n = 0; n < 5; n++) {
        A[i][n] = rand.nextInt(10);
      }
    }

    System.out.println("Vetor A: " + Arrays.deepToString(A));
    System.out.println("Digite um Numero: ");
    int num = sc.nextInt();

    if (num % 2 == 0) {
      System.out.println(num + " é Par");
      for (int p = 0; p < 3; p++) {
        for (int l = 0; l < 5; l++) {
          if (A[p][l] % 2 == 0) {
            System.out.println(A[p][l]);
          }
        }
      }
    } else {
      System.out.println(num + " é Impar");
      for (int p = 0; p < 3; p++) {
        for (int l = 0; l < 5; l++) {
          if (A[p][l] % 2 != 0) {
            System.out.println(A[p][l]);
          }
        }
      }

    }

    sc.close();
  }
}
