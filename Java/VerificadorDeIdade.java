package Java;
import java.util.Scanner;


public class VerificadorDeIdade {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite sua Idade: ");
        Integer idade = scanner.nextInt();


        if (idade >= 18) {
            System.out.println("Voce e maior de idade.");
            System.out.println("Voce pode votar");
        } else {
            System.out.println("Voce nao e maior de idade.");
            System.out.println("Voce nao pode votar!");
        }

        scanner.close();
    }


}