public class main {

  public static void main(String[] args) {
   lutador charles = new lutador("charles", "brasileiro", 21, 80);
  lutador poatan = new lutador("alex poatan", "brasileiro", 31, 90);

  luta luta = new luta();

  luta.marcarLuta(charles, poatan);
  luta.iniciarLuta();   
  }

}
