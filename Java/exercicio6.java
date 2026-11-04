import java.util.Random;
import java.util.Arrays;

public class exercicio6 {

  public static void main(String[] args) {
    Random rand = new Random();
    int A[][] = new int[5][5];
    int B[][] = new int[5][5];
    int C[][] = new int[5][5];

    for (int i = 0; i < 5; i++) {
      for (int n = 0; n < 5; n++) {
        A[i][n] = rand.nextInt(10);
        B[i][n] = rand.nextInt(10);
      }
    }

    for (int i = 0; i < A.length; i++) {
      for (int n = 0; n < A.length; n++) {
        C[i][n] = A[i][n] + B[i][n];
      }
    }

    System.out.println("Matriz A: " + Arrays.deepToString(A));
    System.out.println("Matriz B: " + Arrays.deepToString(B));
    System.out.println("Matriz C: " + Arrays.deepToString(C));

  }
}
