public class fogao {
  private String Marca;
  private int Custo;
  private int N_Bocas;
  private String Tipo;

  public fogao(String Marca, int Custo, int N_Bocas, String Tipo) {
    this.Marca = Marca;
    this.Custo = Custo;
    this.N_Bocas = N_Bocas;
    this.Tipo = Tipo;
  }

  public String getMarca() {
    return Marca;
  }

  public void setMarca(String Marca) {
    this.Marca = Marca;
  }

  public int getCusto() {
    return Custo;
  }

  public void setCusto(int Custo) {
    this.Custo = Custo;
  }

  public int getN_Bocas() {
    return N_Bocas;
  }

  public void setN_Bocas(int N_Bocas) {
    this.N_Bocas = N_Bocas;
  }

  public String getTipo() {
    return Tipo;
  }

  public void setTipo(String Tipo) {
    this.Tipo = Tipo;
  }
}
