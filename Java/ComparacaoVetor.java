import java.util.Arrays;

public class ComparacaoVetor {

  public static void main(String[] args) {
    int[] estoqueFilialA = { 1, 5, 6, 10, 0, 50, 24, 69 };
    int[] estoqueFilialB = new int[8];
    Arrays.fill(estoqueFilialB, 10);

    System.out.println(Arrays.toString(estoqueFilialA));
    System.out.println(Arrays.toString(estoqueFilialB));

    Boolean result = Arrays.equals(estoqueFilialA, estoqueFilialB);

    System.out.println(result);

    Arrays.sort(estoqueFilialA);
    Arrays.sort(estoqueFilialB);

    System.out.println(Arrays.toString(estoqueFilialA));
    System.out.println(Arrays.toString(estoqueFilialB));

    Boolean result2 = Arrays.equals(estoqueFilialA, estoqueFilialB);

    System.out.println(result2);

    if (estoqueFilialA.length == estoqueFilialB.length) {
      System.out.println("Os vetores são do mesmo tamanho");
    } else {
      System.out.println("Os vetores NÃO são do mesmo tamanho");
    }

    System.out.println("o Maior item da filial A é: " + estoqueFilialA[estoqueFilialA.length - 1]);
    System.out.println("o Menor item da filial A é: " + estoqueFilialA[0]);
    System.out.println("o Maior item da filial B é: " + estoqueFilialB[estoqueFilialB.length - 1]);
    System.out.println("o Menor item da filial A é: " + estoqueFilialB[0]);
  }
}
