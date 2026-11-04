import java.util.Scanner;

public class main {
  public static void main(String[] args) {
    try (Scanner entrada = new Scanner(System.in)) {
      int num_Eleitores;
      int voto_Branco;
      int voto_Nulo;
      int voto_Valido;

      System.out.print("Digite o numero total de eleitores: ");
      num_Eleitores = entrada.nextInt();
      System.out.print("Digite o numero total de votos brancos: ");
      voto_Branco = entrada.nextInt();
      System.out.print("Digite o numero total de votos nulos: ");
      voto_Nulo = entrada.nextInt();
      System.out.print("Digite o numero total de votos validos: ");
      voto_Valido = entrada.nextInt();

      if (voto_Branco + voto_Nulo + voto_Valido != num_Eleitores) {
        System.out.println("Numero de votos impossivel! A soma dos votos nao bate com o total de eleitores.");
        return;
      }

      double percBranco = ((double) voto_Branco / num_Eleitores) * 100;
      double percNulo = ((double) voto_Nulo / num_Eleitores) * 100;
      double percValido = ((double) voto_Valido / num_Eleitores) * 100;

      System.out.println("\n--- Resultado da Apuração ---");
      System.out.println("Numero Total de Eleitores: " + num_Eleitores);
      System.out.printf("Votos Brancos: %d (%.2f%%)\n", voto_Branco, percBranco);
      System.out.printf("Votos Nulos: %d (%.2f%%)\n", voto_Nulo, percNulo);
      System.out.printf("Votos Validos: %d (%.2f%%)\n", voto_Valido, percValido);
    }
  }
}
