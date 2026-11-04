public class Notebook {
  public String modelo;
  private String cor;
  protected String marca;
  public int carga;
  private boolean tem_5g;

  void status() {
    System.out.println("Modelo: " + this.modelo);
    System.out.println("Cor: " + this.cor);
    System.out.println("Marca: " + this.marca);
    System.out.println("Carga Atual: " + this.carga);
    System.out.println("Tem 5g?: " + this.tem_5g);
  }

  void ligar() {
    if (this.carga > 0) {
      System.out.println("Ligando Notebook");
    } else {
      System.out.println("Não é possivel ligar");
    }
  }

}
