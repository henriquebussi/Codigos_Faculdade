public class luta {

    private lutador desafiante;
    private lutador desafiado;

    public lutador getDesafiante() {
        return desafiante;
    }

    public void setDesafiante(lutador desafiante) {
        this.desafiante = desafiante;
    }

    public lutador getDesafiado() {
        return desafiado;
    }

    public void setDesafiado(lutador desafiado) {
        this.desafiado = desafiado;
    }

    public void marcarLuta(lutador desafiante, lutador desafiado) {
        this.desafiante = desafiante;
        this.desafiado = desafiado;
    }

  public void iniciarLuta() {
    if (this.desafiante != null && this.desafiado != null) {
        System.out.println("Luta iniciada!");
        
        System.out.println("--- Desafiante ---");
        this.desafiante.apresentar();
        
        System.out.println("--- Desafiado ---");
        this.desafiado.apresentar();
    } else {
        System.out.println("Não é possível iniciar a luta. Defina os dois lutadores.");
    }
}
}


