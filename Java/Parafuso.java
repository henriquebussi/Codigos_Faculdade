public class Parafuso {
  String padrao;
  String material;
  String tipoCabeca;
  float diametro;
  float comprimento;
  String tipoRosca;
  float passoRosca;
  boolean emUso;

  void status() {
    System.out.println("Padrão: " + this.padrao);
    System.out.println("Material: " + this.material);
    System.out.println("Tipo de Cabeça: " + this.tipoCabeca);
    System.out.println("Diâmetro: " + this.diametro);
    System.out.println("Comprimento: " + this.comprimento);
    System.out.println("Tipo de Rosca: " + this.tipoRosca);
    System.out.println("Passo da Rosca: " + this.passoRosca);
    System.out.println("Está em uso?: " + this.emUso);
  }

  void parafusar() {
    if (!this.emUso) {
      this.emUso = true;
      System.out.println("Parafuso apertado com sucesso!");
    } else {
      System.out.println("O parafuso já está em uso/apertado.");
    }
  }

  void desparafusar() {
    if (this.emUso) {
      this.emUso = false;
      System.out.println("Parafuso solto com sucesso!");
    } else {
      System.out.println("O parafuso já está solto.");
    }
  }
}
