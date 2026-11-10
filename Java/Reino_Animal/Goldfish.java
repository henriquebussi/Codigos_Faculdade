package Reino_Animal;

public class Goldfish extends Peixe {
    @Override
    public void locomover() {
        System.out.println("Nadando");
    }

    @Override
    public void alimentar() {
        System.out.println("Comendo ração de peixe");
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de Goldfish");
    }
    
}
