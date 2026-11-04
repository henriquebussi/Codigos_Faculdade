
public class Ventilador implements ControleVentilador {

  private int velocidade;
  private String marca;
  private boolean noTeto;
  private boolean ligado;

  public Ventilador() {
    this.velocidade = 0;
    this.marca = "Generico";
    this.noTeto = false;
    this.ligado = false;
  }

  public int getVelocidade() {
    return this.velocidade;
  }

  public void setVelocidade(int velocidade) {
    this.velocidade = velocidade;
  }

  public String getMarca() {
    return this.marca;
  }

  public void setMarca(String marca) {
    this.marca = marca;
  }

  public boolean getNoTeto() {
    return this.noTeto;
  }

  public void setNoTeto(boolean noTeto) {
    this.noTeto = noTeto;
  }

  public boolean getLigado() {
    return this.ligado;
  }

  public void setLigado(boolean ligado) {
    this.ligado = ligado;
  }

  @Override
  public void ligar() {
    setLigado(true);
  }

  @Override
  public void desligar() {
    setLigado(false);
  }

  @Override
  public void aumentarVelocidade() {
    setVelocidade(this.getVelocidade() + 10);
  }

  @Override
  public void diminuirVelocidade() {
    setVelocidade(this.getVelocidade() - 10);
  }

  @Override
  public void menu() {
    System.out.println("Esta Ligado? " + this.getLigado());
    System.out.println("Esta no Teto? " + this.getNoTeto());
    System.out.println("Velocidade: " + this.getVelocidade());
  }
}
