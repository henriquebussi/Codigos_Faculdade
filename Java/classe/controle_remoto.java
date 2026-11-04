public class controle_remoto {
  private String Marca;
  private int Custo;
  private String Tv;
  private String Bateria;

  public controle_remoto(String Marca, int Custo, String Tv, String Bateria) {
    this.Marca = Marca;
    this.Custo = Custo;
    this.Tv = Tv;
    this.Bateria = Bateria;
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

  public String getTv() {
    return Tv;
  }

  public void setTv(String Tv) {
    this.Tv = Tv;
  }

  public String getBateria() {
    return Bateria;
  }

  public void setBateria(String Bateria) {
    this.Bateria = Bateria;
  }
}
