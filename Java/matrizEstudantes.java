import java.util.Arrays;

public class matrizEstudantes {
  public static void main(String[] args) {
    double matrizEstudantes[][] = {
        { 10, 8, 7, 3 },
        { 3, 2, 4, 9 },
        { 7, 8, 9, 10 }
    };

    System.out.println(Arrays.deepToString(matrizEstudantes));

    for (int i = 0; i < matrizEstudantes.length; i++) {
      Arrays.sort(matrizEstudantes[i]);
    }

    System.out.println(Arrays.deepToString(matrizEstudantes));

    System.out.println(matrizEstudantes);

    for (int i = 0; i < matrizEstudantes.length; i++) {
      double[] notas = matrizEstudantes[i];

      double menor = notas[0];
      double maior = notas[0];
      double soma = 0;

      for (double nota : notas) {
        if (nota < menor) {
          menor = nota;
        }
        if (nota > maior) {
          maior = nota;
        }
        soma += nota;
      }

      double media = soma / notas.length;

      System.out.printf("Estudante" + (i + 1) + "\n");
      System.out.printf("  - Menor nota: " + menor + "\n");
      System.out.printf("  - Maior nota: " + maior + "\n");
      System.out.printf("  - Média: " + media + "\n");
    }
  }
}
