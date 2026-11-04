public class Camisa {
  String marca;
  String material;
  String cor;
  boolean temEstampa;
  String tipoCamisa;
  String tipoGola;
  String estado;

  void status() {
    System.out.println("Marca: " + this.marca);
    System.out.println("Material: " + this.material);
    System.out.println("Cor: " + this.cor);
    System.out.println("Tem Estampa?: " + this.temEstampa);
    System.out.println("Tipo de Camisa: " + this.tipoCamisa);
    System.out.println("Tipo de Gola: " + this.tipoGola);
    System.out.println("Estado Atual: " + this.estado);
  }

  void vestir() {
    if ("Vestida".equalsIgnoreCase(this.estado)) {
      System.out.println("A camisa já está a ser vestida!");
    } else {
      this.estado = "Vestida";
      System.out.println("Vestiste a camisa!");
    }
  }

  void dobrar() {
    if ("Dobrada".equalsIgnoreCase(this.estado)) {
      System.out.println("A camisa já está dobrada.");
    } else if ("Vestida".equalsIgnoreCase(this.estado)) {
      System.out.println("Não podes dobrar a camisa enquanto a estiveres a vestir!");
    } else {
      this.estado = "Dobrada";
      System.out.println("A camisa foi dobrada com sucesso.");
    }
  }
}
