import java.util.Arrays;
import java.util.Scanner;

public class exercicio5 {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int A[] = new int[10];
    int B[] = new int[10];

    for (int i = 0; i < A.length; i++) {
      System.out.printf("Digite o " + (i + 1) + "º numero: ");
      A[i] = sc.nextInt();
    }
    System.out.printf("Digite um Valor X: ");
    int x = sc.nextInt();

    int n = A.length;
    for (int i = 0; i < n; i++) {
      B[i] = A[i] + x;
    }

    System.out.println("Vetor A: " + Arrays.toString(A));
    System.out.println("Vetor B: " + Arrays.toString(B));
    sc.close();
  }
}

// Fazer com que os valores da lista sejam
