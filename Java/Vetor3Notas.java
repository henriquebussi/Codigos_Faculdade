import java.util.Arrays;
import java.util.Random;

public class Vetor3Notas {

  public static void main(String[] args) {
    Random random = new Random();

    double[] notas = new double[6];

    for (int i = 0; i < notas.length; i++) {
      notas[i] = random.nextDouble();
    }

    System.out.println(Arrays.toString(notas));

    Arrays.sort(notas);
    System.out.println(Arrays.toString(notas));

    System.out.println("O maior numero é: " + notas[notas.length - 1]);
    System.out.println("O menor numero é: " + notas[0]);
  }
}
