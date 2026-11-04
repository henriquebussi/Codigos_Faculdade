public class Carregador {
  String marca;
  String tipoEntrada;
  String tipoSaida;
  float capacidadeCargaVolts;
  String estado;

  void status() {
    System.out.println("Marca: " + this.marca);
    System.out.println("Tipo de Entrada: " + this.tipoEntrada);
    System.out.println("Tipo de Saída: " + this.tipoSaida);
    System.out.println("Voltagem (V): " + this.capacidadeCargaVolts);
    System.out.println("Estado Atual: " + this.estado);
  }

  void carregar() {
    if (this.estado == "DESCONECTADO") {
      this.estado = "EM USO";
      System.out.println("Carregador ligado! A carregar o dispositivo...");
    } else if (this.estado == "EM_USO") {
      System.out.println("O carregador já está em uso.");
    }
  }
}
