package Reino_Animal;

public class Cachorro extends Mamifero {
    @Override
    public void locomover() {
        System.out.println("Correndo");
    }

    @Override
    public void alimentar() {
        System.out.println("Comendo Ração");
    }

    @Override
    public void emitirSom() {
        System.out.println("Au Au");
    }
    
}
