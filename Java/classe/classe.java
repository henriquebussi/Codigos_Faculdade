public class classe {
  public static void main(String[] args) {
    controle_remoto controle = new controle_remoto("Samsung", 150, "Smart TV", "AAA");
    fogao meuFogao = new fogao("Brastemp", 1200, 4, "Gás");

    System.out.println(controle.getMarca());
    System.out.println(controle.getCusto());
    System.out.println(controle.getTv());
    System.out.println(controle.getBateria());

    System.out.println(meuFogao.getMarca());
    System.out.println(meuFogao.getCusto());
    System.out.println(meuFogao.getN_Bocas());
    System.out.println(meuFogao.getTipo());

    controle.setMarca("LG");
    controle.setCusto(180);
    controle.setTv("OLED");
    controle.setBateria("AA");

    meuFogao.setMarca("Consul");
    meuFogao.setCusto(1500);
    meuFogao.setN_Bocas(5);
    meuFogao.setTipo("Indução");

    System.out.println(controle.getMarca());
    System.out.println(controle.getCusto());
    System.out.println(controle.getTv());
    System.out.println(controle.getBateria());

    System.out.println(meuFogao.getMarca());
    System.out.println(meuFogao.getCusto());
    System.out.println(meuFogao.getN_Bocas());
    System.out.println(meuFogao.getTipo());
  }
}
