public class Associacao {
  
  public static void main(String[] args) {
    Motorista motorista = new Motorista("Carlos", "1234567");

    Carro c1 = new Carro("Toyota Corolla", "ABC-1234");

    c1.atribuirMotorista(motorista);
  }
}
