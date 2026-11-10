package Reino_Animal;

public class Main {
    public static void main(String[] args) {
        Mamifero mamifero = new Mamifero();
        Reptil reptil = new Reptil();
        Peixe peixe = new Peixe();
        Ave ave = new Ave();
        Cachorro cachorro = new Cachorro();
        Canguru canguru = new Canguru();
        Cobra cobra = new Cobra();
        Tartaruga tartaruga = new Tartaruga();
        Goldfish goldfish = new Goldfish();
        Arara arara = new Arara();

        cachorro.emitirSom();
        cachorro.locomover();
        cachorro.setCorPelo("Marrom");
        cachorro.getCorPelo();
        canguru.emitirSom();
        canguru.locomover();
        canguru.setCorPelo("Marrom");
        canguru.getCorPelo();
        cobra.emitirSom();
        cobra.locomover();
        cobra.setCorEscama("Verde");
        cobra.getCorEscama();
        tartaruga.emitirSom();
        tartaruga.locomover();
        tartaruga.setCorEscama("Verde");
        tartaruga.getCorEscama();
        goldfish.emitirSom();
        goldfish.locomover();
        goldfish.setCorEscama("Dourado");
        goldfish.getCorEscama();
        goldfish.soltarBolha();
        arara.emitirSom();
        arara.locomover();
        arara.setCorPena("Azul");
        arara.getCorPena();
        arara.fazerNinho();
    }
}
