public class Motorista {
  private String nome;
  private String cnh;


  // Construtor
  public Motorista(String nome, String cnh) {
    this.nome = nome;
    this.cnh = cnh;
  }

  public String getNome(){
    return nome;
  }  
  public String getCnh(){
    return cnh;
  }
}
