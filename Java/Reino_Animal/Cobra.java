package Reino_Animal;

public class Cobra extends Reptil {
    @Override
    public void locomover() {
        System.out.println("Rastejando");
    }

    @Override
    public void alimentar() {
        System.out.println("Comendo carne");
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de Cobra");
    }
}
