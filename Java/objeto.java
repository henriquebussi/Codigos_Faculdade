
public class objeto {

  public static void main(String[] args) {
    Notebook a1 = new Notebook();
    Parafuso b2 = new Parafuso();
    Carregador d2 = new Carregador();
    Camisa c1 = new Camisa();

    a1.modelo = "Aspire 5";
    a1.cor = "prata";
    a1.marca = "Acer";
    a1.carga = 85;
    a1.tem_5g = true;

    a1.status();
    a1.ligar();

    System.out.println("\n");
    b2.padrao = "Americano";
    b2.material = "Aluminio";
    b2.tipoCabeca = "Sextavada";
    b2.diametro = 10;
    b2.comprimento = 15;
    b2.tipoRosca = "Retangular";
    b2.passoRosca = 2;
    b2.emUso = true;

    b2.status();
    b2.parafusar();
    b2.desparafusar();

    System.out.println("\n");
    d2.marca = "Acer";
    d2.tipoEntrada = "Padrão 3 pinos";
    d2.tipoSaida = "Padrão Acer";
    d2.capacidadeCargaVolts = 19.0f;
    d2.estado = "DESCONECTADO";
    d2.status();
    d2.carregar();
    d2.carregar();

    c1.marca = "Nike";
    c1.material = "Algodão";
    c1.cor = "Preta";
    c1.temEstampa = true;
    c1.tipoCamisa = "Camiseta";
    c1.tipoGola = "Careca";
    c1.estado = "No cabide";
    c1.status();
    c1.vestir();
    c1.dobrar();
  }
}
