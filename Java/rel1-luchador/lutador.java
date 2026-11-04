public class lutador {
  private String nome;
  private String nacionalidade;
  private int idade;
  private int peso;

  public lutador(String nome, String nacionalidade, int idade, int peso) {
    this.nome = nome;
    this.nacionalidade = nacionalidade;
    this.idade = idade;
    this.peso = peso;
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNacionalidade() {
    return nacionalidade;
  }

  public void setNacionalidade(String nacionalidade) {
    this.nacionalidade = nacionalidade;
  }

  public int getIdade() {
    return idade;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }

  public int getPeso() {
    return peso;
  }

  public void setPeso(int peso) {
    this.peso = peso;
  }

  public void apresentar(){
    System.out.println("Nome: " + nome);
    System.out.println("Nacionalidade: " + nacionalidade);
    System.out.println("Idade: " + idade);
    System.out.println("Peso: " + peso);
  }
}
