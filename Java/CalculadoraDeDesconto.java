package Java;
import java.util.Scanner;

public class CalculadoraDeDesconto {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Me fale o preco original do produto: ");
        Double preco_original = scanner.nextDouble();

        System.out.println("Me fale qual percentual de desconto aplicar: ");
        Double desconto_naoformatado = scanner.nextDouble();

        Double desconto = desconto_naoformatado/100;
        Double Valor_total = preco_original-(preco_original*desconto);

        String Resultado = "Valor Original: " + preco_original + "\nDesconto Aplicado: " + desconto_naoformatado + "% \nValor Total: " + Valor_total ;

        if (desconto >= 0.20){
            System.out.print("Desconto Generoso! \n");
            System.out.print(Resultado);
        } else{
            System.out.print("Desconto padrão \n");
            System.out.print(Resultado);
        }

        scanner.close();
    }
}
