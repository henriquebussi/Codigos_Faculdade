public class Biblioteca {

  private String nomeBiblioteca;
  private String cidade;
  private int tipoLivro;

  public Biblioteca(String nomeBiblioteca, String cidade, int tipoLivro) {
    this.nomeBiblioteca = nomeBiblioteca;
    this.cidade = cidade;
    this.tipoLivro = tipoLivro;
  }

  public void mostrarBiblioteca() {
    System.out.println("Nome da Biblioteca: " + nomeBiblioteca);
    System.out.println("Cidade: " + cidade);
    System.out.println("Tipos de Livros: " + tipoLivro);
  }

  public String getNomeBiblioteca() {
    return this.nomeBiblioteca;
  }

  public void setNomeBiblioteca(String nomeBiblioteca) {
    this.nomeBiblioteca = nomeBiblioteca;
  }

  public String getCidade() {
    return this.cidade;
  }

  public void setCidade(String cidade) {
    this.cidade = cidade;
  }

  public int getTipoLivro() {
    return this.tipoLivro;
  }

  public void setTipoLivro(int tipoLivro) {
    this.tipoLivro = tipoLivro;
  }
}
