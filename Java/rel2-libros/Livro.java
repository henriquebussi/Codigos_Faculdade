public class Livro {
  
  private String titulo;
  private String autor;
  private int anoPublicacao;

  public Livro(String titulo, String autor, int anoPublicacao) {
    this.titulo = titulo;
    this.autor = autor;
    this.anoPublicacao = anoPublicacao;
  }

  public void apresentarLivro() {
    System.out.println("Titulo: " + titulo);
    System.out.println("Autor: " + autor);
    System.out.println("Ano de Publicação: " + anoPublicacao);
  }

  public String getTitulo() {
    return this.titulo;
  }

  public void setTitulo(String titulo) {
    this.titulo = titulo;
  }

  public String getAutor() {
    return this.autor;
  }

  public void setAutor(String autor) {
    this.autor = autor;
  }

  public int getAnoPublicacao() {
    return this.anoPublicacao;
  }

  public void setAnoPublicacao(int anoPublicacao) {
    this.anoPublicacao = anoPublicacao;
  }
}
