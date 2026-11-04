import java.util.Scanner;

public class POO {
  public static float nota(int n1, int n2) {
    float mediaAritmetica = (n1 + n2) / 2.0f;
    return mediaAritmetica;
  }

  public static void infoPessoal() {
    System.out.println("Nome: Henrique Bussi dos Santos");
    System.out.println("Idade: 18");
    System.out.println("Onde Mora: Pompéia");
    System.out.println("Curso: TSI");
  }

  public static void dadosPessoais() {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Nome: ");
    String nome = scanner.nextLine();

    System.out.print("Idade: ");
    int idade = scanner.nextInt();
    scanner.nextLine();

    System.out.print("Cidade: ");
    String cidade = scanner.nextLine();

    System.out.print("Curso: ");
    String curso = scanner.nextLine();

    System.out.println("Nome: " + nome);
    System.out.println("Idade: " + idade);
    System.out.println("Cidade: " + cidade);
    System.out.println("Curso: " + curso);

    scanner.close();

  }

  public static void operar(int n1, int n2) {
    float soma = n1 + n2;
    float sub = n1 - n2;
    float mult = n1 * n2;
    float div = n1 / n2;

    System.out.println("Soma: " + soma);
    System.out.println("Subtração: " + sub);
    System.out.println("Multiplicação: " + mult);
    System.out.println("Divisão: " + div);
  }

  public static void main(String[] args) {
    System.out.println("Henrique Bussi dos Santos");

    float media = nota(10, 5);
    System.out.println("A média foi " + media);

    operar(20, 2);
    dadosPessoais();

  }
}
