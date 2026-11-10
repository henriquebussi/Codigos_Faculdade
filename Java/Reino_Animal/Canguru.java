package Reino_Animal;

public class Canguru extends Mamifero {
    @Override
    public void locomover() {
        System.out.println("Saltando");
    }

    @Override
    public void alimentar() {
        System.out.println("Comendo vegetais");
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de Canguru");
    }
    
}
