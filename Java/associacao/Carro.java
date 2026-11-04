public class Carro {
  private String modelo;
  private String placa;

  // Associação
  private Motorista motorista;

  public Carro(String modelo, String placa) {
    this.modelo = modelo;
    this.placa = placa;
  }

  public void atribuirMotorista(Motorista motorista) {
    this.motorista = motorista;
  }

  public void exibirDados() {
    System.out.println("Modelo: " + modelo);
    System.out.println("Placa: " + placa);

    if (motorista != null) {
      System.out.println("Motorista: " + motorista.getNome());
      System.out.println("CNH: " + motorista.getCnh());
    } else {
      System.out.println("Carro sem motorista.");
    }
  } 
}
